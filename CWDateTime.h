#ifndef CWDateTimeCf_h
#define CWDateTimeCf_h

#include <Arduino.h>

#include <ezTime.h>
#include <WiFi.h>

class CWDateTime
{
private:
  Timezone myTZ;

public:
  void begin();
  void setTimezone(const char *timeZone);
  String getTimezone();
  void update();
  String getFormattedTime();

  char *getHour(const char *format);
  char *getMinute(const char *format);
  int getHour();
  int getMinute();
  int getSecond();
};
#endif
