### To do:
- Custom namespace: DONE
- Put button vars into Light_sensing_dimmer class or it's own: DONE
- Make functions to simplify initialization in setup() and main(): DONE
- Update doxy comments for constructor and class: DONE
- Integrate with freeRTOS to allow multithreading. mode -> dimmer_1.mode. delay() -> ?.
- Optimizations. Alignment
- Put setupDimmer() into constructor instead

# Light Sensing Dimmer Library

## Overview
The **Light Sensing Dimmer** is an Arduino-compatible library designed for the **ESP32** microcontroller. It automatically adjusts the brightness of an LED based on ambient light levels. It follows the **inverse square law** to provide a natural perception of brightness changes and includes **anti-flickering** mechanisms to cancel out fluctuations at **50-60 Hz**. Designed for **ease of use**, this library allows seamless integration into projects requiring automatic LED dimming.

## Features
- **Adaptive brightness**: Dynamically adjusts LED brightness based on ambient light.
- **Inverse square law mapping**: Ensures smooth and natural transitions in brightness.
- **Anti-flickering design**: Reduces flickering effects caused by power fluctuations at 50-60 Hz.
- **Configurable parameters**: Allows users to customize sampling rate, delay time, and mapping curve.
- **Serial output for debugging**: Provides real-time sensor readings and LED values.
- **Designed for ESP32**: Optimized for the ESP32 platform.
- **Tested on ESP32-C3 Super Mini**: Verified to work on this specific board.
- **Built using PlatformIO**: Developed and tested with the PlatformIO environment.

## Installation
To use the Light Sensing Dimmer library, include the header file in your Arduino project:

```cpp
#include <Light_sensing_dimmer.h>
```

## Usage

### Initialization
Create a `Light_sensing_dimmer` object by specifying the following parameters:

```cpp
Light_sensing_dimmer dimmer_1(A4, 3, 100, 20, 2500, 2);
```

- `SENSOR_PIN` - Analog pin for light sensor input.
- `LED_PIN` - Digital pin for dimmable LED output.
- `POLLING_RATE` - Interval in milliseconds for LED updates.
- `AVERAGES` - Number of sensor readings to average.
- `PART_DELAY` - Delay in microseconds between sensor readings.
- `K` - Exponential scaling factor for brightness adjustment.

### Example Code
```cpp
void setup()
{
  ledcSetup(0, 490, 8);
  ledcAttachPin(dimmer_1.LED_PIN, 0);
  pinMode(dimmer_1.SENSOR_PIN, INPUT);
  Serial.begin(115200);
}

void loop()
{
  measureLight(
    dimmer_1.sensor_value_sum,
    dimmer_1.AVERAGES,
    dimmer_1.SENSOR_PIN,
    dimmer_1.PART_DELAY);
  
  averageLight(
    dimmer_1.sensor_value_average,
    dimmer_1.sensor_value_sum,
    dimmer_1.AVERAGES);

  mapLed(
    dimmer_1.led_value,
    dimmer_1.sensor_value_average,
    dimmer_1.K);
  
  writeLed(dimmer_1.led_value);
  writeSerial(dimmer_1.led_value, dimmer_1.sensor_value_average);
  
  delay(dimmer_1.DELAY_TIME);
}
```

## API Reference

### `measureLight(uint32_t &sensor_value_sum, uint8_t AVERAGES, uint8_t SENSOR_PIN, uint16_t PART_DELAY)`
Measures ambient light and accumulates readings.

### `averageLight(uint16_t &sensor_value_average, uint32_t sensor_value_sum, uint8_t AVERAGES)`
Calculates the average sensor value over multiple readings.

### `mapLed(uint8_t &led_value, uint16_t sensor_value_average, float K)`
Maps sensor values to LED brightness using an exponential curve.

### `writeLed(uint8_t led_value)`
Writes the computed brightness level to the LED.

### `writeSerial(uint8_t led_value, uint16_t sensor_value_average)`
Outputs LED and sensor values to the serial monitor for debugging.

## Configuration
The `K` parameter defines the curve steepness of LED brightness adjustments. A higher `K` results in more rapid brightness transitions.

## License
This project is licensed under the GPL 2.0 License.

## Author
Marco Lind

