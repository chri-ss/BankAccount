#include "BusinessAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <string>

BankAccount &createAccount() {
  // ask what type of account to make
  int accountChoice = 0;
  do {
    std::cout << "What type of bank account would you like to create?\n"
              << "1. Savings\n"
              << "2. Checking\n"
              << "3. Business\n"
              << std::endl;

    std::cin >> accountChoice;
    if (accountChoice < 1 || accountChoice > 3) {
      std::cout << "please choose a number between 1 and 3" << std::endl;
    }
  } while (accountChoice < 1 || accountChoice > 3);

  BankAccount *account;
  // create the account
  switch (accountChoice) {
  case 1:
    // get info for savings account
    break;
  case 2:
    // get info for checking account
    break;
  case 3:
    // get info for business account
    break;
  default:
    break;
  }
  return *account;
}

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
  createAccount();
  return 0;
}
