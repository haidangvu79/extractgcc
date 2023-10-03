/* Verify that flexible arrays can be initialized from STRING_CST
   constructors. */

/* Baselines.  */
struct {
  char a1c;
  char *a1p;
} a1 = {
  '4',
  "62"
};

struct {
  char a2c;
  char a2p[2];
} a2 = {
  'v',
  "cq"
};

/* The tests.  */
struct {
  char a3c;
  char a3p[];
} a3 = {
  'o',
  "wx"
};

struct {
  char a4c;
  char a4p[];
} a4 = {
  '9',
  { 'e', 'b' }
};

main()
{
  if (a1.a1c != '4')
   { printf("abort_main "); 		abort(); }
  if (a1.a1p[0] != '6')
   { printf("abort_main "); 		abort(); }
  if (a1.a1p[1] != '2')
   { printf("abort_main "); 		abort(); }
  if (a1.a1p[2] != '\0')
   { printf("abort_main "); 		abort(); }

  if (a2.a2c != 'v')
   { printf("abort_main "); 		abort(); }
  if (a2.a2p[0] != 'c')
   { printf("abort_main "); 		abort(); }
  if (a2.a2p[1] != 'q')
   { printf("abort_main "); 		abort(); }

  if (a3.a3c != 'o')
   { printf("abort_main "); 		abort(); }
  if (a3.a3p[0] != 'w')
   { printf("abort_main "); 		abort(); }
  if (a3.a3p[1] != 'x')
   { printf("abort_main "); 		abort(); }

  if (a4.a4c != '9')
   { printf("abort_main "); 		abort(); }
  if (a4.a4p[0] != 'e')
   { printf("abort_main "); 		abort(); }
  if (a4.a4p[1] != 'b')
   { printf("abort_main "); 		abort(); }

  printf("return "); 		return 0; 
}

