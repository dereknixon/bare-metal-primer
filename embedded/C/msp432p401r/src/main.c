#include "msp.h"
#include "watchdog.h"
#include "io.h"
#include "low_frequency_crystal.h"
#include "timer_a.h"
#include "register.h"

static void init(void);
static void processing_forever(void);

int main(void)
{
    init();

    while(true)
    {
        processing_forever();
    }

    return 0;
}

static void init(void)
{
    stop_watchdog();

    enable_low_frequency_crystal();
    wait_for_low_frequency_crystal_stabilization();

    // Timer sourced from 32.768 kHz crystal, flash at 1Hz, 50% duty cycle
    const uint16_t TIMER_PERIOD = 32768;
    const uint16_t TIMER_DUTY_CYCLE = TIMER_PERIOD / 2;

    timer_a_init();
    timer_a_start_in_up_mode(TIMER_PERIOD);
    timer_a_set_compare(TIMER_DUTY_CYCLE);
    timer_a_set_output_mode_to_reset_set();
}

static void processing_forever(void)
{
    while(true);
}
