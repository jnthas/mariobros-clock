#ifndef MarioClockface_h
#define MarioClockface_h

#include "Super_Mario_Bros__24pt7b.h"

#include <Adafruit_GFX.h>
#include "Tile.h"
#include "Locator.h"
#include "Game.h"
#include "Object.h"
// Commons
#include "IClockface.h"
#include "DateTime.h"

#include "assets.h"
#include "mario.h"
#include "block.h"

class Clockface: public IClockface {
  private:
    Adafruit_GFX* _display;
    DateTime* _dateTime;
    void updateTime();

  public:
    Clockface(Adafruit_GFX* display);
    void setup(DateTime *dateTime);
    void update();
};

#endif
