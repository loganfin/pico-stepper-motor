#include "stepper.h"

#include "pico/stdlib.h"

int main()
{
    stepper_init();

    while (true) {
        stepper_step(50, true);
        sleep_ms(200);
        stepper_step(50, false);
        sleep_ms(200);
        stepper_rev(true);
        sleep_ms(400);
    }
}
