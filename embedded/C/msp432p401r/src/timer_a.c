#include "timer_a.h"
#include "register.h"
#include "isr_callback.h"
#include "msp.h"

#include <stddef.h>

void timer_a_init(void)
{
    register_clear_bits16(&TIMER_A0->CTL, TIMER_A_CTL_SSEL_MASK | TIMER_A_CTL_MC_MASK);
    register_set_bits16(&TIMER_A0->CTL, TIMER_A_CTL_SSEL__ACLK | TIMER_A_CTL_MC__STOP);
}

void timer_a_start(const uint16_t interval_in_counts)
{
    register_clear_bits16(&TIMER_A0->CTL, TIMER_A_CTL_MC_MASK);
    register_set_bits16(&TIMER_A0->CTL, TIMER_A_CTL_MC__STOP);
    register_write16(&TIMER_A0->CCR[0], interval_in_counts);
    register_set_bits16(&TIMER_A0->CTL, TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR);
}

static isr_callback_t _a0_isr_callback = NULL;

void timer_a_set_a0_isr_callback(const isr_callback_t callback)
{
    _a0_isr_callback = callback;
}

isr_callback_t timer_a_get_a0_isr_callback(void)
{
    return _a0_isr_callback;
}

void TA0_0_IRQHandler(void)
{
    execute_isr_callback(_a0_isr_callback);
}