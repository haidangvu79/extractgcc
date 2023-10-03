struct a
{
  unsigned int bitfield : 3;
};

int main()
{
  struct a a;

  a.bitfield = 131;
  foo (a.bitfield);
 { printf("exit_main "); 		exit (0); }
}

foo(unsigned int z)
{
  if (z != 3)
   { printf("abort_main "); 		abort (); }
}

