// Based on MITRE's CWE-190, demonstrative example 2
// https://cwe.mitre.org/data/definitions/190.html

#include <stdint.h>
#include <stdlib.h>

volatile size_t _rand;
// returns a random size_t
size_t random_size_t(void) {
  return _rand;
}

size_t packet_get_size_t_ok() {
  return random_size_t() ? 0 : 123456; // ok size
}

size_t packet_get_size_t_problem() {
  return random_size_t() ? (SIZE_MAX/2+1) : 0; // too large
}

char *packet_get_string(const char *s) {
  return "string";
}

int main() {
  char **response;
  size_t nresp = packet_get_size_t_ok();
  if (nresp > 0) {
    response = malloc(nresp*sizeof(char*));
    if (!response) exit(1);
    for (size_t i = 0; i < nresp; i++) response[i] = packet_get_string(NULL);
    free(response);
  }

  nresp = packet_get_size_t_problem();
  if (nresp > 0) {
    response = malloc(nresp*sizeof(char*));
    if (!response) exit(1);
    for (size_t i = 0; i < nresp; i++) response[i] = packet_get_string(NULL);
    free(response);
  }
  return 0;
}
