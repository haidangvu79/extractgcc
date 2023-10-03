/* { dg-skip-if "small alignment" { pdp11-*-* } } */

struct s1
{
  int __attribute__ ((aligned (8))) a;
};

struct
{
  char c;
  struct s1 m;
} v;

int
main (void)
{
  if ((int)&v.m & 7)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

