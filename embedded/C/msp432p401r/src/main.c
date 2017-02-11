#include "msp.h"
#include "watchdog.h"
#include "io.h"

static void init(void);
static void toggle_led(void);
static void wait_to_toggle_led(void);
static bool is_button_pressed(void);
static void pretend_there_is_some_other_processing_going_on();
static void some_delay(void);

int main(void)
{
    init();

    while(true) {
        toggle_led();
        wait_to_toggle_led();

        if (is_button_pressed())
        {
            pretend_there_is_some_other_processing_going_on();
        }
    }

    return 0;
}

static void init(void)
{
    stop_watchdog();

    io_configure_pin_as_output(P1, BIT0);
    io_configure_pin_as_input(P1, BIT1);
    io_clear_output_pin(P1, BIT0);
}

static void toggle_led(void)
{
    io_toggle_output_pin(P1, BIT0);
}

static void wait_to_toggle_led(void)
{
    some_delay();
}

static bool is_button_pressed(void)
{
    // Active low
    return !io_read_input_pin(P1, BIT1);
}

static void pretend_there_is_some_other_processing_going_on(void)
{
    some_delay();
    some_delay();
    some_delay();
}

static void some_delay(void)
{
    for (uint32_t arbitrary_delay = 0; arbitrary_delay < 50000; arbitrary_delay++)
    {
    }
}
