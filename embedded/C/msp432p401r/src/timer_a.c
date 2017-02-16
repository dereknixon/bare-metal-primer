#include "timer_a.h"
#include "register.h"
#include "msp.h"

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
