#ifndef WiFiConnect_h
#define WiFiConnect_h

#include <WiFiManager.h>

WiFiManager wifiManager;

struct WiFiConnect 
{
    std::vector<const char *> _menu = {"wifi","exit"};
    
    void connect() 
    {
      bool resp;
      wifiManager.setTitle("Clockwise Wifi Setup");
      wifiManager.setMenu(_menu);
      resp = wifiManager.autoConnect("Clockwise-Wifi", "12345678");
      
      if (!resp) {
        Serial.println("Failed to connect");
        ESP.restart();
      } 
      else {
        Serial.println("connected!");
      }
    }

    boolean isConnected() 
    {
        return WiFi.status() == WL_CONNECTED;
    }
};

#endif
