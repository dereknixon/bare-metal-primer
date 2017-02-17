#ifndef _ISR_CALLBACK_H
#define _ISR_CALLBACK_H

#include <stddef.h>

typedef void (* isr_callback_t)(void);

void execute_isr_callback(const isr_callback_t to_execute);

#endif // _ISR_CALLBACK_H
