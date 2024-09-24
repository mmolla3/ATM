#include <iostream>
#include <string>
#include <math.h>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"

// To Do: Include the appropriate header files

using namespace std;

void getTransaction(char &transact, double& amount, char &fromAcct);
// @param: transact is the requested transaction (eg. B,C,D,T,W,Q)
// @param: amount is the amount to transact
// @param: from is the requested account ('C'hecking or 'S'aving)
// @returns the parameters are references, all are returned.

string getTransactionString(char transat);
// @param: transact is the character to convert to string
// @returns the matching string (checks first char) or ""

int main() {
// To Do: Declare a SavingAccount and a CheckingAccount object
char transact, fromAcct;
double amount;
int dollars=0, cents=0;
SavingAccount savingAccount;
CheckingAccount checkingAccount;
cout << "Update the account info for Checking (balanace and fee): ";
// To Do: Call your input function for the CheckingAccount
checkingAccount.input(cin);

cout << "Update the account info for Saving (balanace and rate): ";
// To Do: Call your input function for the SavingAccount
savingAccount.input(cin);

cout << "\n\n*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-\n";
cout << "***** Welcome to the ATM 2000!!\n";
cout << "\n*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-\n";
cout << "Looks like you accrued some interest in your Savings.\n";

// To Do: Call your update function for the SavingAccount
savingAccount.update();

do {
    getTransaction(transact, amount, fromAcct);
    cout << "\n*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-\n";
    // To Do: take apart the amount into dollars and cents
dollars = floor(amount);
cents = (amount - dollars)*100;

// To Do: Use the values returned from getTransaction to implement the ATN
// if transact contains
// 'B' - call your output function on fromAcct ('C'=checking, 'S'=saving)
// 'D' - call your deposit function on fromAcct ('C'=checking, 'S'=saving)
// 'W' - call your withdraw function on fromAcct ('C'=checking, 'S'=saving)
// 'T' - call your withdraw function on fromAcct ('C'=checking, 'S'=saving)
// - then call your deposit function on the other.
// 'C' - call your check function on checking
switch (transact) {
case 'B': {
if (fromAcct == 'C')
checkingAccount.output(cout);
if (fromAcct == 'S')
savingAccount.output(cout);
break;
}
case 'D': {
if (fromAcct == 'C') {
checkingAccount.deposit(dollars, cents);
}
if (fromAcct == 'S') {
savingAccount.deposit(dollars,cents);
}
break;
}
case 'W': {
if (fromAcct == 'C') {
checkingAccount.withdraw(dollars,cents);
}
if (fromAcct == 'S') {
savingAccount.withdraw(dollars,cents);
}
break;
}
case 'T': {
if (fromAcct == 'C') {
checkingAccount.withdraw(dollars,cents);
savingAccount.deposit(dollars,cents);
}
if (fromAcct == 'S') {
savingAccount.withdraw(dollars,cents);
checkingAccount.deposit(dollars,cents);
}
break;
}
case 'C':
checkingAccount.check(dollars,cents,checkingAccount.getCheck_fee(),checkingAccount.get_balance());
break;
}

} while (transact != 'Q');

cout << "Come Again! Bye!";
return 0;
}

// Postcondition: transact has a char for the requested transaction
// amount has the amount and from has the account 'C' or 'S'.
void getTransaction(char &transact, double& amount, char &from) {
do {
cout << "What would you like to do today?\n";
cout << "B)alance, D)eposit, W)ithdraw, C)heck, T)ransfer, Q)uit?\n";
cin >> transact;
} while (getTransactionString(transact) == "");
if (transact != 'Q' && transact != 'B') {
    do {
        cout << "What amount would you like to " << getTransactionString(transact) << " today?\n";
        cin >> amount;
    } while (amount <= 0.0);
}

if (transact != 'Q' && transact != 'C') {
    do {
        cout << "From which account? C)hecking S)aving?\n";
        cin >> from;
    } while (from != 'C' && from != 'S');
}
}
string getTransactionString(char transact) {
// @param: the character of the transaction.
// @returns: the string for the transaction.
string transactions[] = { "Balance", "Deposit", "Withdraw", "Check", "Transfer", "Quit" };
for (string it : transactions) {
if (it[0] == transact)
return it;
}
return "";
}