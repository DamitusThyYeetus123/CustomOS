#include "time.h"
#include "interrupts.h"

void sleep(uint32_t millis) {
    uint32_t CountDown = millis * 1000;
    while (CountDown > 0) {
        CountDown = CountDown - 1;
        io_wait();
    }
}

