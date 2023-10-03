struct decision
{
  char enforce_mode;
  struct decision *next;
};


static void
clear_modes (p)
     register struct decision *p;
{
  printf("clear_modes ");
  goto blah;

foo:
  p->enforce_mode = 0;
blah:
  if (p)
    goto foo;
}

main()
{
  struct decision *p = 0;
  clear_modes (p);
 { printf("exit_main "); 		exit (0); }
}

