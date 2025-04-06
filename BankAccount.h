#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
class BankAccount {
public:
  BankAccount();
  BankAccount(std::string, int, double);
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
};
#endif
