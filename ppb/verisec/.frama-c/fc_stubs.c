#include "stubs.h"

// Copied from lib/stubs.c, since these functions are not in
// Frama-C's libc

/*****************************************************************
 *
 * Functions which are like the functions in libc, but return indexes
 * into arrays rather than pointers into arrays. -1 becomes the
 * stand-in for NULL, which is hashish and evil in general.
 *
 ****************************************************************/

char *strrand (char *s)
{
  int i;
  for (i = 0; s[i] != EOS; i++)
    if (nondet_int () == 1)
      return &s[i];

  return NULL;
}

int istrrand (char *s)
{
  int i;
  for (i = 0; s[i] != EOS; i++)
    if (nondet_int () == 1)
      return i;

  return -1;
}

int istrchr(const char *s, int c)
{
  int i;
  for (i = 0; s[i] != EOS; i++)
    if (s[i] == c)
      return i;

  return (c == EOS) ? i : -1;
}

int istrrchr(const char *s, int c)
{
  int ret = -1;
  int i;

  for (i = 0; s[i] != EOS; i++)
    if (s[i] == c)
      ret = i;

  if (c == EOS)
    return i;

  return ret;
}

int istrncmp (const char *s1, int start, const char *s2, size_t n)
{
  int i;
  int end = start + (n-1);

  for (i = start; i < end; i++) {
    if (s1[i] == EOS) return 0;
    if (s1[i] - s2[i] != 0) return s1[i] - s2[i];
  }

  assert (i == end); //KK: what's this here for?
  return s1[end] - s2[end];
}

int istrstr(const char *haystack, const char *needle)
{
  int len;
  int i;
  int j;

  len = 0;
  while (needle[len] != EOS) len++;

  for (i = 0; haystack[i] != EOS; i++) {
    for (j = 0; j < len-1; j++) {
      if (haystack[i+j] == EOS) break;
      if (haystack[i+j] != needle[j]) break;
    }
    if (j == len-1 &&
        haystack[i+len-1] == needle[len-1])
      return i;
  }

  // Note: the original code returned NULL instead of -1; likely a typo
  return -1;
}
