#include "lcd.h"
#include "temp.h"
#include "pump.h"
#include "matrix.h"
#include "config.h"

void setup() {
    lcd_init();
    pump_init();
    matrix_init();
    matrix_all_on();
}

void loop() {
    struct lcd_status_t status;
    status.temp = read_temp();

    set_pump(RESV_PUMP, HIGH);
    set_pump(RBOX_PUMP, LOW);
    status.message = "Irrigating...";
    lcd_update_status(status);
    delay(800);

    set_pump(RESV_PUMP, LOW);
    set_pump(RBOX_PUMP, HIGH);
    status.message = "Raining...";
    lcd_update_status(status);
    delay(800);
}
