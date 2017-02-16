#include "unity.h"
#include "testable_msp.h"
#include "timer_a.h"

#include "mock_register.h"

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
