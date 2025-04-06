#include "CheckingAccount.h"
#include "BankAccount.h"
#include <string>

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
