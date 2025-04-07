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
    //    getCheckingAccountInfo(overdraftLimit, monthlyFee);
    break;
  case 3:
    // get info for business account
    int transactionLimit;
    double transactionFee;
    //   getBusinessAccountInfo(transactionLimit, transactionFee);
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
      bal = -1;
    }
    if (bal <= 0) {
      std::cout << "balance must be a positive value. Please try again."
                << std::endl;
    }
  } while (bal <= 0);
}

void getSavingsAccountInfo(double &intRate, double &wdFee, int &freeWdLim,
                           int &availFreeWd) {
  do {
    std::cout << "Enter the interest rate for the account" << std::endl;
    std::cin >> intRate;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      intRate = -1;
    }
    if (intRate < 0) {
      std::cout << "interest rate must be a positive value. Please try again."
                << std::endl;
    }
  } while (intRate < 0);
  do {
    std::cout << "Enter the withdrawal fee for the account" << std::endl;
    std::cin >> wdFee;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      wdFee = -1;
    }
    if (wdFee < 0) {
      std::cout << "withdrawal fee must be a positive value. Please try again."
                << std::endl;
    }
  } while (wdFee < 0);
  do {
    std::cout << "Enter the free withdrawal limit for the account" << std::endl;
    std::cin >> freeWdLim;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      freeWdLim = -1;
    }
    if (freeWdLim < 0) {
      std::cout
          << "free withdrawal limit must be a positive value. Please try again."
          << std::endl;
    }
  } while (freeWdLim < 0);
  do {
    std::cout
        << "Enter the available free withdrawals per month for the account"
        << std::endl;
    std::cin >> availFreeWd;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      availFreeWd = -1;
    }
    if (availFreeWd < 0) {
      std::cout << "available free withdrawals must be a positive value. "
                   "Please try again."
                << std::endl;
    }
  } while (availFreeWd < 0);
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
