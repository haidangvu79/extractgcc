int main() {
  void *p = malloc(sizeof(float)); assert (p != NULL);
  // is this free of undefined behaviour?
  float f = *((float *)p);
  printf("f=%f\n",f);
}
