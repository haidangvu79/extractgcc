int main() {
  unsigned char x;
  unsigned char *p = &x;
  unsigned long long h = ( 1ull << 63 );
  //are the following free of undefined behaviour?
  unsigned char *q1 = p + h;
  unsigned char *q2 = q1 + h;
  *q2 = 1;
  printf("Addresses: p =%p  q1=%p\n",
         (void*)p,(void*)q1);
  printf("Addresses: q2=%p  h =0x%llx\n",
         (void*)q2,h);
  printf("x=0x%x  *p=0x%x  *q2=0x%x\n",x,*p,*q2);
}

