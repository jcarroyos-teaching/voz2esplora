#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>

void setup() {
  Serial.begin(9600);
  EsploraTFT.begin();
  EsploraTFT.background(255, 0, 0);
}


void loop() {
  int micValue = Esplora.readMicrophone();

  Serial.println(micValue);
  int screenWidth = EsploraTFT.width();
  int screenHeight = EsploraTFT.height();

  int centerX = screenWidth / 2;
  int centerY = screenHeight / 2;

  int diameter = map(micValue, 0, 1023, 0, screenWidth);

  EsploraTFT.background(255, 0, 0);

  EsploraTFT.stroke(255, 255, 255); // Color blanco
  for (int i = 0; i < 4; i++) {
    EsploraTFT.circle(centerX, centerY, (diameter / 2) - i);
  }

  delay(30);
}
