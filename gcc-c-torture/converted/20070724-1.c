void abort (void);

static unsigned char magic[] = "\235";
static unsigned char value = '\235';

int main()
{
  if (value != magic[0])
   { printf("abort_main "); 		abort (); }
  printf("return "); 		return 0; 
}

