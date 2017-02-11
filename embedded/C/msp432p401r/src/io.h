#ifndef _IO_H
#define _IO_H

#include <stdint.h>

void io_configure_pin_as_output(volatile void* const port, const uint8_t pin);
void io_set_output_pin(volatile void* const port, const uint8_t pin);

#endif // _IO_H
