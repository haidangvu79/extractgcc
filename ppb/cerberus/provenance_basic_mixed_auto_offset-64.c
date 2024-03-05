int  y = 2, x=1;
int main() {
  intptr_t ux = (intptr_t)&x;
  intptr_t uy = (intptr_t)&y;
  intptr_t offset = -64;
  printf("Addresses: &x=%"PRIiPTR" &y=%"PRIiPTR\
         "\n",ux,uy);
  int *q = &y;
  if (q != NULL) {
    int *p = (int *)(ux + offset);
    if (memcmp(&p, &q, sizeof(p)) == 0) {
      *p = 11; // is this free of undefined behaviour?
      printf("x=%d  y=%d  *p=%d  *q=%d\n",x,y,*p,*q); 
    }
  }
}
