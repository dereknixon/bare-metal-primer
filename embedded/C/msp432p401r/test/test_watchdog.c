#include "unity.h"
#define EXTERN					// Needed in one test file, see http://vandervoord.net/blog/2015/5/24/unit-test-how-registers
#include "msp.h"
#include "watchdog.h"

#include "mock_register.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_stop_watchdog_writes_to_watchdog_control(void)
{
    register_write16_Expect(&WDT_A->CTL, WDT_A_CTL_PW | WDT_A_CTL_HOLD);

    stop_watchdog();
}
