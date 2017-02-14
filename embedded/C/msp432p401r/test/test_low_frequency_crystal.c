#include "unity.h"
#include "testable_msp.h"
#include "low_frequency_crystal.h"

#include "mock_register.h"

void test_enable_low_frequency_crystal_selects_lfxin_and_lfxout_pins(void)
{
    register_set_bits16_Expect(&PJ->SEL0, BIT0);

    enable_low_frequency_crystal();
}

void test_disable_low_frequency_crystal_deselects_lfxin_and_lfxout_pins(void)
{
    register_clear_bits16_Expect(&PJ->SEL0, BIT0);

    disable_low_frequency_crystal();
}
