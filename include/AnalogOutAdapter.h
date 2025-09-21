#ifndef ANALOGOUTADAPTER_H
#define ANALOGOUTADAPTER_H

#include "IAnalogOut.h"
#include "EmbSysLib.h"

class AnalogOutAdapter : public IAnalogOut {
private:
    EmbSysLib::Dev::AnalogOut &out;
public:
    AnalogOutAdapter(EmbSysLib::Dev::AnalogOut &o) : out(o) {}
    void set(int value) override {
        out.set(value);
    }
};

#endif
