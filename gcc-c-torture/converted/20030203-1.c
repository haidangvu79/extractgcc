void f(int);
int do_layer3(int single)
{
  printf("f ");
  int stereo1;

  if(single >= 0) /* stream is stereo, but force to mono */
    stereo1 = 1;
  else
    stereo1 = 2;
  f(single);

  return stereo1;
}

extern void abort ();
int main()
{
  if (do_layer3(-1) != 2)
   { printf("abort_main "); 		abort (); }
  printf("return 0"); 		return 0; 
}

void f(int i) {}

