#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "print.h"
#pragma once

void print_input();
char* get_input_till_key_pressed(uint8_t key, char out[4096]);