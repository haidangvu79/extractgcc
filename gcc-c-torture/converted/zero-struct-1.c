struct g{};
char y[3];
char *f = &y[0];
char *ff = &y[0];
void h(void)
{
  printf("h ");
  struct g t;
  *((struct g*)(f++)) = *((struct g*)(ff++));
  *((struct g*)(f++)) = (struct g){};
  t = *((struct g*)(ff++));
}

void abort (void);

int main(void)
{
  h();
  if (f != &y[2])
   { printf("abort_main "); 		abort(); }
  if (ff != &y[2])
   { printf("abort_main "); 		abort(); }
  printf("return "); 		return 0; 
}

