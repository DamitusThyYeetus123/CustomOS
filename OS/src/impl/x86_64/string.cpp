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
char *strstr1(const char *str, const char *substring)
{
  const char *a, *b = substring;

  if ( !*b ) return (char *) str;
  for ( ; *str ; str++) {
    if (*str != *b) continue;
    a = str;
    for (;;) {
      if ( !*b ) return (char *) str;
      if (*a++ != *b++) break;
    }
    b = substring;
  }
  return NULL;
}
void clean(char *var) {
    int i = 0;
    while(var[i] != '\0') {
        var[i] = '\0';
        i++;
    }
}
