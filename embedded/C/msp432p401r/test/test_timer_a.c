#include "unity.h"
#include "testable_msp.h"
#include "timer_a.h"
#include <stdbool.h>

#include "mock_register.h"
#include "mock_isr_callback.h"

void test_timer_a_init_sets_stops_timer_and_sets_source_to_ACLK(void)
{
    register_clear_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_SSEL_MASK | TIMER_A_CTL_MC_MASK);
    register_set_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_SSEL__ACLK | TIMER_A_CTL_MC__STOP);

    timer_a_init();
}

void test_timer_a_start_clears_and_starts_timer_in_up_mode_with_given_interval(void)
{
    const uint16_t expected_interval = 1;

    register_clear_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_MC_MASK);
    register_set_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_MC__STOP);
    register_write16_Expect(&TIMER_A0->CCR[0], expected_interval); 
    register_set_bits16_Expect(&TIMER_A0->CTL, TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR);
    
    timer_a_start(expected_interval);
}

static void _test_a0_isr_callback(void) { }

void test_timer_a_a0_isr_callback_setters_are_working(void)
{
    timer_a_set_a0_isr_callback(_test_a0_isr_callback);

    TEST_ASSERT_EQUAL_PTR(_test_a0_isr_callback, timer_a_get_a0_isr_callback());
}

extern void TA0_0_IRQHandler(void);

void test_timer_a_interrupt_vector_calls_isr_callback(void)
{
    execute_isr_callback_Expect(_test_a0_isr_callback);

    TA0_0_IRQHandler();
}
