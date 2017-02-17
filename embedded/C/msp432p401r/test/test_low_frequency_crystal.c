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

void test_wait_for_low_frequency_crystal_stabilization_immediately_passes_through_when_already_stable(void)
{
    register_write32_Expect(&CS->KEY, CS_KEY_VAL);
    register_read32_ExpectAndReturn(&CS->IFG, 0);
    register_write32_Expect(&CS->KEY, 0);

    wait_for_low_frequency_crystal_stabilization();
}

void test_wait_for_low_frequency_crystal_stabilization_waits_for_fault_flag_to_clear(void)
{
    register_write32_Expect(&CS->KEY, CS_KEY_VAL);
    register_read32_ExpectAndReturn(&CS->IFG, BIT0);
    register_write32_Expect(&CS->CLRIFG, BIT0);
    register_read32_ExpectAndReturn(&CS->IFG, 0);
    register_write32_Expect(&CS->KEY, 0);

    wait_for_low_frequency_crystal_stabilization();
}
