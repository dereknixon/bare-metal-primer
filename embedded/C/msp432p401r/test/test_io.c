#include "unity.h"
#include "testable_msp.h"
#include "io.h"

#include "mock_register.h"

void test_io_configure_pin_as_output_handles_P1(void)
{
    register_set_bits8_Expect(&P1->DIR, BIT0);

    io_configure_pin_as_output(P1, BIT0);
}

void test_io_configure_pin_as_output_handles_P2(void)
{
    register_set_bits8_Expect(&P2->DIR, BIT0);

    io_configure_pin_as_output(P2, BIT0);
}

void test_io_configure_pin_as_output_does_not_handle_other_ports(void)
{
    DIO_PORT_Odd_Interruptable_Type an_unknown_port = { 0 };
    const DIO_PORT_Odd_Interruptable_Type expected_port = { 0 };;

    io_configure_pin_as_output(&an_unknown_port, BIT0);

    TEST_ASSERT_EQUAL_MEMORY(&expected_port, &an_unknown_port, sizeof(DIO_PORT_Odd_Interruptable_Type));
}

void test_io_set_output_pin_sets_output(void)
{
    register_set_bits8_Expect(&P1->OUT, BIT0);

    io_set_output_pin(P1, BIT0);
}

void test_io_set_output_pin_handles_P1(void)
{
    register_set_bits8_Expect(&P1->OUT, BIT0);

    io_set_output_pin(P1, BIT0);
}

void test_io_set_output_pin_handles_P2(void)
{
    register_set_bits8_Expect(&P2->OUT, BIT0);

    io_set_output_pin(P2, BIT0);
}

void test_io_set_output_pin_does_not_handle_other_ports(void)
{
    DIO_PORT_Odd_Interruptable_Type an_unknown_port = { 0 };
    const DIO_PORT_Odd_Interruptable_Type expected_port = { 0 };;

    io_set_output_pin(&an_unknown_port, BIT0);

    TEST_ASSERT_EQUAL_MEMORY(&expected_port, &an_unknown_port, sizeof(DIO_PORT_Odd_Interruptable_Type));
}

void test_io_clear_output_pin_clears_output(void)
{
    register_clear_bits8_Expect(&P1->OUT, BIT0);

    io_clear_output_pin(P1, BIT0);
}

void test_io_clear_output_pin_handles_P1(void)
{
    register_clear_bits8_Expect(&P1->OUT, BIT0);

    io_clear_output_pin(P1, BIT0);
}

void test_io_clear_output_pin_handles_P2(void)
{
    register_clear_bits8_Expect(&P2->OUT, BIT0);

    io_clear_output_pin(P2, BIT0);
}

void test_io_clear_output_pin_does_not_handle_other_ports(void)
{
    DIO_PORT_Odd_Interruptable_Type an_unknown_port = { 0 };
    const DIO_PORT_Odd_Interruptable_Type expected_port = { 0 };;

    io_clear_output_pin(&an_unknown_port, BIT0);

    TEST_ASSERT_EQUAL_MEMORY(&expected_port, &an_unknown_port, sizeof(DIO_PORT_Odd_Interruptable_Type));
}

void test_io_toggle_output_pin_toggles_output(void)
{
    register_toggle_bits8_Expect(&P1->OUT, BIT0);

    io_toggle_output_pin(P1, BIT0);
}

void test_io_toggle_output_pin_handles_P1(void)
{
    register_toggle_bits8_Expect(&P1->OUT, BIT0);

    io_toggle_output_pin(P1, BIT0);
}

void test_io_toggle_output_pin_handles_P2(void)
{
    register_toggle_bits8_Expect(&P2->OUT, BIT0);

    io_toggle_output_pin(P2, BIT0);
}

void test_io_toggle_output_pin_does_not_handle_other_ports(void)
{
    DIO_PORT_Odd_Interruptable_Type an_unknown_port = { 0 };
    const DIO_PORT_Odd_Interruptable_Type expected_port = { 0 };;

    io_toggle_output_pin(&an_unknown_port, BIT0);

    TEST_ASSERT_EQUAL_MEMORY(&expected_port, &an_unknown_port, sizeof(DIO_PORT_Odd_Interruptable_Type));
}

void test_io_configure_pin_as_input_handles_P1(void)
{
    register_clear_bits8_Expect(&P1->DIR, BIT0);

    io_configure_pin_as_input(P1, BIT0);
}

void test_io_configure_pin_as_input_handles_P2(void)
{
    register_clear_bits8_Expect(&P2->DIR, BIT0);

    io_configure_pin_as_input(P2, BIT0);
}

void test_io_configure_pin_as_input_does_not_handle_other_ports(void)
{
    DIO_PORT_Odd_Interruptable_Type an_unknown_port = { 0 };
    const DIO_PORT_Odd_Interruptable_Type expected_port = { 0 };;

    io_configure_pin_as_input(&an_unknown_port, BIT0);

    TEST_ASSERT_EQUAL_MEMORY(&expected_port, &an_unknown_port, sizeof(DIO_PORT_Odd_Interruptable_Type));
}

void test_io_read_input_pin_returns_false_when_pin_is_cleared_on_P1(void)
{
    register_read8_ExpectAndReturn(&P1->IN, 0);

    bool actual = io_read_input_pin(P1, BIT0);

    TEST_ASSERT_FALSE(actual);
}

void test_io_read_input_pin_returns_true_when_pin_is_set_on_P1(void)
{
    register_read8_ExpectAndReturn(&P1->IN, 1);

    bool actual = io_read_input_pin(P1, BIT0);

    TEST_ASSERT_TRUE(actual);
}

void test_io_read_input_pin_returns_false_when_pin_is_cleared_on_P2(void)
{
    register_read8_ExpectAndReturn(&P2->IN, 0);

    bool actual = io_read_input_pin(P2, BIT0);

    TEST_ASSERT_FALSE(actual);
}

void test_io_read_input_pin_returns_true_when_pin_is_set_on_P2(void)
{
    register_read8_ExpectAndReturn(&P2->IN, 1);

    bool actual = io_read_input_pin(P2, BIT0);

    TEST_ASSERT_TRUE(actual);
}

void test_io_read_input_pin_does_not_handle_other_ports(void)
{
    DIO_PORT_Odd_Interruptable_Type an_unknown_port = { 0 };
    const DIO_PORT_Odd_Interruptable_Type expected_port = { 0 };;

    bool actual = io_read_input_pin(&an_unknown_port, BIT0);

    TEST_ASSERT_EQUAL_MEMORY(&expected_port, &an_unknown_port, sizeof(DIO_PORT_Odd_Interruptable_Type));
    TEST_ASSERT_FALSE(actual);
}
