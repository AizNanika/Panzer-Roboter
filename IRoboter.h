#ifndef ROBOTER_H
#define ROBOTER_H

class IRoboter_ {
public:
    virtual ~IRoboter_() = default;

    virtual void moveForwards() = 0;
    virtual void moveBackwards() = 0;
    virtual void moveRight() = 0;
    virtual void moveLeft() = 0;
    virtual void stop() = 0;

};

#endif
