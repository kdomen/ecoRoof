/**
 * temp.cpp
 *
 * DS18B20 temperature sensor.
 */

#include "temp.h"
#include "config.h"
#include <OneWire.h>

OneWire ds(TEMP_SIGNAL);

/**
 * Returns the temperature in degrees fahrenheit.
 * A value of -1000 indicates that an error has occured.
 */
float read_temp() {
    byte data[12], addr[8];

    if (!ds.search(addr)) {
            // No more sensors on chain, reset search
            ds.reset_search();
            return -1000;
    }

    if (OneWire::crc8( addr, 7) != addr[7]) {
            // CRC is not valid
            return -1000;
    }

    if (addr[0] != 0x10 && addr[0] != 0x28) {
            // device ID is not recognized
            return -1000;
    }

    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1); // start conversion, with parasite power on at the end

    byte present = ds.reset();
    ds.select(addr);
    ds.write(0xBE); // read from scratchpad

    for (int i = 0; i < 9; i++) {
        data[i] = ds.read();
    }

    ds.reset_search();

    byte MSB = data[1];
    byte LSB = data[0];

    float temp_read = ((MSB << 8) | LSB);
    float temp_sum    = temp_read / 16;

    return 1.8*temp_sum + 32;
}
