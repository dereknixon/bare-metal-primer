#include "unity.h"
#include "register.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_register_write8_value_to_register(void)
{
    uint8_t a_register = 0xF0;
    const uint8_t expected = 0x0A;

    register_write8(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT8(expected, a_register);
}

void test_register_write16_value_to_register(void)
{
    uint16_t a_register = 0x00F0;
    const uint16_t expected = 0xF000;

    register_write16(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT16(expected, a_register);
}

void test_register_write32_value_to_register(void)
{
    uint32_t a_register = 0x0F0000F0;
    const uint32_t expected = 0xF000F000;

    register_write32(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT32(expected, a_register);
}

void test_register_set_bits8_value_to_register(void)
{
    uint8_t a_register = 0x00F0;
    const uint8_t bits = 0x0A;
    const uint8_t expected = a_register | bits;;

    register_set_bits8(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT8(expected, a_register);
}

void test_register_set_bits16_value_to_register(void)
{
    uint16_t a_register = 0x00F0;
    const uint16_t bits = 0x0F00;
    const uint16_t expected = a_register | bits;;

    register_set_bits16(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT16(expected, a_register);
}

void test_register_set_bits32_value_to_register(void)
{
    uint32_t a_register = 0x0F0000F0;
    const uint32_t bits = 0xF000F000;
    const uint32_t expected = a_register | bits;

    register_set_bits32(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT32(expected, a_register);
}

