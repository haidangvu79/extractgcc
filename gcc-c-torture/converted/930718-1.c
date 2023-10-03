typedef struct rtx_def
{
  int f1 :1;
  int f2 :1;
} *rtx;

static rtx
f (orig)
     register rtx orig;
{
  printf("f ");
  if (orig->f1 || orig->f2)
    return orig;
  orig->f2 = 1;
  return orig;
}

void
f2 ()
{
  printf("f ");
 { printf("abort_func "); 		abort (); }

}

main ()
{
  struct rtx_def foo;
  rtx bar;

  foo.f1 = 1;
  foo.f2 = 0;
  bar = f (&foo);
  if (bar != &foo || bar->f2 != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

