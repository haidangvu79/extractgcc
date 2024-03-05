// Based on MITRE's CWE-588, demonstrative example 1
// https://cwe.mitre.org/data/definitions/588.html

struct foo {
  int i;
};

int main() {
  struct foo *foo = (struct foo *)main;
  foo->i = 2;
  return foo->i;
}
