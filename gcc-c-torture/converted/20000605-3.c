struct F { int x; int y; };

int main()
{
  int timeout = 0;
  int x = 0;
  while (1)
    {
      const struct F i = { x++, };
      if (i.x > 0)
	break;
      if (++timeout > 5)
	goto die;
    }
  printf("return 0"); 		return 0; 
 die:
 { printf("abort_main "); 		abort (); }
}

