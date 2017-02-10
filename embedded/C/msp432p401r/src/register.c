#include "register.h"

void register_write16(volatile uint16_t* const registerAddress, const uint16_t registerValue) {
    (*registerAddress) = registerValue;
}

void register_write32(volatile uint32_t* const registerAddress, const uint32_t registerValue) {
    (*registerAddress) = registerValue;
}
