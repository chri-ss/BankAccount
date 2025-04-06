#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
  // parameterized constructor
  CheckingAccount(std::string, int, double, double, double);

  double withdraw(double) override;
  void display() noexcept override;
  void deposit(double) override;

  void chargeMonthlyFee();

  double getOverdraftLimit() const;

private:
  double overdraftLimit;
  double monthlyFee;
};

CheckingAccount::CheckingAccount(std::string acctHldr, int acctNum, double bal,
                                 double odLim, double mFee)
    : BankAccount(acctHldr, acctNum, bal) {
  if (bal <= 0) {
    throw NegativeAmountException("Error, balance must be positive");
  }
  if (odLim <= 0) {
    throw NegativeAmountException("Error, overdraft must be positive");
  }
  if (mFee <= 0) {
    throw NegativeAmountException("Error, monthly fee must be positive");
  }

  overdraftLimit = odLim;
  monthlyFee = mFee;
}
double CheckingAccount::withdraw(double amount) {
  balance -= amount;
  if (balance < overdraftLimit) {
    balance += monthlyFee;
    throw InsufficientFundsException(
        "Error, insufficient funds for withdrawal");
  }
  return amount;
}

void CheckingAccount::display() noexcept {
  std::cout << "Checking Account: " << getAccountNumber() << std::endl;
  std::cout << "Account Holder: " << getAccountHolder() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "Balance: " << getBalance()
            << std::endl;
  std::cout << "Overdraft limit: " << getOverdraftLimit() << std::endl;
}

void CheckingAccount::deposit(double amount) {
  if (amount < 0) {
    throw NegativeAmountException("Error, can't deposit a negative amount");
  }
  balance += amount;
}

void CheckingAccount::chargeMonthlyFee() {
  balance -= monthlyFee;
  if (balance < overdraftLimit) {
    balance += monthlyFee;
    throw InsufficientFundsException(
        "Error, insufficient funds for monthly fee");
  }
}

double CheckingAccount::getOverdraftLimit() const { return overdraftLimit; }
#endif
