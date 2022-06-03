#ifndef WiFiConnect_h
#define WiFiConnect_h

#include <WiFiManager.h>
#include <EEPROM.h>

WiFiManager wifiManager;

struct WiFiConnect 
{
    std::vector<const char *> _menu = {"wifi","exit"};
    char timezone[4]="1";
    bool shouldSaveConfig = false;

    void saveTimezone(const char* value) {
      int tz = atoi(value);
      byte is_neg = (tz < 0 ? 1 : 0);
      
      if (tz < -12 || tz > 14) {
        tz = 0;
        is_neg = 0;
      }
      
      Serial.print("Save Timezone: ");
      Serial.println(tz);

      EEPROM.write(7, abs(tz));
      delay(10);
      EEPROM.write(8, is_neg);
      delay(10);
      if (EEPROM.commit()) {
        Serial.print("EEPROM saved.");
      } else {
        Serial.print("Error saving EEPROM.");
      }
      shouldSaveConfig = false;
    }

    signed int loadTimezone() {
      int tz = EEPROM.read(7);
      int is_neg = EEPROM.read(8);

      Serial.print("Current Timezone: ");
      Serial.println(tz * (is_neg == 1 ? -1 : 1));

      if (tz < -12 || tz > 14) {
        tz = 0;
        is_neg = 0;
      }

      return tz * (is_neg == 1 ? -1 : 1);
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
