#ifndef _TIMER_A_H
#define _TIMER_A_H

#include <stdint.h>
#include "isr_callback.h"

void timer_a_init(void);
void timer_a_start(const uint16_t interval_in_counts);

void timer_a_set_a0_isr_callback(const isr_callback_t callback);
isr_callback_t timer_a_get_a0_isr_callback(void);
void timer_a_enable_a0_interrupt(void);
void timer_a0_0_isr(void);

#endif // _TIMER_A_H
