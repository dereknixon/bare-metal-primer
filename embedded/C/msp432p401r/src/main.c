#include "msp.h"
#include "watchdog.h"
#include "io.h"

int main(void) {

    stop_watchdog();

    io_configure_pin_as_output(P1, BIT0);
    io_set_output_pin(P1, BIT0);

    while(1);

    return 0;
}

