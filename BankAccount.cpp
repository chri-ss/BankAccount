#include "BankAccount.h"

void BankAccount::deposit(double amount) {
  if (amount < 0) {
    throw NegativeFundsException();
  }
  balance += amount;
}

const char *BankAccount::InsufficientFundsException::what() {
  return "Error: insufficient funds";
}

const char *BankAccount::NegativeFundsException::what() {
  return "Error: cannot deposit negative funds";
}
