# STM32 Garage Door Controller (In Progress)

A bare-metal STM32F411RE project built entirely from scratch. No HAL, no
CubeIDE, no vendor-generated code. Every register, startup instruction, and
build step is written and understood by hand, with the goal of actually
learning embedded systems at the level of memory maps, linker scripts, and
peripheral registers rather than working through a vendor abstraction layer.

The project is loosely framed as a "garage door" controller: a state machine
that opens and closes a door in response to a button, using a stepper motor
as the actuator, with obstacle detection and other sensors layered in as the
project grows.

## Hardware

STM32 Nucleo-F411RE (Cortex-M4), plus a small collection of sensors and
actuators being integrated incrementally: push button (EXTI), stepper motor,
ultrasonic distance sensor, accelerometer, and a temperature sensor.

## Toolchain

`arm-none-eabi-gcc`, OpenOCD, `gdb-multiarch`, CMake + Ninja (primary build
system). A legacy Makefile is kept as a known-working fallback.

## Build

```bash
mkdir -p build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-none-eabi.cmake ..
cmake --build .
```

Or in VS Code: **CMake: Build**.

## Flash & run

```bash
openocd -f board/st_nucleo_f4.cfg -c "program build/bin/project verify reset exit"
```

Or press **Start Debugging** in VS Code for the full debug workflow.

