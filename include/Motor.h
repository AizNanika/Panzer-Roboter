#ifndef MOTOR_H
#define MOTOR_H

#define MIN_PWM 0
#define MAX_PWM 800

#include "IPin.h"
#include "IAnalogOut.h"
#include "MathUtils.h"
#include "IMotor.h"

class Motor : public IMotor{

private:
    IPin &cw;
    IPin &ccw;
    IAnalogOut &pwm;
    bool running;
    bool clockwise;
    int currentPwm;


    void updateDirectionPins() {
        cw.set(clockwise ? 1 : 0);
        ccw.set(clockwise ? 0 : 1);
    }

    void updatePwmOutput() {
        pwm.set(running ? currentPwm : 0);
    }


public:
    explicit Motor(IPin &_cw, IPin &_ccw, IAnalogOut &_pwm)
        : cw(_cw), ccw(_ccw), pwm(_pwm),
          running(false), clockwise(false), currentPwm(0) {}

    void run(int pwmValue) {
        currentPwm = clamp(pwmValue, MIN_PWM, MAX_PWM);
        running = true;
        updateDirectionPins();
        updatePwmOutput();
    }

    void run(){
        running = true;
        updateDirectionPins();
        updatePwmOutput();
    }

    void setPwm(int pwmValue) {
        currentPwm = clamp(pwmValue, MIN_PWM, MAX_PWM);
        if (running) {
            updatePwmOutput();
        }
    }

    void stop() {
        running = false;
        updatePwmOutput();
    }

    void toggle() {
        if (running)
            stop();
        else
            run(currentPwm);
    }

    void setDirection(bool clockwiseDirection) {
        clockwise = clockwiseDirection;
        updateDirectionPins();
    }

    bool isRunning() const {
        return running;
    }

    int getPwm() const {
        return currentPwm;
    }

    bool getDirection() const {
        return clockwise;
    }
};

#endif
