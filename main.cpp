#include "SavingsAccount.h"

int main() {
  SavingsAccount savings1("chris", 100, 0.50, 0.05, 0.50, 10, 10);

  BankAccount *bPtr = &savings1;

  bPtr->display();
  return 0;
}
