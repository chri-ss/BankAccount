#include "BankAccount.h"

void BankAccount::deposit(double amount) {
  if (amount < 0) {
    throw NegativeAmountException("Error, can't deposit a negative amount");
  }
  balance += amount;
}

const char *BankAccount ::InsufficientFundsException::what() {
  return errMsg.c_str();
}

const char *BankAccount::NegativeAmountException::what() {
  return errMsg.c_str();
}
