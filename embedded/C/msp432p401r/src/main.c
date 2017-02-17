#include "msp.h"
#include "watchdog.h"
#include "io.h"
#include "low_frequency_crystal.h"
#include "timer_a.h"
#include "register.h"

static void init(void);

int main(void)
{
    init();

    while(true)
    {
    }

    return 0;
}

static void init(void)
{
    stop_watchdog();

    io_configure_pin_as_output(P2, BIT0 | BIT1 | BIT2);
    io_configure_pin_for_peripheral_in_primary_mode(P2, BIT0 | BIT1 | BIT2);

    io_configure_pin_as_output(P7, BIT3);
    io_configure_pin_for_peripheral_in_primary_mode(P7, BIT3);

    enable_low_frequency_crystal();
    wait_for_low_frequency_crystal_stabilization();

    timer_a_init();
    timer_a_set_compare(32768);
    timer_a_set_output_mode_to_set_reset();
    timer_a_start_in_up_mode(65000);
}
