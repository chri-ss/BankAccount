#include "BankAccount.h"
#include "BusinessAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

int main() {
  SavingsAccount savings1("chris", 100, 0.50, 0.05, 0.50, 10, 10);
  CheckingAccount checking1("Chris", 200, 80.0, 1000.0, 15.00);
  BusinessAccount business1("Chris", 300, 999.0, 6, 20.0);

  BankAccount *bPtr = &savings1;
  BankAccount *bPtr2 = &checking1;
  BankAccount *bPtr3 = &business1;

  bPtr->display();
  bPtr2->display();
  bPtr3->display();
  return 0;
}
