#include "lcd.h"
#include "temp.h"
#include "pump.h"
#include "config.h"

void setup() {
    lcd_init();
    pump_init();
}

void loop() {
    set_pump(RESV_PUMP, HIGH);
    set_pump(RBOX_PUMP, LOW);
    lcd_pump_status("Irrigating..");
    lcd_temp_status(read_temp());
    delay(800);

    set_pump(RESV_PUMP, LOW);
    set_pump(RBOX_PUMP, HIGH);
    lcd_pump_status("Raining...  ");
    lcd_temp_status(read_temp());
    delay(800);
}
