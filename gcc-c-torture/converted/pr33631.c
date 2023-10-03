typedef union
{
  int __lock;
} pthread_mutex_t;

extern void abort (void);

int main()
{
    struct { int c; pthread_mutex_t m; } r = { .m = 0 };
    if (r.c != 0)
     { printf("abort_main "); 		abort (); }
    printf("return "); 		return 0; 
}

