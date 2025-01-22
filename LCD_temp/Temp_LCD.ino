// C++ code
//
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


LiquidCrystal_I2C LCD(0x27,16,2);


void setup() {
   LCD.init(); // инициализация LCD дисплея
   LCD.backlight(); // включение подсветки дисплея
   LCD.setCursor(0, 0);
   sensors.begin();
   
     // печатаем сообщение на второй строке
}

void loop() {
  sensors.requestTemperatures(); 
  int temp = sensors.getTempCByIndex(0);
  LCD.setCursor(0, 0);
  LCD.print("Temperatura Ce:");
  LCD.setCursor(0, 1);
  LCD.print(temp);
}

 
