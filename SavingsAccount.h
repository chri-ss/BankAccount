#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include <string>
class SavingsAccount : public BankAccount {
public:
  // parameterized constructor
  SavingsAccount(std::string, int, double, double, double, int, int);

  void applyInterest();
  void resetMonthlyWithdrawLimit();

private:
  double interestRate;
  double withdrawFee;
  int freeWithdrawlimit;
  int availableFreeWithdrawal;
};
#endif
