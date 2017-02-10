#ifndef _REGISTER_H
#define _REGISTER_H

#include <stdint.h>

void register_write16(volatile uint16_t* const registerAddress, const uint16_t registerValue);
void register_write32(volatile uint32_t* const registerAddress, const uint32_t registerValue);

#endif // _REGISTER_H
