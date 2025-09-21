#include "Motor.h"

Motor::Motor(int motorID) : clock_wise(true), pwm(0), motorID(motorID) {
    if (motorID != 1 && motorID != 4) {
        throw std::invalid_argument("'motorID' muss 1 oder 4 sein");
    }
    enable.set(1); // H-Brücke aktivieren
}

void Motor::setDirection(bool direction) {
    clock_wise = direction;
    update();
}

void Motor::setPWM(int value) {
    pwm = value;
    update();
}

void Motor::stop() {
    pwm = 0;
    update();
}

void Motor::update() {
    if (motorID == 1) {
        m1_cw.set(clock_wise ? 1 : 0);
        m1_ccw.set(clock_wise ? 0 : 1);
        m1_pwm.set(pwm);
    } else if (motorID == 4) {
        m4_cw.set(clock_wise ? 1 : 0);
        m4_ccw.set(clock_wise ? 0 : 1);
        m4_pwm.set(pwm);
    }
}
