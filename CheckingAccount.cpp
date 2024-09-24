// Implementation of the class CheckingAccount.
#include <iostream>
#include <cmath>
#include "CheckingAccount.h"

using namespace std;

// To Do: include necessary header files

// To Do: Please write comments and code to implement CheckingAccount here

// 3 parameter constructor
// Precondition: takes in dollars, cents, and fee.
// Postcondition: Initializes the account balance to $dollars.cents and the check fee to fee.
CheckingAccount::CheckingAccount(int dollars, int cents, double fee) : BankAccount(dollars, cents), check_fee(fee) {
if (fee < 0) {
cout << "Illegal values for check fee.\n";
exit(1); // throw exception;
}
}

// 2 parameter constructor
// Precondition: takes in dollars and fee.
// Postcondition: Initializes the account balance to $dollars.00 and the check fee to the fee.
CheckingAccount::CheckingAccount(int dollars, double fee) : BankAccount(dollars), check_fee(fee) {
if (fee < 0) {
cout << "Illegal values for check fee.\n";
exit(1); // throw exception;
}
}

// default constructor
// Goal: Initializes the account balance to $0.00 and the check fee to $0.00.
CheckingAccount::CheckingAccount() : BankAccount(), check_fee(0.0) {
//leave empty
}

// an accessor for the check fee
// Returns the check fee.
double CheckingAccount::getCheck_fee() {
return check_fee;
}

// output the check fee
void CheckingAccount::output(ostream& outs) {
BankAccount::output(outs);
outs << "Check fee: $" << getCheck_fee() << endl;
}

// input the balance from BankAccount
void CheckingAccount::input(istream& ins) {
BankAccount::input(ins);
ins >> check_fee;
}

// Precondition: dollars and cents must be greater than or equal to 0 and check fee.
// Dollars and cents must be less than or equal to balance.
// Postcondition: increase the balance by the dollars and cents and check fee.
void CheckingAccount::check(int dollars, int cents, double check_fee, double balance) {
double amount = dollars + .01*cents + check_fee;
if (dollars >= 0 && cents >= 0 && amount <= get_balance()) {
balance -= amount;
set_balance(balance);
}
else {
cout << "Illegal values for money must be greater than or equal 0 ";
cout << "and less than or equal to the balance.\n";
}
}






