#include "isr_callback.h"

#include <stddef.h>

void execute_isr_callback(const isr_callback_t to_execute)
{
    if (to_execute != NULL)
    {
       (*to_execute)();
    }
}
