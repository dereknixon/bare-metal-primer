#ifndef _IO_H
#define _IO_H

#include <stdint.h>
#include <stdbool.h>

void io_configure_pin_as_output(volatile void* const port, const uint8_t pin);
void io_set_output_pin(volatile void* const port, const uint8_t pin);
void io_clear_output_pin(volatile void* const port, const uint8_t pin);
void io_toggle_output_pin(volatile void* const port, const uint8_t pin);

void io_configure_pin_as_input(volatile void* const port, const uint8_t pin);
bool io_read_input_pin(volatile void* const port, const uint8_t pin);

void io_configure_pin_for_peripheral_in_primary_mode(volatile void* const port, const uint8_t pin);

#endif // _IO_H
