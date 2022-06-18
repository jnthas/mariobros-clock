#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include "Clockface.h"
#include "WiFiConnect.h"
#include "CWDateTime.h"

MatrixPanel_I2S_DMA *dma_display = nullptr;
WiFiConnect wifi;
CWDateTime cwDateTime;
Clockface *clockface;

uint16_t myBLACK = dma_display->color565(0, 0, 0);
uint16_t myWHITE = dma_display->color565(255, 255, 255);
uint16_t myBLUE = dma_display->color565(0, 0, 255);

byte displayBright = 32;

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

void setup() {

  Serial.begin(115200);

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
  cwDateTime.begin();

  clockface->setup(&cwDateTime);
}

void loop() {
  clockface->update();

}
