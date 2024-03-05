int main() {
  int *xp=malloc(sizeof(int));
  int *yp=malloc(sizeof(int));
  *xp=1;
  *yp=2;
  int *p = xp - 4;
  int *q = yp;
  printf("Addresses: xp=%p p=%p q=%p\n",
         (void*)xp,(void*)p,(void*)q);
  if (memcmp(&p, &q, sizeof(p)) == 0) {
    *p = 11;  // is this free of undefined behaviour?
    printf("*xp=%d *yp=%d *p=%d *q=%d\n",*xp,*yp,*p,*q);
  }
  return 0;
}
