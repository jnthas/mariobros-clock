#ifndef DateTimeCf_h
#define DateTimeCf_h

#include <NTPClient.h>
#include <TimeLib.h>
#include <WiFi.h>

class DateTime
{
  private:    
    WiFiUDP udp;
    NTPClient* ntp;

  public:
    void begin();
    void update();
    String getFormattedTime();

    char* getHour(const char *format);
    char* getMinute(const char *format);
    
    int getHour();
    int getMinute();
    int getSecond();
};
#endif
