#include "watchdog.h"
#include "register.h"
#include "msp.h"

void stop_watchdog(void) {
    register_write16(&WDT_A->CTL, WDT_A_CTL_PW | WDT_A_CTL_HOLD);
}

