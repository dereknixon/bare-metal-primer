#include "low_frequency_crystal.h"
#include "register.h"
#include "msp.h"

void enable_low_frequency_crystal(void)
{
    register_set_bits16(&PJ->SEL0, BIT0);
}

void disable_low_frequency_crystal(void)
{
    register_clear_bits16(&PJ->SEL0, BIT0);
}

void wait_for_low_frequency_crystal_stabilization(void)
{
    register_write32(&CS->KEY, CS_KEY_VAL);

    while((register_read32(&CS->IFG) & BIT0) == BIT0)
    {
        register_write32(&CS->CLRIFG, BIT0);
    }

    register_write32(&CS->KEY, 0);
}
