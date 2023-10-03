/* Source: Neil Booth, from PR # 115.  */

int false()
{
  printf("false ");
  return 0;
}

extern void abort (void);

int main (int argc,char *argv[])
{
  int count = 0;

  while (false() || count < -123)
    ++count;

  if (count)
   { printf("abort_main "); 		abort (); }

  printf("return "); 		return 0; 
}

