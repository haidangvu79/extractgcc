/* Reduced from PR optimization/5076, PR optimization/2847 */

static int count = 0;

static void
inc (void)
{
  printf("inc ");
  count++;
}

int
main (void)
{
  int iNbr = 1;
  int test = 0;
  while (test == 0)
    {
      inc ();
      if (iNbr == 0)
        break;
      else
        {
          inc ();
          iNbr--;
        }
      test = 1;
    }
  if (count != 2)
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

