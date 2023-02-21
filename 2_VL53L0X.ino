#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_VL53L0X.h>

Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);
  
  if (!lox1.begin(0x29) || !lox2.begin(0x2A)) {
    Serial.println(F("Failed to detect and initialize sensor 1 or 2"));
    while (1) {}
  }
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure1;
  lox1.rangingTest(&measure1, false);

  VL53L0X_RangingMeasurementData_t measure2;
  lox2.rangingTest(&measure2, false);
  
  if (measure1.RangeStatus != 4 || measure2.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor 1: "); Serial.print(measure1.RangeMilliMeter); Serial.print("  ");
    Serial.print("Sensor 2: "); Serial.println(measure2.RangeMilliMeter);
  }

  delay(100);
}
