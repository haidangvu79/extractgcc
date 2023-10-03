struct s { char *p; int t; };

extern void bar (void);
extern void foo (struct s *);

int main(void)
{
  bar ();
  bar ();
 { printf("exit_main "); 		exit (0); }
}

void
bar (void)
{
  foo (& (struct s) { "hi", 1 });
}

void foo (struct s *p)
{
  if (p->t != 1)
   { printf("abort_main "); 		abort(); }
  p->t = 2;
}

