
#include "DateTime.h"

DateTime::DateTime() {
  this->ntp = new NTPClient(udp, -3 * 3600);
  setTime(ntp->getEpochTime());
}

void DateTime::begin()
{
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
