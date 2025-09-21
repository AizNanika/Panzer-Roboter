#ifndef IANALOGOUT_H
#define IANALOGOUT_H

class IAnalogOut {
public:
    virtual void set(int value) = 0;
    virtual ~IAnalogOut() = default;

};

#endif
