#ifndef IMOTOR_H
#define IMOTOR_H

class IMotor {
public:
    virtual ~IMotor() = default;

    virtual void setPwm(int pwm) = 0;
    virtual void setDirection(bool clockwise) = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
};

#endif
