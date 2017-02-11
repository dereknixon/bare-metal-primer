#include "io.h"
#include "register.h"
#include "msp.h"

void io_configure_pin_as_output(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        register_set_bits8(&((DIO_PORT_Odd_Interruptable_Type*)port)->DIR, pin);
    } else if (port == P2) {
        register_set_bits8(&((DIO_PORT_Even_Interruptable_Type*)port)->DIR, pin);
    }
}

void io_set_output_pin(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        register_set_bits8(&((DIO_PORT_Odd_Interruptable_Type*)port)->OUT, pin);
    } else if (port == P2) {
        register_set_bits8(&((DIO_PORT_Even_Interruptable_Type*)port)->OUT, pin);
    }
}

void io_clear_output_pin(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        register_clear_bits8(&((DIO_PORT_Odd_Interruptable_Type*)port)->OUT, pin);
    } else if (port == P2) {
        register_clear_bits8(&((DIO_PORT_Even_Interruptable_Type*)port)->OUT, pin);
    }
}

void io_toggle_output_pin(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        register_toggle_bits8(&((DIO_PORT_Odd_Interruptable_Type*)port)->OUT, pin);
    } else if (port == P2) {
        register_toggle_bits8(&((DIO_PORT_Even_Interruptable_Type*)port)->OUT, pin);
    }
}

void io_configure_pin_as_input(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        register_clear_bits8(&((DIO_PORT_Odd_Interruptable_Type*)port)->DIR, pin);
    } else if (port == P2) {
        register_clear_bits8(&((DIO_PORT_Even_Interruptable_Type*)port)->DIR, pin);
    }
}

bool io_read_input_pin(volatile void* const port, const uint8_t pin) {
    if (port == P1) {
        return ((((DIO_PORT_Odd_Interruptable_Type*)port)->IN & pin) == pin);
    } else if (port == P2) {
        return ((((DIO_PORT_Even_Interruptable_Type*)port)->IN & pin) == pin);
    }

    return false;
}
