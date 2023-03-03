# pico-stepper-motor
Trying to get a 28BYJ-48 stepper motor working with the rp2040-based Pico Feather

## Building

This program depends on the pico-sdk

1. Clone the repository:
    ```
    git clone https://github.com/loganfin/pico-stepper-motor.git
    ```
2. Configure the build directory using CMake:
    * If you already have the pico-sdk on your machine:
        ```
        cmake -B build -DPICO_SDK_PATH=</path/to/pico-sdk/>
        ```
    * If you don't have the pico-sdk on your machine:
        ```
        git submodule update --init
        git -C lib/pico-sdk/ submodule update --init
        cmake -B build
        ```
3. Build the program:
    ```
    cmake --build build
    ```

The uf2 binary will be located inside the `build` directory that was created with the `cmake -B build` command.

