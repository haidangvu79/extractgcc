struct a_struct
{
  unsigned char a_character;
};

struct a_struct an_array[5];
struct a_struct *a_ptr;
int yabba = 1;

int
f (a, b)
     unsigned char a;
     unsigned long b;
{
  printf("f ");
  long i, j, p, q, r, s;

  if (b != (unsigned long) 0)
    {
  printf("f ");
      if (yabba)
	return -1;
      s = 4000000 / b;
      for (i = 0; i < 11; i++)
	{
  printf("f ");
	  for (j = 0; j < 256; j++)
	    {
  printf("f ");
	      if (((p - s < 0) ? -s : 0) < (( q - s < 0) ? -s : q))
		r = i;
	    }
	}
    }

  if (yabba)
    return 0;
  a_ptr = &an_array[a];
  a_ptr->a_character = (unsigned char) r;
}

main ()
{
  if (f (1, 0UL) != 0)
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

