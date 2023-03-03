#include "stepper.h"

#include "pico/stdlib.h"

const uint stepper_coil_1_pin = 6;
const uint stepper_coil_2_pin = 0;
const uint stepper_coil_3_pin = 1;
const uint stepper_coil_4_pin = 7;

const uint stepper_rev_steps = 524; // approximate

// initialize all of the necessary pins
void stepper_init()
{
    gpio_init(stepper_coil_1_pin);
    gpio_init(stepper_coil_2_pin);
    gpio_init(stepper_coil_3_pin);
    gpio_init(stepper_coil_4_pin);

    gpio_set_dir(stepper_coil_1_pin, GPIO_OUT);
    gpio_set_dir(stepper_coil_2_pin, GPIO_OUT);
    gpio_set_dir(stepper_coil_3_pin, GPIO_OUT);
    gpio_set_dir(stepper_coil_4_pin, GPIO_OUT);
}

// spins the motor 1 step per call in either direction
void stepper_step(uint steps, bool clockwise)
{
    uint delay = 1;

    if (clockwise) {
        for (int i = 0; i < steps; i++) {
            gpio_put(stepper_coil_4_pin, 1);
            sleep_ms(delay);
            gpio_put(stepper_coil_1_pin, 0);
            sleep_ms(delay);
            gpio_put(stepper_coil_3_pin, 1);
            sleep_ms(delay);
            gpio_put(stepper_coil_4_pin, 0);
            sleep_ms(delay);
            gpio_put(stepper_coil_2_pin, 1);
            sleep_ms(delay);
            gpio_put(stepper_coil_3_pin, 0);
            sleep_ms(delay);
            gpio_put(stepper_coil_1_pin, 1);
            sleep_ms(delay);
            gpio_put(stepper_coil_2_pin, 0);
            sleep_ms(delay);
        }
        return;
    }

    for (int i = 0; i < steps; i++) {
        gpio_put(stepper_coil_1_pin, 1);
        sleep_ms(delay);
        gpio_put(stepper_coil_4_pin, 0);
        sleep_ms(delay);
        gpio_put(stepper_coil_2_pin, 1);
        sleep_ms(delay);
        gpio_put(stepper_coil_1_pin, 0);
        sleep_ms(delay);
        gpio_put(stepper_coil_3_pin, 1);
        sleep_ms(delay);
        gpio_put(stepper_coil_2_pin, 0);
        sleep_ms(delay);
        gpio_put(stepper_coil_4_pin, 1);
        sleep_ms(delay);
        gpio_put(stepper_coil_3_pin, 0);
        sleep_ms(delay);
    }
}

// spins the motor one full revolution in either direction
void stepper_rev(bool clockwise)
{
    stepper_step(stepper_rev_steps, clockwise);
}
