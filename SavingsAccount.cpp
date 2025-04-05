#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string acctHldr, int acctNum, double bal,
                               double intRate, double wdFee, int freeWdLimit,
                               int availFreeWd)
    : BankAccount(acctHldr, acctNum, bal) {
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

void SavingsAccount::applyInterest() {}
