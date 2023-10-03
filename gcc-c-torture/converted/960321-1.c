char a[10] = "deadbeef";

char
acc_a (long i)
{
  printf("acc_a ");
  return a[i-2000000000L];
}

main ()
{
  if (acc_a (2000000000L) != 'd')
   { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

