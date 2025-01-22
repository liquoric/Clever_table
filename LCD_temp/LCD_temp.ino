#incleude <Wire.h>
#incleude <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD (0x20, 16, 2);

void setup(){
  LCD.init();
  LCD.backlight();
}

void loop(){
  LCD.setCursor(1,0);
  LCD.print("It works!");
}
