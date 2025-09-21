#ifndef IPIN_H
#define IPIN_H

class IPin {
public:
    virtual void set(int value) = 0;
    virtual ~IPin() = default;
};

#endif
