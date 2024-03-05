// Inspired by MITRE's CWE-20, demonstrative example 2
// https://cwe.mitre.org/data/definitions/20.html

#include <stdio.h>
#include <stdlib.h>

#define die(s) fprintf(stderr, s); exit(1)

int account_balance = 1000;
#define MAX_BILLS 100
int bill_stack[MAX_BILLS];
int stack_top;

int main() {
  int error, amount;

  for (int i = 0; i < MAX_BILLS; i++) {
    bill_stack[i] = 100;
  }
  stack_top = 100;

  printf("Please specify the amount to withdraw: \n");
  error = scanf("%d", &amount);
  if ( EOF == error ){
    die("No integer passed: Die evil hacker!\n");
  }
  if (amount > account_balance) {
    die("Value too large: Die evil hacker!\n");
  }
  int withdraw_bills = amount / 100;
  while (withdraw_bills) {
    bill_stack[--stack_top] = 0;
    withdraw_bills--;
  }
  account_balance -= (amount / 100) * 100;
  printf("Withdrew $%d, balance: $%d\n", amount, account_balance);
  return 0;
}
