#ifndef _TIMER_A_H
#define _TIMER_A_H

#include <stdint.h>

void timer_a_init(void);
void timer_a_start(const uint16_t interval_in_counts);

#endif // _TIMER_A_H
