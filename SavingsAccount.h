#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
class SavingsAccount : public BankAccount {
public:
  // parameterized constructor
  SavingsAccount(std::string, int, double, double, double, int, int);

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
#endif
