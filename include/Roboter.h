#include "Motor.h"
#include "IRoboter.h"


class PanzerRoboter : public IRoboter_ {
private:

    IMotor &leftMotor;
    IMotor &rightMotor;

    void runAll(){
        leftMotor.run();
        rightMotor.run();
    }

    void stopAll(){
        leftMotor.stop();
        rightMotor.stop();
    }

    void setAllDirections(bool clockwise){
        leftMotor.setDirection(clockwise);
        rightMotor.setDirection(clockwise);
    }

public:

    explicit PanzerRoboter(IMotor &m1, IMotor &m2, int startSpeed) :
        leftMotor(m1), rightMotor(m2){

            setSpeedALL(startSpeed);

            }
    explicit PanzerRoboter(Motor &m1, Motor &m2) :
        leftMotor(m1), rightMotor(m2){

            setSpeedALL(0);

            }

    void moveForwards(){
        setAllDirections(false);
        runAll();

    }
    void moveBackwards(){
        setAllDirections(true);
        runAll();
    }
    void moveRight(){
        rightMotor.setDirection(true);
        leftMotor.setDirection(false);
        runAll();
    }
    void moveLeft(){
        rightMotor.setDirection(false);
        leftMotor.setDirection(true);
        runAll();
    }
    void stop(){
        stopAll();

    }
    void setSpeedALL(int pwmValue){
        leftMotor.setPwm(pwmValue);
        rightMotor.setPwm(pwmValue);
    }
};
