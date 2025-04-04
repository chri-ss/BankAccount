#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <exception>
#include <string>
class BankAccount {
public:
  virtual double withdraw() = 0;
  virtual void deposit(double);
  virtual void display();

  class InsufficientFundsException : public std::exception {
  public:
    InsufficientFundsException(std::string error) { errMsg = error; }
    const char *what();

  private:
    std::string errMsg;
  };

  class NegativeAmountException : public std::exception {
  public:
    NegativeAmountException(std::string error) { errMsg = error; }
    const char *what();

  private:
    std::string errMsg;
  };

private:
  std::string accountHolder;
  int accountNumber;
  double balance;
};
#endif
