#include "msp.h"
#include "watchdog.h"
#include "io.h"
#include "low_frequency_crystal.h"
#include "timer_a.h"
#include "register.h"

static void init(void);
static void toggle_led(void);

int main(void)
{
    const uint16_t LED_TOGGLE_INTERVAL = 8192;     // 32.768kHz clock, 1/4 second interval

    init();

    timer_a_start(LED_TOGGLE_INTERVAL);

    while(true) {
//       uint16_t is_time = register_read16(&TIMER_A0->CTL);
//       if ((is_time & TIMER_A_CTL_IFG) == TIMER_A_CTL_IFG) {
//           timer_a0_0_isr();
//       }
    }

    return 0;
}

static void init(void)
{
    stop_watchdog();

    __disable_interrupt();

    io_configure_pin_as_output(P1, BIT0);
    io_configure_pin_as_input(P1, BIT1);
    io_clear_output_pin(P1, BIT0);

    enable_low_frequency_crystal();
    wait_for_low_frequency_crystal_stabilization();

    timer_a_init();
    timer_a_set_a0_isr_callback(toggle_led);
    timer_a_enable_a0_interrupt();

    NVIC_EnableIRQ(TA0_0_IRQn);
    __enable_interrupt();
}

static void toggle_led(void)
{
    io_toggle_output_pin(P1, BIT0);
}
