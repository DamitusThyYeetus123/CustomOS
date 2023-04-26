#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "print.h"
#pragma once

int strlen(char* string);
char* join_strings(char* stringA, char* stringB, char out[4096]);
char *strstr1(const char *str, const char *substring)
