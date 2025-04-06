#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H
#include "BankAccount.h"

class BusinessAccount : public BankAccount {
public:
  BusinessAccount(std::string, int, double, int, double);

  double withdraw(double) override;
  void display() noexcept override;
  void deposit(double) override;

  void resetTransactionCount();

private:
  int transactionLimit;
  // chargded on additional withdrawals/deposits in excess of transactionLimit
  double transactonFee;
};

#endif
