#include "unity.h"
#include "testable_msp.h"
#include "io.h"

#include "mock_register.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_io_configure_pin_as_output_handles_P1(void)
{
    register_set_bits8_Expect(&P1->DIR, BIT0);
    
    configure_pin_as_output(P1, BIT0);
}

void test_io_configure_pin_as_output_does_not_handle_other_ports(void)
{
    DIO_PORT_Odd_Interruptable_Type an_unknown_port = { 0 };
    const DIO_PORT_Odd_Interruptable_Type expected_port = { 0 };;

    configure_pin_as_output(&an_unknown_port, BIT0);

    TEST_ASSERT_EQUAL_MEMORY(&expected_port, &an_unknown_port, sizeof(DIO_PORT_Odd_Interruptable_Type));
}
