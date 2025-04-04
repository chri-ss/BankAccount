#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
class SavingsAccount : public BankAccount {
public:
  SavingsAccount(double intRate, double wdFee, int freeWdLimit, int availFreeWd)
      : BankAccount() {
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

private:
  double interestRate;
  double withdrawFee;
  int freeWithdrawlimit;
  int availableFreeWithdrawal;
};
#endif
