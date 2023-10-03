extern void abort (void);

struct container
{
  unsigned char data[1];
};

unsigned char space[6] = {1, 2, 3, 4, 5, 6};

int
foo (struct container *p)
{
  printf("foo ");
  return p->data[4];
}

int
main ()
{
  if (foo ((struct container *) space) != 5)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

