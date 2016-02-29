#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    lcd.begin(16, 4);
    lcd.print("hello, world!");
}

void loop() {
}

