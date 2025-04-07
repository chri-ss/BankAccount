#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
class SavingsAccount : public BankAccount {
public:
  // parameterized constructor
  SavingsAccount(std::string, double, double, double, int, int);

  // prevent copying or moving of accounts
  SavingsAccount(const SavingsAccount &) = delete;
  SavingsAccount(SavingsAccount &&) = delete;
  SavingsAccount &operator=(const SavingsAccount &) = delete;
  SavingsAccount &operator=(const SavingsAccount &&) = delete;

  double withdraw(double) override;
  void display() noexcept override;
  void deposit(double) override;

  // applies simple interest to the account
  void applyInterest();

  // should be caled on first of every month
  void resetMonthlyWithdrawLimit();

private:
  double interestRate;
  double withdrawFee;
  int freeWithdrawlimit;
  int availableFreeWithdrawal;
};

SavingsAccount::SavingsAccount(std::string acctHldr, double bal, double intRate,
                               double wdFee, int freeWdLimit, int availFreeWd)
    : BankAccount(acctHldr, bal) {
  if (bal <= 0) {
    throw NegativeAmountException("Error, balance must be positive");
  }
  if (intRate <= 0) {
    throw NegativeAmountException("Error, negative interest rate");
  }
  if (wdFee <= 0) {
    throw NegativeAmountException("Error, negative withdrawal fee");
  }
  if (freeWdLimit <= 0) {
    throw NegativeAmountException("Error, negative withdrawal limit");
  }
  if (availFreeWd <= 0) {
    throw NegativeAmountException("Error, negative available withdrawal");
  }

  interestRate = intRate;
  withdrawFee = wdFee;
  freeWithdrawlimit = freeWdLimit;
  availableFreeWithdrawal = availFreeWd;
}

double SavingsAccount::withdraw(double amount) {
  balance -= amount;
  if (balance < 0) {
    balance += amount;
    throw InsufficientFundsException(
        "Error, insufficient funds for withdrawal");
  }

  if (freeWithdrawlimit >= availableFreeWithdrawal) {
    std::cout << "You have exceeded your available free " << freeWithdrawlimit
              << " withdrawals for the month. A fee of " << withdrawFee
              << " will be applied to your account." << std::endl;
    balance -= withdrawFee;
  }
  return amount;
}

void SavingsAccount::deposit(double amount) {
  if (amount < 0) {
    throw NegativeAmountException("Error, can't deposit a negative amount");
  }
  balance += amount;
}

void SavingsAccount::display() noexcept {
  std::cout << "Savings Account: " << getAccountNumber() << std::endl;
  std::cout << "Account Holder: " << getAccountHolder() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "Balance: " << getBalance()
            << std::endl;
}

void SavingsAccount::applyInterest() { balance += balance * interestRate; }

void SavingsAccount::resetMonthlyWithdrawLimit() {
  availableFreeWithdrawal = freeWithdrawlimit;
}
#endif
