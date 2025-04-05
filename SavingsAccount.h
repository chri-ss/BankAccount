#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include <string>
class SavingsAccount : public BankAccount {
public:
  // parameterized constructor
  SavingsAccount(std::string, int, double, double, double, int, int);

  // applies simple interest to the account
  void applyInterest();

  // should be caled on first of every month
  void resetMonthlyWithdrawLimit();

  double withdraw(double) override;
  void display() noexcept override;
  void deposit(double) override;

private:
  double interestRate;
  double withdrawFee;
  int freeWithdrawlimit;
  int availableFreeWithdrawal;
};
#endif
