#include "string.h"

int strlen(char* string) {
    int size = sizeof(string) / sizeof(char);
}

char* join_strings(char* stringA, char* stringB, char out[2048]) { 
    int counter = 0;
    for (int i=0; i<strlen(stringA); i++){
        out[counter] = stringA[i];
        counter++;
    }
    for (int i=0; i<strlen(stringB); i++){
        out[counter] = stringB[i];
        counter++;
    }
    return out;
}