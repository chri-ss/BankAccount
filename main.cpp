#include "BusinessAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <cctype>
#include <cstdlib>
#include <string>

BankAccount *createAccount();
bool validateName(const std::string &);
void getBankAccountInfo(std::string &, double &);
void getSavingsAccountInfo(double &, double &, int &, int &);
void getCheckingAccountInfo(double &, double &);
void getBusinessAccountInfo(int &, double &);

BankAccount *createAccount() {
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

  // clear newline from first cin
  std::cin.clear();
  std::cin.ignore(1000, '\n');

  BankAccount *account;

  // create the account
  std::string accountHldr;
  double bal;
  getBankAccountInfo(accountHldr, bal);

  switch (accountChoice) {
  case 1:
    // get info for savings account
    double interestRate;
    double withdrawFee;
    int freeWithdrawlimit;
    int availablefreeWithdraw;
    getSavingsAccountInfo(interestRate, withdrawFee, freeWithdrawlimit,
                          availablefreeWithdraw);
    break;
  case 2:
    //  get info for checking account
    double overdraftLimit;
    double monthlyFee;
    getCheckingAccountInfo(overdraftLimit, monthlyFee);
    break;
  case 3:
    // get info for business account
    int transactionLimit;
    double transactionFee;
    getBusinessAccountInfo(transactionLimit, transactionFee);
    break;
  default:
    break;
  }

  return account;
}

bool validateName(const std::string &str) {
  for (int i = 0; i < str.size(); ++i) {
    if (!isalpha(str[i]) && !isspace(str[i])) {
      return false;
    }
  }
  return true;
}

void getBankAccountInfo(std::string &acctHldr, double &bal) {
  do {
    std::cout << "Enter a name for the account" << std::endl;
    getline(std::cin, acctHldr);
    if (!validateName(acctHldr)) {
      std::cout << "Account holder name must be alphabetical characters "
                   "only. Please try again."
                << std::endl;
    }
  } while (!validateName(acctHldr));
  // account numbers handled by BankAccount base class

  do {
    std::cout << "Enter the starting balance for the account" << std::endl;
    std::cin >> bal;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
    if (bal <= 0) {
      std::cout << "balance must be a positive value. Please try again."
                << std::endl;
    }
  } while (bal <= 0);
}

int main() {
  SavingsAccount savings1("chris", 100, 0.05, 0.50, 10, 10);
  CheckingAccount checking1("Chris", 200, 1000.0, 15.00);
  BusinessAccount business1("Chris", 300, 6, 20.0);

  BankAccount *bPtr = &savings1;
  BankAccount *bPtr2 = &checking1;
  BankAccount *bPtr3 = &business1;

  bPtr->display();
  bPtr2->display();
  bPtr3->display();
  createAccount();
  return 0;
}
