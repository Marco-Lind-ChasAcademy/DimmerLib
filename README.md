### To do:
- Optimizations. Alignment
- Custom namespace: DONE
- Put button vars into Light_sensing_dimmer class or it's own: DONE
- Make functions to simplify initialization in setup() and main(): DONE
- Update doxy comments for constructor and class: DONE
- Integrate with FreeRTOS to allow multithreading. loop() -> xTaskCreate(). millis() -> delay(): DONE
- Put setupDimmer() into constructor instead: DONE
- Put task creation function into header: DONE
- Implement thread sync mechanisms where needed. Binary semasphores: DONE
- Test conflicting pins to ensure thread safety: DONE
- Make button and ISR for debug mode (for serial prints, so that they don't always run): DONE
- Add some sort or standardized way to schedule vTaskDelays in main. vTaskDelay(num_of_delays - 1): DONE
- Add function or macro for task initialization in main: DONE
- Update README
- Replace delayMicroseconds with something more optimized: DONE

# DimmerLib library

## Overview
The **DimmerLib library** is an easy to use, **Arduino-compatible** library designed for the **ESP32** microcontroller. It automatically adjusts the brightness of an LED based on ambient light levels. It follows the **inverse square law** to provide a natural perception of brightness changes and includes **anti-flickering** mechanisms to cancel out fluctuations at **50-60 Hz**. Designed for **ease of use**, this library allows seamless integration into projects requiring automatic LED dimming.

## Features
- **Adaptive brightness**: Dynamically adjusts LED brightness based on ambient light.
- **Inverse square law mapping**: Ensures smooth and natural transitions in brightness.
- **Anti-flickering design**: Reduces flickering effects caused by power fluctuations at 50-60 Hz by default.
- **Configurable parameters**: Allows users to customize sampling rate, delay time, and mapping curve.
- **Serial output for debugging**: Provides real-time sensor readings and LED values.
- **ISR macro**: Provides a standardized macro for easy ISR creation.
- **Designed for ESP32**: Optimized for the ESP32 platform.
- **Tested on ESP32-C3 Super Mini**: Verified to work on this specific board.
- **Built using PlatformIO**: Developed and tested with the PlatformIO environment.

## Installation
To use the DimmerLib library, include the header file in your Arduino project:

```cpp
#include <DimmerLib.h>
```

## Usage

### Initialization
Create a `LightSensingDimmer` object by specifying the following parameters:

```cpp
DimmerLib::LightSensingDimmer dimmer(A4, 6, 5, A3, 0);
```

- `SENSOR_PIN_` – Analog pin to read light levels.
- `LED_PIN_` – PWM-capable pin connected to the LED.
- `MODE_BUTTON_PIN_` – Digital pin connected to mode toggle button (INPUT_PULLUP).
- `POT_PIN_` – Analog pin connected to potentiometer for manual dimming.
- `CHANNEL_` – PWM channel (0–15 on ESP32).
- `mode_` – **Optional**: Starting mode (AUTO or MANUAL).
- `K_` – **Optional**: Exponential scaling factor for brightness mapping.
- `POLLING_RATE_` – **Optional**: Update rate in ms.
- `AVERAGES_` – **Optional**: Number of light samples to average.
- `PART_DELAY_` – **Optional**: Microsecond delay between samples.

If optional fields are left empty, the object will default to settings optimized for 50-60 Hz anti-flickering.

### Example Code
```cpp
DimmerLib::LightSensingDimmer dimmer(A4, 6, 5, A3, 0);

MAKE_MODE_SWITCH_ISR(dimmer_ISR, dimmer)

void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit();

  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_ISR, RISING);
}

void loop()
{
  DimmerLib::runDimmer(dimmer);
}
```

## API Reference

### `measureLight(uint32_t &sensor_value_sum, uint8_t AVERAGES, uint8_t SENSOR_PIN, uint16_t PART_DELAY)`
Measures ambient light by summing analog readings over a number of samples.

- **Parameters:**
  - `sensor_value_sum`: Reference to store the total light measurement.
  - `AVERAGES`: Number of samples to take.
  - `SENSOR_PIN`: Analog pin used to read the light sensor.
  - `PART_DELAY`: Delay (in microseconds) between each sample.

---

### `averageLight(uint16_t &sensor_value_average, uint32_t sensor_value_sum, uint8_t AVERAGES)`
Calculates the average sensor value over the total sum of readings.

- **Parameters:**
  - `sensor_value_average`: Reference to store the averaged result.
  - `sensor_value_sum`: Accumulated sum of sensor readings.
  - `AVERAGES`: Number of samples used in the sum.

---

### `mapLed(uint8_t &led_value, uint16_t sensor_value_average, float K)`
Applies an exponential mapping to the averaged sensor value to determine LED brightness.

- **Parameters:**
  - `led_value`: Reference to store the calculated brightness (0–255).
  - `sensor_value_average`: Averaged sensor value.
  - `K`: Curve sharpness constant (higher values make the curve steeper).

---

### `writeLed(LightSensingDimmer &dimmer)`
Writes the calculated brightness level to the LED using PWM.

- **Parameters:**
  - `dimmer`: Reference to the `LightSensingDimmer` instance to control.

---

### `writeSerial(uint8_t led_value, uint16_t sensor_value_average)`
Outputs the current LED brightness and light level average to the serial monitor.

- **Parameters:**
  - `led_value`: Current brightness level.
  - `sensor_value_average`: Current averaged light level.

---

### `runDimmer(LightSensingDimmer &dimmer)`
Main control loop for the dimmer. Should be called repeatedly in `loop()`.

- **Behavior:**
  - In **AUTO** mode: Measures and averages ambient light, adjusts LED brightness accordingly.
  - In **MANUAL** mode: Uses potentiometer value to set LED brightness.
  - Switches mode using the provided mode-switch button.

- **Parameters:**
  - `dimmer`: Reference to a `LightSensingDimmer` object.

---

### `void runDimmerTask(void *pvParameter)`
FreeRTOS task for `runDimmer()`.

- **Behavior:**
  - Runs a `runDimmer()`-based task

- **Parameters:**
  - `pvParameter`: for `xTaskCreate()`.

---

### `void writeSerialSafe(uint8_t led_value, uint16_t sensor_value_average)`
Writes serial output in thread-safe manner.

- **Behavior:**
  - Runs a `runDimmer()`-based task

- **Parameters:**
  - `led_value`: Dimmer object LED output value.
  - `sensor_value_average`: Dimmer object average sensor value.

---

### `void semInit()`
Initializes semaphores.

- **Behavior:**
  - Runs xSemaphoreGive() for the Serial semaphore

- **Parameters:**

---

### `MAKE_MODE_SWITCH_ISR(ISR_NAME, DIMMER_OBJECT)`
Macro to create a mode-switching ISR that toggles between `AUTO` and `MANUAL` modes.

- **Parameters:**
  - `ISR_NAME`: Desired name for the ISR function.
  - `DIMMER_OBJECT`: Instance of `LightSensingDimmer` to operate on.

---

### `LightSensingDimmer` Constructor
Initializes a dimmer object for controlling an LED based on ambient light or manual control.

```cpp
LightSensingDimmer(
    uint8_t SENSOR_PIN_,
    uint8_t LED_PIN_,
    uint8_t MODE_BUTTON_PIN_,
    uint8_t POT_PIN_,
    uint8_t CHANNEL_,
    volatile uint8_t mode_ = AUTO,
    uint8_t POLLING_RATE_ = 100,
    uint8_t AVERAGES_ = 20,
    uint16_t PART_DELAY_ = 2500,
    float K_ = 2.0
)
```

## Configuration
The `K` parameter defines the curve steepness of LED brightness adjustments. A higher `K` results in more rapid brightness transitions.

## License
This project is licensed under the GPL 2.0 License.

## Author
Marco Lind

