#include "BusinessAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <cctype>
#include <cstdlib>
#include <string>

// To create specific kinds of bank account objects
BankAccount *createAccount();

// utilities for validating input
bool validateName(const std::string &);
void getBankAccountInfo(std::string &, double &);
void getSavingsAccountInfo(double &, double &, int &, int &);
void getCheckingAccountInfo(double &, double &);
void getBusinessAccountInfo(int &, double &);

// To validate numeric input gathered when creating an account
template <typename T>
void validateNumericInput(T &val, const std::string &displayStr);

int main() {
  BankAccount *account1 = createAccount();

  account1->display();

  return 0;
}

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
    account = new SavingsAccount(accountHldr, bal, interestRate, withdrawFee,
                                 freeWithdrawlimit, availablefreeWithdraw);
    break;
  case 2:
    //  get info for checking account
    double overdraftLimit;
    double monthlyFee;
    getCheckingAccountInfo(overdraftLimit, monthlyFee);
    account = new CheckingAccount(accountHldr, bal, overdraftLimit, monthlyFee);
    break;
  case 3:
    // get info for business account
    int transactionLimit;
    double transactionFee;
    getBusinessAccountInfo(transactionLimit, transactionFee);
    account =
        new BusinessAccount(accountHldr, bal, transactionLimit, transactionFee);
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

template <typename T>
void validateNumericInput(T &val, const std::string &displayStr) {
  do {
    std::cout << "Enter the " << displayStr << " for the account" << std::endl;
    std::cin >> val;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      val = -1;
    }
    if (val < 0) {
      std::cout << displayStr
                << " must be a positive value. "
                   "Please try again."
                << std::endl;
    }
  } while (val < 0);
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

  //  account numbers handled by BankAccount base class

  validateNumericInput(bal, "the starting balance");
}

void getSavingsAccountInfo(double &intRate, double &wdFee, int &freeWdLim,
                           int &availFreeWd) {
  validateNumericInput(intRate, "interest rate");
  validateNumericInput(wdFee, "withdrawal fee");
  validateNumericInput(freeWdLim, "free withdrawal limit");
  validateNumericInput(availFreeWd, "available free withdrawals per month");
}

void getCheckingAccountInfo(double &odLim, double &mFee) {
  validateNumericInput(odLim, "available overdraft limit");
  validateNumericInput(mFee, "monthly fee");
}

void getBusinessAccountInfo(int &transLim, double &transFee) {
  validateNumericInput(transLim, "transaction limit");
  validateNumericInput(transFee, "transaction fee");
}
