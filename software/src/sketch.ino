#include "config.h"
#include "lcd.h"
#include "pump.h"

void setup() {
    lcd_init();
    pump_init();
}

void loop() {
    set_pump(RESV_PUMP, HIGH);
    set_pump(RBOX_PUMP, LOW);
    lcd_pump_status("Irrigating...");
    delay(800);

    set_pump(RESV_PUMP, LOW);
    set_pump(RBOX_PUMP, HIGH);
    lcd_pump_status("Raining...   ");
    delay(800);
}
