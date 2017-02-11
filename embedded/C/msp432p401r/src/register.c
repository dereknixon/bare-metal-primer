#include "register.h"

void register_write8(volatile uint8_t* const register_address, const uint8_t value_to_write) {
    (*register_address) = value_to_write;
}

void register_write16(volatile uint16_t* const register_address, const uint16_t value_to_write) {
    (*register_address) = value_to_write;
}

void register_write32(volatile uint32_t* const register_address, const uint32_t value_to_write) {
    (*register_address) = value_to_write;
}

void register_set_bits8(volatile uint8_t* const register_address, const uint8_t bits_to_set) {
    (*register_address) |= bits_to_set;
}

void register_set_bits16(volatile uint16_t* const register_address, const uint16_t bits_to_set) {
    (*register_address) |= bits_to_set;
}

void register_set_bits32(volatile uint32_t* const register_address, const uint32_t bits_to_set) {
    (*register_address) |= bits_to_set;
}

void register_clear_bits8(volatile uint8_t* const register_address, const uint8_t bits_to_clear) {
    (*register_address) &= ~bits_to_clear;
}

void register_clear_bits16(volatile uint16_t* const register_address, const uint16_t bits_to_clear) {
    (*register_address) &= ~bits_to_clear;
}

void register_clear_bits32(volatile uint32_t* const register_address, const uint32_t bits_to_clear) {
    (*register_address) &= ~bits_to_clear;
}

void register_toggle_bits8(volatile uint8_t* const register_address, const uint8_t bits_to_toggle) {
    (*register_address) ^= bits_to_toggle;
}

void register_toggle_bits16(volatile uint16_t* const register_address, const uint16_t bits_to_toggle) {
    (*register_address) ^= bits_to_toggle;
}

void register_toggle_bits32(volatile uint32_t* const register_address, const uint32_t bits_to_toggle) {
    (*register_address) ^= bits_to_toggle;
}
