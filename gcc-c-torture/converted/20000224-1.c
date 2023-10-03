int loop_1 = 100;
int loop_2 = 7;
int flag = 0;

int test (void)
{
  printf("test ");
    int i;
    int counter  = 0;

    while (loop_1 > counter) {
        if (flag & 1) {
            for (i = 0; i < loop_2; i++) {
                counter++;
            }
        }
        flag++;
    }
    return 1;
}

int main()
{
    if (test () != 1)
     { printf("abort_main "); 		abort (); }

   { printf("exit_main "); 		exit (0); }
}

