# DimmerLib library

## Overview
The **DimmerLib library** is an easy-to-use, **Arduino-compatible** library designed for the **ESP32** microcontroller. It automatically adjusts the brightness of an LED based on ambient light levels. It follows the **inverse square law** to provide a natural perception of brightness changes and includes **anti-flickering** mechanisms to cancel out **50–60 Hz** interference. Designed for **thread-safe multitasking**, this library integrates seamlessly with **FreeRTOS** on the ESP32.

## Features
- **Adaptive brightness**: Dynamically adjusts LED brightness based on ambient light.
- **Inverse square law mapping**: Ensures smooth and natural transitions in brightness.
- **Anti-flickering design**: Reduces flickering effects caused by power fluctuations at 50-60 Hz by default.
- **Multithreaded with FreeRTOS**: Each dimmer runs in its own task with safe access to Serial.
- **Configurable parameters**: Allows users to customize sampling rate, delay time, and mapping curve.
- **Manual and automatic modes**: Toggle between potentiometer control and light-sensing.
- **Debug mode toggle**: Enable/disable serial output on-the-fly via a button ISR.
- **ISR macros**: Standardized macros simplify the creation of button ISRs.
- **Designed for ESP32**: Optimized for the ESP32 platform.
- **Built using PlatformIO**: Developed and tested with the PlatformIO environment.
- **Tested on ESP32-C3 Super Mini**

## Installation
To use the DimmerLib library, include the header file in your Arduino project:

```cpp
#include <DimmerLib.h>
```

## Usage

### Initialization
Create a `LightSensingDimmer` object by specifying the following parameters:

```cpp
DimmerLib::LightSensingDimmer dimmer(A4, 6, 5, 7, A2 0);
```

- `SENSOR_PIN_` – Analog pin to read light levels.
- `LED_PIN_` – PWM-capable pin connected to the LED.
- `MODE_BUTTON_PIN_` – Digital pin connected to mode toggle button (INPUT_PULLUP).
- `DEBUG_BUTTON_PIN_` – Digital pin to toggle serial debug output.
- `POT_PIN_` – Analog pin connected to potentiometer for manual dimming.
- `CHANNEL_` – PWM channel (0–15 on ESP32).
- `mode_` – *(Optional)* Starting mode (`AUTO` or `MANUAL`).
- `K_` – *(Optional)* Exponential brightness curve factor.
- `POLLING_RATE_` – *(Optional)* Delay between each update (in ms).
- `AVERAGES_` – *(Optional)* Number of light samples to average.
- `PART_DELAY_` – *(Optional)* Microsecond delay between light samples.

If optional fields are left empty, the object will default to settings optimized to reduce flickering at 50-60 Hz.

### Example Code

#### Arduino:

```cpp
DimmerLib::LightSensingDimmer dimmer(A4, 6, 5, 7, A2, 0);

MAKE_MODE_SWITCH_ISR(modeSwitchISR, dimmer)
MAKE_DEBUG_SWITCH_ISR(debugSwitchISR, dimmer)

void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit();

  attachInterrupt(digitalPinToInterrupt(dimmer.MODE_BUTTON_PIN), modeSwitchISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer.DEBUG_BUTTON_PIN), debugSwitchISR, RISING);
}

void loop()
{
  DimmerLib::runDimmer(dimmer);
}
```

#### FreeRTOS:

```cpp
DimmerLib::LightSensingDimmer dimmer_0(A4, 6, 5, 7, A2, 0);
DimmerLib::LightSensingDimmer dimmer_1(A4, 8, 9, 7, A3, 1);

MAKE_MODE_SWITCH_ISR(modeSwitchISR_0, dimmer_0)
MAKE_MODE_SWITCH_ISR(modeSwitchISR_1, dimmer_1)
MAKE_DEBUG_SWITCH_ISR(debugSwitchISR, dimmer_0)

void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit();

  attachInterrupt(digitalPinToInterrupt(dimmer.MODE_BUTTON_PIN), modeSwitchISR_0, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer.MODE_BUTTON_PIN), modeSwitchISR_1, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer.DEBUG_BUTTON_PIN), debugSwitchISR, RISING);

  INITIATE_DIMMER_TASK(dimmer_0, 1);
  INITIATE_DIMMER_TASK(dimmer_1, 1);
}

void loop()
{
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

### `MAKE_DEBUG_SWITCH_ISR(ISR_NAME, DIMMER_OBJECT)`
Macro to create a debug ISR that toggles switches serial prints on or off.

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
    uint8_t DEBUG_BUTTON_PIN_,
    uint8_t POT_PIN_,
    uint8_t CHANNEL_,
    volatile uint8_t mode_ = AUTO,
    float K_ = 2.0,
    uint8_t POLLING_RATE_ = 100,
    uint8_t AVERAGES_ = 20,
    uint16_t PART_DELAY_ = 2500
)
```

## Configuration
The `K` parameter defines the curve steepness of LED brightness adjustments. A higher `K` results in more rapid brightness transitions.

## License
This project is licensed under the GPL 2.0 License.

## Author
Marco Lind

