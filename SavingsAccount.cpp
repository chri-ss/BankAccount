#include "SavingsAccount.h"
#include <iomanip>
#include <ios>
#include <iostream>

SavingsAccount::SavingsAccount(std::string acctHldr, int acctNum, double bal,
                               double intRate, double wdFee, int freeWdLimit,
                               int availFreeWd)
    : BankAccount(acctHldr, acctNum, bal) {
  if (intRate <= 0) {
    throw NegativeAmountException("Error, negative interest rate");
  }
  if (wdFee <= 0) {
    throw NegativeAmountException("Error, negative withdrawal fee");
  }
  if (freeWdLimit <= 0) {
    throw NegativeAmountException("Error, negative withdrawal limit");
  }
  if (availFreeWd <= 0) {
    throw NegativeAmountException("Error, negative available withdrawal");
  }

  interestRate = intRate;
  withdrawFee = wdFee;
  freeWithdrawlimit = freeWdLimit;
  availableFreeWithdrawal = availFreeWd;
}

void SavingsAccount::applyInterest() { balance += balance * interestRate; }

void SavingsAccount::resetMonthlyWithdrawLimit() {
  availableFreeWithdrawal = freeWithdrawlimit;
}

void SavingsAccount::display() noexcept {
  std::cout << "Savings Account: " << getAccountNumber() << std::endl;
  std::cout << "Account Holder: " << getAccountHolder() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "Balance: " << getBalance()
            << std::endl;
}

void SavingsAccount::deposit(double amount) {
  if (amount < 0) {
    throw NegativeAmountException("Error, can't deposit a negative amount");
  }
  balance += amount;
}

double SavingsAccount::withdraw(double amount) { return amount; }
