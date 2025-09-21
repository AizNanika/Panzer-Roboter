//*******************************************************************
#include "EmbSysLib.h"
#include "Motor.h"
#include "Roboter.h"
#include "IRoboter.h"
#include "DigitalAdapter.h"
#include "AnalogOutAdapter.h"
#include "Module/Rtos/Rtos.h"
#include "ReportHandler.h"
#include "config.h"

#define W 0x0077
#define A 0x0061
#define S 0x0073
#define D 0x0064
#define OBEN 0x0141
#define UNTEN 0x0142
#define RECHTS 0x0143
#define LINKS 0x0144
#define STOP 0x0020

int currentPwm = 500; //Standard Geschwinidgkeit bei 500

int main(void)
{

    DigitalAdapter m1_cw_adapter(m1_cw);
    DigitalAdapter m1_ccw_adapter(m1_ccw);
    AnalogOutAdapter m1_pwm_adapter(m1_pwm);

    DigitalAdapter m4_cw_adapter(m4_cw);
    DigitalAdapter m4_ccw_adapter(m4_ccw);
    AnalogOutAdapter m4_pwm_adapter(m4_pwm);

    Motor m1(m1_cw_adapter, m1_ccw_adapter, m1_pwm_adapter);
    Motor m4(m4_cw_adapter, m4_ccw_adapter, m4_pwm_adapter);

    PanzerRoboter robot(m1, m4, currentPwm);


  disp.printf(0,0,"Robot is ready");


  while(1)
  {

      WORD c;

      if( c = terminal.get() ){

              switch (c){
                case W:
                       robot.moveForwards();
                    break;
                case S:
                        robot.moveBackwards();
                    break;
                case D:
                    robot.moveRight();
                    break;
                case A:
                    robot.moveLeft();
                    break;
                case STOP:
                    robot.stop();
                    break;
                case OBEN:
                    currentPwm += 100;
                    robot.setSpeedALL(currentPwm);
                    disp.printf(1,0,"%d", currentPwm);
                    break;
                case UNTEN:
                    currentPwm -= 100;
                    robot.setSpeedALL(currentPwm);
                    disp.printf(1,0,"%d", currentPwm);
                    break;
                default:
                    robot.stop();
                    break;
              }

        terminal.printf("0x%04x ",c);
      }

     switch( btnB.getEvent())
            {
              case Digital::ACTIVATED:
                  led1.set(1);
                  robot.stop();
                  break;
              case Digital::RELEASED:
                  led1.set(0);
                  break;
              default:
                    ;
            }


        switch( btnA.getEvent())
            {
              case Digital::ACTIVATED:
                  led0.set(1);
                  robot.stop();

                  break;
              case Digital::RELEASED:
                  led0.set(0);
                  break;
            }


  }
}
//EOF
