uint8_t displayBright = 32;
uint8_t brightnessChangeSteps = 4;

int threshold = 40; //This is a decent value from testing
bool touch8detected = false;
bool touch9detected = false;

MatrixPanel_I2S_DMA *matrixDisplay;

// We will change the brightness in the loop rather than the interupts
void gotTouch8() {
  touch8detected = true;
}

void gotTouch9() {
  touch9detected = true;
}

void processTouch() {
  if (touch8detected) {
    //Bright up
    touch8detected = false;
    //Serial.println("Touch 8 detected");
    if (displayBright > 255 - brightnessChangeSteps) {
      displayBright = 255;
    } else {
      displayBright = displayBright + brightnessChangeSteps;
    }
    matrixDisplay->setBrightness8(displayBright);
  }
  if (touch9detected) {
    //Bright down
    touch9detected = false;
    //Serial.println("Touch 9 detected");

    if (displayBright <= brightnessChangeSteps) {
      displayBright = brightnessChangeSteps;
      //1 seems to be off, so no point being that low
    } else {
      displayBright = displayBright - brightnessChangeSteps;
    }
    matrixDisplay->setBrightness8(displayBright);
  }
}
