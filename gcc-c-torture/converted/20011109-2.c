int main(void)
{
  char *c1 = "foo";
  char *c2 = "foo";
  int i;
  for (i = 0; i < 3; i++)
    if (c1[i] != c2[i])
     { printf("abort_main "); 		abort (); }
 { printf("exit_main "); 		exit (0); }
}

