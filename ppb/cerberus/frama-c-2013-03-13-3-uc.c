int main(int c, char **v) {
  unsigned char j;
  unsigned char *p = &j;
  if (c==4) 
    j = 1; 
  else
    j *= 2;
  // does this have undefined behaviour for c != 4 ?
  printf("j:%u ",j);
  printf("c:%d\n",c);
}
