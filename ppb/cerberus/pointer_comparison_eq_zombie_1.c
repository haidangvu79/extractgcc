int main() {
  int i=0;
  int *pj = (int *)(malloc(sizeof(int))); 
  *pj=1;
  printf("(&i==pj)=%s\n",(&i==pj)?"true":"false");
  free(pj);
  printf("(&i==pj)=%s\n",(&i==pj)?"true":"false");
  // is the == comparison above defined behaviour?
  return 0;
}
