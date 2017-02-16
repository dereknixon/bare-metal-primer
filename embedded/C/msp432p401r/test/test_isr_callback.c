#include "unity.h"
#include "testable_msp.h"
#include "isr_callback.h"

#include <stddef.h>
#include <stdbool.h>

void test_execute_interrupt_callback_should_handle_if_callback_is_NULL(void)
{
    // NOTE: The inability of execute_isr_callback to handle NULL pointers will
    // show up during testing as a failed test due to seg fault/abort.   
    execute_isr_callback(NULL);
}

static bool was_isr_callback_executed = false;

static void an_isr_callback(void)
{
    was_isr_callback_executed = true;
}

void test_execute_isr_callback_should_execute_provided_callback(void)
{
    was_isr_callback_executed = false;
    execute_isr_callback(an_isr_callback);
  
    TEST_ASSERT_TRUE(was_isr_callback_executed);
}
