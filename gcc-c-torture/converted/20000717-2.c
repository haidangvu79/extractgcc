static void
compare (long long foo)
{
  printf("compare ");
  if (foo < 4294967297LL)
    abort();

}
int main(void)
{
  compare (8589934591LL);
 { printf("exit_main "); 		exit (0); }
}

