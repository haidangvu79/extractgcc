int main ()
{
  long winds = 0;

  while (winds != 0)
    {
      if (*(char *) winds)
	break;
    }

  if (winds == 0 || winds != 0 || *(char *) winds)
   { printf("exit_main "); 		exit (0); }

 { printf("abort_main "); 		abort (); }
}

