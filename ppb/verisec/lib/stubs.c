#include "stubs.h"

#ifdef __FRAMAC__
// These signatures and redefinitions are incompatible with Frama-C's libc
#error "This file is incompatible with Frama-C's libc"
#else
static volatile char nd_char;
static volatile int nd_int;
static volatile long nd_long;
static volatile unsigned char nd_uchar;
static volatile short nd_short;

char nondet_char(void) {
  return nd_char;
}

int nondet_int(void) {
  return nd_int;
}

long nondet_long(void) {
  return nd_long;
}

unsigned char nondet_unsigned_char(void) {
  return nd_uchar;
}

short nondet_short(void){
  return nd_short;
}
#endif

/*
 * KK: I think SatAbs/CBMC front-end complains about this, but the backend
 * knows what it means.
 */
/* extern int nondet_int(); */

/****************************************************************************
 *
 * Begin duplicate relevant functions.
 *
 ***************************************************************************/

char *r_strcat(char *dest, const char *src)
{
  int i, j;
  char tmp;
  i = 0; j = 0;
  while (dest[i] != EOS)
    i++;
  do {
    tmp = src[j];
    /* replace this line.... */
    dest[i] = tmp;
    i++; j++;
  } while (src[j] != EOS);

  /* strcat man page says that strcat null-terminates dest */
  /* r_strcat RELEVANT */
  dest[i] = EOS;

  return dest;
}

char *r_strncat(char *dest, const char *src, size_t n)
{
  int i, j;
  char tmp;
  i = 0; j = 0;
  while (dest[i] != EOS)
    i++;
  do {
    if (j >= n) break;
    tmp = src[j];
    /* replace this line.... */
    dest[i] = tmp;
    i++; j++;
  } while (src[j] != EOS);

  /* strncat man page says that strcat null-terminates dest */
  /* r_strncat RELEVANT */
  dest[i] = EOS;

  return dest;
}

/* We do the copy backwards in order to trip upper bounds assertion
 * failures more quickly. */
void *r_memcpy(void *dest, const void *src, size_t n)
{
  int i;

  /*@ assert \valid((char *)dest+(n-1)); */
  /* dest[n-1]; */

  for (i = n-1; i >= 0; i--) {
    ((char *) dest)[i] = ((char *) src)[i];
  }
  return dest;
}

char *r_strncpy (char *dest, const char *src, size_t n)
{
  int _i;

  /* r_strncpy RELEVANT */
  dest[n];

  for (_i = 0; _i < n; _i++) {
    dest[_i] = src[_i]; // DO NOT CHANGE THE POSITION OF THIS LINE
    if (src[_i] == EOS)
      break;
  }
  return dest;
}

char *r_strcpy (char *dest, const char *src)
{
  int i;
  char tmp;
  for (i = 0; ; i++) {
    tmp = src[i];
    /* r_strcpy RELEVANT */
    dest[i] = tmp; // DO NOT CHANGE THE POSITION OF THIS LINE
    if (src[i] == EOS)
      break;
  }
  return dest;
}

/****************************************************************************
 *
 * End duplicate relevant functions.
 *
 ***************************************************************************/

#ifndef __OSCS__

char *strcat(char *dest, const char *src)
{
  int i, j;
  char tmp;
  i = 0; j = 0;
  while (dest[i] != EOS)
    i++;
  do {
    tmp = src[j];
    dest[i] = tmp;
    i++; j++;
  } while (src[j] != EOS);

  /* strcat man page says that strcat null-terminates dest */
  dest[i] = EOS;

  return dest;
}

/* We do the copy backwards in order to trip upper bounds assertion
 * failures more quickly. */
void *memcpy(void *dest, const void *src, size_t n)
{
  int i;
  for (i = n-1; i >= 0; i--) {
    /* I can't find a way to use a temporary here. :-/ */
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

char *strchr(const char *s, int c)
{
  int i;
  for (i = 0; s[i] != EOS; i++)
    if (s[i] == c)
      return &s[i];

  return (c == EOS) ? &s[i] : NULL;
}


char *strrchr(const char *s, int c)
{
  char *ret = NULL;
  int i;

  for (i = 0; s[i] != EOS; i++)
    if (s[i] == c)
      ret = &s[i];

  if (c == EOS)
    return &s[i];

  return ret;
}

char *strncpy (char *dest, const char *src, size_t n)
{
  int _i;
  char tmp;
  for (_i = 0; _i < n; _i++) {
    tmp = src[_i];
    dest[_i] = tmp;
    if (src[_i] == EOS)
      break;
  }
  return dest;
}

char *strncpy_ptr (char *dest, const char *src, size_t n)
{
  char *p, *q;
  p = dest;
  q = src;
  for (; q - src < n; q++, p++) {
    *p = *q;
    if (*p == 0)
      break;
  }
  return dest;
}

char *strcpy (char *dest, char *src)
{
  int i;
  char tmp;
  for (i = 0; ; i++) {
    tmp = src[i];
    dest[i] = tmp;
    if (src[i] == EOS)
      break;
  }
  return dest;
}

/* Version of strstr written for analyzability rather than performance.
 *
 * In this version, EVERYTHING is inlined. This seems to aid
 * analyzability considerably.
 */
char *strstr(const char *haystack, const char *needle)
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
      return &haystack[i];
  }

  return NULL;
}

unsigned strlen(char *s)
{
  int i;
  i = 0;
  while (s[i] != EOS)
    ++i;
  return i;
}

int strncmp (const char *s1, const char *s2, size_t n)
{
  int i;
  int retval;
  i = 0;
  do {
    retval = s1[i] - s2[i];
    if (i >= n-1) return retval;
    if (retval != 0) return retval;
    if (s1[i] == EOS) return 0;
    i++;
  } while (1);
}

int strcmp (const char *s1, const char *s2)
{
  int i;
  for (i = 0; s1[i] == s2[i]; i++)
    if (s1[i] == EOS)
      return 0;
  return s1[i] - s2[i];
}

/*
 * getc which returns EOF within MAX_GETC calls if preprocessor macro CBMC is
 * defined.
 */
int getc ()
{
#ifdef CBMC
  static int getc_count = 0;
  if (getc_count++ < MAX_GETC)
  {
    if (nondet_int ())
      return (int) nondet_unsigned_char ();

    return EOF;
  }
  else
  {
    getc_count = 0;
    return EOF;
  }
#else
  return nondet_int ();
#endif
}

int isascii (int c)
{
  return ('!' <= c && c <= '~');
}

int isspace (int c)
{
  return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
      || c == ' ');
}

#endif //ifndef __OSCS__

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

#ifdef __OSCS__
  return -1;
#else
  return NULL;
#endif
}

struct modem;
int put_command( struct modem *mdm, char* command, int clen, char* answer,
                 int max, int timeout,char* expect) {
  strcpy(answer,"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\
ABCDEF+CMGR:");
  return 0;
}

#ifdef __OSCS__

// Function used by crackaddr
void printbuf(const char *buf, size_t size) {
  for (size_t i = 0; i < size; i++) {
    putchar(buf[i]);
  }
}

// Functions used by realpath-linkpath

//void delay_signaling(void) {}
//void enable_signaling(void) {}
void disable_signaling(void) {}

#endif //ifdef __OSCS__
