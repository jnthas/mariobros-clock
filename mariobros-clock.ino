#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include "Clockface.h"
#include "WiFiConnect.h"
#include "DateTime.h"

#define EEPROM_SIZE 512

MatrixPanel_I2S_DMA *dma_display = nullptr;
WiFiConnect wifi;
DateTime dateTime;
Clockface *clockface;

uint16_t myBLACK = dma_display->color565(0, 0, 0);
uint16_t myWHITE = dma_display->color565(255, 255, 255);
uint16_t myBLUE = dma_display->color565(0, 0, 255);

const int touchThreshold = 40;
byte displayBright = 32;
bool touch8detected = false;
bool touch9detected = false;
unsigned long touchLastMillis = 0;

void displaySetup() {
  HUB75_I2S_CFG mxconfig(
    64,   // module width
    64,   // module height
    1    // Chain length
  );

  mxconfig.gpio.e = 18;
  mxconfig.clkphase = false;

  // Display Setup
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(displayBright);
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);
}

void gotTouch8(){
 touch8detected = (millis() - touchLastMillis > 1000);
}

void gotTouch9(){
 touch9detected = (millis() - touchLastMillis > 1000);
}

void changeDisplayBright() {
  displayBright += 32;
  dma_display->setBrightness8(displayBright);
  Serial.print("Bright set to ");
  Serial.println(displayBright);
}

void setup() {

  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);

  displaySetup();

  clockface = new Clockface(dma_display);

  dma_display->setTextSize(1);
  dma_display->setTextColor(myWHITE);
  dma_display->setCursor(5, 0);
  dma_display->println("CLOCKWISE");
  dma_display->setTextColor(myBLUE);
  dma_display->setCursor(0, 32);
  dma_display->print("connecting...");
  
  wifi.connect();
  dateTime.begin();

  clockface->setup(&dateTime);

  touchAttachInterrupt(T8, gotTouch8, touchThreshold);
  touchAttachInterrupt(T9, gotTouch9, touchThreshold);
}

void loop() {
  clockface->update();

  if (touch8detected) {
    touch8detected = false;
    changeDisplayBright();
    touchLastMillis = millis();
  } else if (touch9detected) {
    touch9detected = false;
    clockface->externalEvent(0);
    touchLastMillis = millis();
  }

}
