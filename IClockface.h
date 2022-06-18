#ifndef IClockface_h
#define IClockface_h

#include "CWDateTime.h"

class IClockface {

    virtual void setup(CWDateTime *dateTime) = 0;
    virtual void update() = 0;

};

#endif
