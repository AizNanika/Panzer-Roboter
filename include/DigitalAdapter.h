#ifndef DIGITALADAPTER_H
#define DIGITALADAPTER_H

#include "IPin.h"
#include "EmbSysLib.h"

class DigitalAdapter : public IPin {
private:
    EmbSysLib::Dev::Digital &pin;
public:
    DigitalAdapter(EmbSysLib::Dev::Digital &p) : pin(p) {}
    void set(int value) override {
        pin.set(value);
    }
};


#endif
