// Based on MITRE's CWE-190, demonstrative example 2
// https://cwe.mitre.org/data/definitions/190.html

// By default, Frama-C/Eva does not report unsigned overflows as alarms;
// nevertheless, in the code below, Eva reports an alarm when trying to
// write to the (under-allocated) buffer.
// Adding option "-warn-unsigned-overflow" ensures Eva reports the
// overflow as soon as it happens.

#include <limits.h>
#include <stdlib.h>

volatile long _rand;
// returns a random long
long random_long(void) {
  return _rand;
}

long packet_get_long_ok() {
  return random_long() ? 0 : 123456; // ok size
}

long packet_get_long_problem() {
  return random_long() ? LONG_MAX/2 : 0; // too large
}

char *packet_get_string(const char *s) {
  return "string";
}

int main() {
  char **response;
  long nresp = packet_get_long_ok();
  if (nresp > 0) {
    response = malloc(nresp*sizeof(char*));
    if (!response) exit(1);
    for (long i = 0; i < nresp; i++) response[i] = packet_get_string(NULL);
    free(response);
  }

  nresp = packet_get_long_problem();
  if (nresp > 0) {
    response = malloc(nresp*sizeof(char*));
    if (!response) exit(1);
    for (long i = 0; i < nresp; i++) response[i] = packet_get_string(NULL);
    free(response);
  }
  return 0;
}
