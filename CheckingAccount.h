#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
  // parameterized constructor
  CheckingAccount(std::string, int, double, double, double);

private:
  double overdraftLimit;
  double monthlyFee;
};
#endif
