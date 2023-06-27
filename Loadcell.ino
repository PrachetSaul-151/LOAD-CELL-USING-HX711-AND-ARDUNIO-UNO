#include "HX711.h"

#define DOUT_PIN  2
#define CLK_PIN   3

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.set_scale(2000.0); // Set calibration factor if required 2000
  scale.tare(); // Reset the scale to 0
}

void loop() {
  if (scale.is_ready()) {
    long reading = scale.get_units(); // Get the weight reading
    Serial.print("Weight: ");
    Serial.print(reading);
    Serial.println(" units");
  }
  
  delay(1000);
}
