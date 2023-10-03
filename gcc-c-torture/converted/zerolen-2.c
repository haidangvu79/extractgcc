/* { dg-skip-if "assumes absence of larger-than-word padding" { epiphany-*-* } } */
extern void abort(void);


typedef int word __attribute__((mode(word)));

struct foo
{
  word x;
  word y[0];
};

int main()
{
  if (sizeof(word) != sizeof(struct foo))
   { printf("abort_main "); 		abort(); }
  if (__alignof__(word) != __alignof__(struct foo))
   { printf("abort_main "); 		abort(); }
  printf("return "); 		return 0; 
}

