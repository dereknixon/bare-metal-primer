#include "unity.h"
#include "testable_msp.h"
#include "timer_a.h"
#include <stdbool.h>

#include "mock_register.h"
#include "mock_isr_callback.h"
#include "mock_io.h"

void test_timer_a_init_sets_stops_timer_and_sets_source_to_ACLK(void)
{
    register_clear_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_SSEL_MASK | TIMER_A_CTL_MC_MASK);
    register_set_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_SSEL__ACLK | TIMER_A_CTL_MC__STOP);

    timer_a_init();
}

void test_timer_a_start_in_up_mode_clears_and_starts_timer_in_up_mode_with_given_interval(void)
{
    const uint16_t expected_interval = 1;

    register_clear_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_MC_MASK);
    register_set_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_MC__STOP);
    register_write16_Expect(&TIMER_A0->CCR[0], expected_interval); 
    register_set_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR);
    
    timer_a_start_in_up_mode(expected_interval);
}

void test_timer_a_set_compare_sets_ccr_to_given_count(void)
{
    const uint16_t expected_interval = 1;

    register_set_bits16_Expect(&TIMER_A0->CCR[1], expected_interval);

    timer_a_set_compare(expected_interval);
}

void test_timer_a_set_output_mode_to_reset_set(void)
{
    register_clear_bits16_Expect(&TIMER_A0->CCTL[0], TIMER_A_CCTLN_CCIE | TIMER_A_CCTLN_OUTMOD_7);
    register_clear_bits16_Expect(&TIMER_A0->CCTL[1], TIMER_A_CCTLN_OUTMOD_MASK);
    register_set_bits16_Expect(&TIMER_A0->CCTL[1], TIMER_A_CCTLN_OUTMOD_7);

    register_set_bits8_Expect(&P2->DIR, BIT4);
    register_set_bits8_Expect(&P2->SEL0, BIT4);
    register_clear_bits8_Expect(&P2->SEL1, BIT4);

    timer_a_set_output_mode_to_reset_set();
}

void test_timer_a_enable_a0_interrupt_sets_interrupt_enable_bits(void)
{
    register_set_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_IE);

    timer_a_enable_a0_interrupt();
}

static void _test_timer_isr_callback(void) { }

void test_timer_a_a0_isr_callback_setters_are_working(void)
{
    timer_a_set_a0_isr_callback(_test_timer_isr_callback);

    TEST_ASSERT_EQUAL_PTR(_test_timer_isr_callback, timer_a_get_a0_isr_callback());
}

void test_timer_a0_0_isr_clears_interrupt_flag_and_calls_isr_callback(void)
{
    register_clear_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_IFG);
    execute_isr_callback_Expect(_test_timer_isr_callback);

    timer_a0_0_isr();
}
