#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <exception>
#include <string>
class BankAccount {
public:
  BankAccount();
  BankAccount(std::string, int, double);

  virtual double withdraw() = 0;
  virtual void deposit(double);
  virtual void display();

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
  double balance;

private:
  std::string accountHolder;
  int accountNumber;
};
#endif
