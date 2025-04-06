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
  transactions = transactionLimit;
  transactionFee = transFee;
}

double BusinessAccount::withdraw(double amount) {
  balance -= amount;
  if (amount < 0) {
    balance += amount;
    throw InsufficientFundsException(
        "Error, insufficient funds for withdrawal");
  }
  transactions--;
  return amount;
}

void BusinessAccount::display() noexcept {
  std::cout << "Business Account: " << getAccountNumber() << std::endl;
  std::cout << "Account Holder: " << getAccountHolder() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << "Balance: " << getBalance()
            << std::endl;
  std::cout << "Transation limit: " << transactionLimit << std::endl;
  std::cout << "Transations this month: " << transactionLimit - transactions
            << std::endl;
}

void BusinessAccount::deposit(double amount) {
  if (transactions < 0) {
    std::cout << "You have exceeded your available free " << transactionLimit
              << " transactions for the month. A fee of " << transactionFee
              << " will be applied to your account." << std::endl;
    balance -= transactionFee;
  }
  balance += amount;
  transactions--;
}

// called at beginning of every month
void BusinessAccount::resetTransactionCount() {
  transactions = transactionLimit;
}
