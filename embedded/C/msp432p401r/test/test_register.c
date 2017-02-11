#include "unity.h"
#include "register.h"

void test_register_write8_writes_value_to_register(void)
{
    uint8_t a_register = 0xF0;
    const uint8_t expected = 0x0A;

    register_write8(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT8(expected, a_register);
}

void test_register_write16_writes_value_to_register(void)
{
    uint16_t a_register = 0x00F0;
    const uint16_t expected = 0xF000;

    register_write16(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT16(expected, a_register);
}

void test_register_write32_writes_value_to_register(void)
{
    uint32_t a_register = 0x0F0000F0;
    const uint32_t expected = 0xF000F000;

    register_write32(&a_register, expected);

    TEST_ASSERT_EQUAL_UINT32(expected, a_register);
}

void test_register_set_bits8_sets_bits_within_register(void)
{
    uint8_t a_register = 0xF0;
    const uint8_t bits = 0x0A;
    const uint8_t expected = a_register | bits;;

    register_set_bits8(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT8(expected, a_register);
}

void test_register_set_bits16_sets_bits_within_register(void)
{
    uint16_t a_register = 0x00F0;
    const uint16_t bits = 0x0F00;
    const uint16_t expected = a_register | bits;;

    register_set_bits16(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT16(expected, a_register);
}

void test_register_set_bits32_sets_bits_within_register(void)
{
    uint32_t a_register = 0x0F0000F0;
    const uint32_t bits = 0xF000F000;
    const uint32_t expected = a_register | bits;

    register_set_bits32(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT32(expected, a_register);
}

void test_register_clear_bits8_clears_bits_within_register(void)
{
    uint8_t a_register = 0xF0;
    const uint8_t bits = 0xA0;
    const uint8_t expected = a_register & ~bits;;

    register_clear_bits8(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT8(expected, a_register);
}

void test_register_clear_bits16_clears_bits_within_register(void)
{
    uint16_t a_register = 0x00F0;
    const uint16_t bits = 0x00A0;
    const uint16_t expected = a_register & ~bits;;

    register_clear_bits16(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT16(expected, a_register);
}

void test_register_clear_bits32_clears_bits_within_register(void)
{
    uint32_t a_register = 0x0F0000F0;
    const uint32_t bits = 0x0F000000;
    const uint32_t expected = a_register & ~bits;

    register_clear_bits32(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT32(expected, a_register);
}

void test_register_toggle_bits8_toggles_bits_within_register(void)
{
    uint8_t a_register = 0xF0;
    const uint8_t bits = 0xA5;
    const uint8_t expected = a_register ^ bits;;

    register_toggle_bits8(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT8(expected, a_register);
}

void test_register_toggle_bits16_toggles_bits_within_register(void)
{
    uint16_t a_register = 0xF0F0;
    const uint16_t bits = 0xA5A5;
    const uint16_t expected = a_register ^ bits;;

    register_toggle_bits16(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT16(expected, a_register);
}

void test_register_toggle_bits32_toggles_bits_within_register(void)
{
    uint32_t a_register = 0xF0F0F0F0;
    const uint32_t bits = 0xA5A5A5A5;
    const uint32_t expected = a_register ^ bits;

    register_toggle_bits32(&a_register, bits);

    TEST_ASSERT_EQUAL_UINT32(expected, a_register);
}
