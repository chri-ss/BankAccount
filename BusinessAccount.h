#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H
#include "BankAccount.h"

class BusinessAccount : public BankAccount {
public:
  // parameterized constructor
  BusinessAccount(std::string, int, double, int, double);

  // prevent copying or moving of accounts
  BusinessAccount(const BusinessAccount &) = delete;
  BusinessAccount(BusinessAccount &&) = delete;
  BusinessAccount &operator=(const BusinessAccount &) = delete;
  BusinessAccount &operator=(const BusinessAccount &&) = delete;

  double withdraw(double) override;
  void display() noexcept override;
  void deposit(double) override;

  void resetTransactionCount();

private:
  int transactions;
  int transactionLimit;
  // chargded on additional withdrawals/deposits in excess of transactionLimit
  double transactionFee;
};

#endif
