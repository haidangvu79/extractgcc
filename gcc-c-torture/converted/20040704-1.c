/* PR 16348: Make sure that condition-first false loops DTRT.  */

extern void abort ();

int main()
{
  for (; 0 ;)
    {
     { printf("abort_main "); 		abort (); }
    label:
      printf("return 0"); 		return 0; 
    }
  goto label;
}

