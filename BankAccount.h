#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
class BankAccount {
public:
  BankAccount();
  BankAccount(std::string, double);
  virtual ~BankAccount();

  virtual double withdraw(double) = 0;
  virtual void deposit(double);
  virtual void display() noexcept;

  class InsufficientFundsException : public std::exception {
  public:
    InsufficientFundsException(std::string);
    const char *what();

  private:
    std::string errMsg;
  };

  class NegativeAmountException : public std::exception {
  public:
    NegativeAmountException(std::string);
    const char *what();

  private:
    std::string errMsg;
  };

protected:
  std::string getAccountHolder() const { return accountHolder; }
  int getAccountNumber() const { return accountNumber; }
  int getBalance() const { return balance; }
  double balance;

private:
  std::string accountHolder;
  int accountNumber;
  static int accountCounter;
};

BankAccount::BankAccount()
    : accountHolder(""), accountNumber(0), balance(0.0) {}

BankAccount::BankAccount(std::string acctHldr, double bal)
    : accountHolder(acctHldr), accountNumber(++accountCounter), balance(bal) {}

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

int BankAccount::accountCounter = 0;

#endif
