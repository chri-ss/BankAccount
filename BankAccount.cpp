#include "BankAccount.h"

BankAccount::BankAccount()
    : accountHolder(""), accountNumber(0), balance(0.0) {}

BankAccount::BankAccount(std::string acctHldr, int acctNum, double bal)
    : accountHolder(acctHldr), accountNumber(acctNum), balance(bal) {}

BankAccount::~BankAccount() {}

BankAccount::InsufficientFundsException::InsufficientFundsException(
    std::string error) {
  errMsg = error;
}
BankAccount::NegativeAmountException::NegativeAmountException(
    std::string error) {
  errMsg = error;
}

const char *BankAccount ::InsufficientFundsException::what() {
  return errMsg.c_str();
}

const char *BankAccount::NegativeAmountException::what() {
  return errMsg.c_str();
}

void BankAccount::deposit(double) {}
void BankAccount::display() noexcept {}
