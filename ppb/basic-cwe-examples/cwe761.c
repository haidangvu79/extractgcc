// Based on MITRE's CWE-761, demonstrative example 1
// https://cwe.mitre.org/data/definitions/761.html

#include <stdlib.h>
#include <string.h>

#ifdef FC_EVA_PRECISE
// Inclusion of Frama-C's libc 'string.c' improves precision of the analysis
// during call to strcpy()
#include "string.c"
#endif

#define SUCCESS (1)
#define FAILURE (0)

int contains_char(char c) {
  char *str;
  str = malloc(20*sizeof(char));
  if (!str) return FAILURE;
  strcpy(str, "Search Me!");
  while(*str != '\0') {
    if( *str == c ){
      /* matched char, free string and return success */
      free(str);
      return SUCCESS;
    }
    /* didn't match yet, increment pointer and try next char */
    str = str + 1;
  }
  /* we did not match the char in the string, free mem and return failure */

  free(str);
  return FAILURE;
}

int main() {
  return contains_char('e');
}
