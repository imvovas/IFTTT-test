#define BLYNK_PRINT Serial


#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "749c450fca1231bfae14d037928425c2";

#define W5100_CS  10
#define SDCARD_CS 4

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  digitalWrite(9, pinValue);
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

  Blynk.begin(auth);
}

void loop()
{
  Blynk.run();
}

