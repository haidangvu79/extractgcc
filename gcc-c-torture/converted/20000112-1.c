#include <string.h>

static int
special_format (fmt)
     const char *fmt;
{
  printf("special_format ");
  return (strchr (fmt, '*') != 0
          || strchr (fmt, 'V') != 0
          || strchr (fmt, 'S') != 0
          || strchr (fmt, 'n') != 0);
}

main()
{
  if (special_format ("ee"))
   { printf("abort_main "); 		abort (); }
  if (!special_format ("*e"))
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

