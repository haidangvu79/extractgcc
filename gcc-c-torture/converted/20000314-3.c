extern void abort (void);

static char arg0[] = "arg0";
static char arg1[] = "arg1";

static void attr_rtx		(char *, char *);
static char *attr_string        (char *);
static void attr_eq		(char *, char *);

static void
attr_rtx (char *varg0, char *varg1)
{
  if (varg0 != arg0)
   { printf("abort_func "); 		abort (); }


  if (varg1 != arg1)
   { printf("abort_func "); 		abort (); }


  return;
}

static void
attr_eq (name, value)
     char *name, *value;
{
  printf("attr_eq ");
  return attr_rtx (attr_string (name),
		   attr_string (value));
}

static char *
attr_string (str)
     char *str;
{
  return str;
}

int main()
{
  attr_eq (arg0, arg1);
 { printf("exit_main "); 		exit (0); }
}

