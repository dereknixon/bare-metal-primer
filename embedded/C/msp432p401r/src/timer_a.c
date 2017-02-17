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

void timer_a_start_in_up_mode(const uint16_t interval_in_counts)
{
    register_clear_bits16(&TIMER_A0->CTL, TIMER_A_CTL_MC_MASK);
    register_set_bits16(&TIMER_A0->CTL, TIMER_A_CTL_MC__STOP);
    register_write16(&TIMER_A0->CCR[0], interval_in_counts);
    register_set_bits16(&TIMER_A0->CTL, TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR);
}

void timer_a_set_compare(const uint16_t interval_in_counts)
{
    register_set_bits16(&TIMER_A0->CCR[1], interval_in_counts);
}

void timer_a_set_output_mode_to_reset_set()
{
    register_clear_bits16(&TIMER_A0->CCTL[0], TIMER_A_CCTLN_CCIE | TIMER_A_CCTLN_OUTMOD_7);
    register_clear_bits16(&TIMER_A0->CCTL[1], TIMER_A_CCTLN_OUTMOD_MASK);
    register_set_bits16(&TIMER_A0->CCTL[1], TIMER_A_CCTLN_OUTMOD_7);

    register_set_bits8(&P2->DIR, BIT4);
    register_set_bits8(&P2->SEL0, BIT4);
    register_clear_bits8(&P2->SEL1, BIT4);
}

void timer_a_enable_a0_interrupt(void)
{
    register_set_bits16(&TIMER_A0->CTL, TIMER_A_CTL_IE);
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

void timer_a0_0_isr(void)
{
    register_clear_bits16(&TIMER_A0->CTL, TIMER_A_CTL_IFG);
    execute_isr_callback(timer_a_get_a0_isr_callback());
}
