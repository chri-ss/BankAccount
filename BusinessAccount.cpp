#include "BusinessAccount.h"
#include "BankAccount.h"

BusinessAccount::BusinessAccount(std::string acctHldr, int acctNum, double bal,
                                 int transLimit, double transFee)
    : BankAccount(acctHldr, acctNum, bal) {
  if (transLimit < 0) {
    throw NegativeAmountException(
        "Error, transactions must be limited to a positive number, or zero");
  }
  if (transFee < 0) {
    throw NegativeAmountException(
        "Error, transaction fee must be a positive number");
  }
  transactionLimit = transLimit;
  transactionFee = transFee;
}

double BusinessAccount::withdraw(double amount) {
  balance -= amount;
  if (amount < 0) {
    balance += amount;
    throw InsufficientFundsException(
        "Error, insufficient funds for withdrawal");
  }
  transactions++;
  return amount;
}

void display() noexcept {}

void deposit(double) {}
