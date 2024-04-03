#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, string accName, double bal) {
        accountNumber = accNum;
        accountHolderName = accName;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal done. New balance: " << balance << endl;
        } else {
            cout << "Not enough Balance" << endl;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount* accounts[5];

    accounts[0] = new BankAccount(1001, "Momin", 5000);
    accounts[1] = new BankAccount(1002, "Azlan", 8000);
    accounts[2] = new BankAccount(1003, "Mubarak", 3000);
    accounts[3] = new BankAccount(1004, "Hashir", 6000);
    accounts[4] = new BankAccount(1005, "Shaheer", 7000);

    accounts[0]->display();
    accounts[0]->deposit(1000);
    accounts[0]->withdraw(2000);

    accounts[1]->display();
    accounts[1]->withdraw(10000);

    for (int i = 0; i < 5; ++i) {
        delete accounts[i];
    }

    return 0;
}
