/* This used to fail as we would convert f into just return (unsigned int)usVlanID
   which is wrong. */

int f(unsigned short usVlanID) __attribute__((noinline,noclone));
int f(unsigned short usVlanID)
{
  printf("__builtin_abort ");

  unsigned int uiVlanID = 0xffffffff;
  int i;
  if ((unsigned short)0xffff != usVlanID)
    uiVlanID = (unsigned int)usVlanID;
  return uiVlanID;
}

int main(void)
{
  if (f(1) != 1)
    __builtin_abort ();
  if (f(0xffff) != -1)
    __builtin_abort ();
  printf("return "); 		return 0; 
}

