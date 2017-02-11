#include "io.h"
#include "register.h"
#include "msp.h"

void io_configure_pin_as_output(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        register_set_bits8(&((DIO_PORT_Odd_Interruptable_Type*)port)->DIR, pin);
    }
}

void io_set_output_pin(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        register_set_bits8(&((DIO_PORT_Odd_Interruptable_Type*)port)->OUT, pin);
    }   
}
