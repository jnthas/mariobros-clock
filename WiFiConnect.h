#ifndef WiFiConnect_h
#define WiFiConnect_h

#include <WiFiManager.h>
#include <EEPROM.h>
#define EEPROM_TZ_ADDR 7


WiFiManager wifiManager;

struct WiFiConnect 
{
    std::vector<const char *> _menu = {"wifi","exit"};
    char timezone[4]="0";
    bool shouldSaveConfig = false;

    void saveTimezone(const char* value) {
      signed char tz = atoi(value);
      if (tz < -12 || tz > 14) {
        tz = 0;
      }
      
      Serial.print("Save Timezone: ");
      Serial.println(tz);

      EEPROM.write(EEPROM_TZ_ADDR, tz);
      delay(10);
      if (!EEPROM.commit()) {
        Serial.print("Error saving EEPROM.");
      }
      shouldSaveConfig = false;
    }

    signed char loadTimezone() {
      signed char tz = EEPROM.read(EEPROM_TZ_ADDR);
      if (tz < -12 || tz > 14) {
        tz = 0;
      }
      return tz;
    }
    
    void connect() 
    {
      bool resp; 
      //wifiManager.resetSettings(); 
      wifiManager.setSaveConfigCallback([&](){ shouldSaveConfig = true; });
      
      sprintf(timezone, "%d", loadTimezone());
      WiFiManagerParameter timezoneParam("tz", "Inform your timezone (GMT)", timezone, 3);

      wifiManager.setTitle("Clockwise Wifi Setup");
      wifiManager.setMenu(_menu);
      wifiManager.addParameter(&timezoneParam);
      
      resp = wifiManager.autoConnect("Clockwise-Wifi", "12345678");
      
      if (!resp) {
        Serial.println("Failed to connect");
        delay(3000);
        ESP.restart();
      } 
      else {
        Serial.println("connected!");
        if (shouldSaveConfig) {
          saveTimezone(timezoneParam.getValue());
        }
      }
    }

    boolean isConnected() 
    {
        return WiFi.status() == WL_CONNECTED;
    }
};

#endif
