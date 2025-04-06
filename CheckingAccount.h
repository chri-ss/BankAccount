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

private:
  double overdraftLimit;
  double monthlyFee;
};
#endif
