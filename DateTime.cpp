
#include "DateTime.h"
#include <EEPROM.h>

void DateTime::begin()
{
  int tz = EEPROM.read(7);
  int is_neg = EEPROM.read(8);  
  tz = tz * (is_neg == 1 ? -1 : 1);
  
  if (tz < -12 || tz > 14) {
    tz = 0;
    is_neg = 0;
  }

  Serial.print("Current Timezone: ");
  Serial.println(tz);

  this->ntp = new NTPClient(udp, tz * 3600);
  setTime(ntp->getEpochTime());
  
  ntp->begin();
  ntp->forceUpdate();
}

void DateTime::update()
{
  ntp->update();
}

String DateTime::getFormattedTime()
{
  return ntp->getFormattedTime();
}

char* DateTime::getHour(const char *format)
{
  static char buffer[3] = {'\0'};
  snprintf(buffer, sizeof(buffer), format, ntp->getHours());
  return buffer;
}

char* DateTime::getMinute(const char *format)
{
  static char buffer[3] = {'\0'};
  snprintf(buffer, sizeof(buffer), format, ntp->getMinutes());
  return buffer;
}

int DateTime::getHour() {
  return ntp->getHours();
}

int DateTime::getMinute() {
  return ntp->getMinutes();
}

int DateTime::getSecond() {
  return ntp->getSeconds();
}
