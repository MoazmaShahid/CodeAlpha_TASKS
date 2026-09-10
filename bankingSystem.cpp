#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double amt) {
        type = t;
        amount = amt;
    }

    void show() {
        cout << type << ": Rs. " << amount << endl;
    }
};

class Account {
public:
    int accNo;
    double balance;
    vector<Transaction> history;

    Account(int no, double startBalance) {
        accNo = no;
        balance = startBalance;
    }

    void deposit(double amt) {
        balance += amt;
        history.push_back(Transaction("Deposit", amt));
        cout << "Deposited Rs. " << amt << endl;
    }

    bool withdraw(double amt) {
        if (amt > balance) {
            cout << "Insufficient balance.\n";
            return false;
        }
        balance -= amt;
        history.push_back(Transaction("Withdraw", amt));
        cout << "Withdrew Rs. " << amt << endl;
        return true;
    }

    void showHistory() {
        cout << "\nTransaction History:\n";
        if (history.empty()) {
            cout << "No transactions yet.\n";
            return;
        }
        for (int i = 0; i < history.size(); i++) {
            history[i].show();
        }
    }

    void showBalance() {
        cout << "Account No: " << accNo << " | Balance: Rs. " << balance << endl;
    }
};

class Customer {
public:
    string name;
    Account account;

    Customer(string n, int accNo, double startBalance) : account(accNo, startBalance) {
        name = n;
    }

    void showInfo() {
        cout << "\nCustomer: " << name << endl;
        account.showBalance();
    }
};

int findCustomerByAccNo(vector<Customer> &customers, int accNo) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].account.accNo == accNo) {
            return i;
        }
    }
    return -1;
}

void transferFunds(Customer &from, Customer &to, double amt) {
    if (from.account.withdraw(amt)) {
        to.account.deposit(amt);
        cout << "Transferred Rs. " << amt << " from " << from.name << " to " << to.name << endl;
    }
}

int main() {
    vector<Customer> customers;
    int choice;

    do {
        cout << "\n----- Banking System -----\n";
        cout << "1. Create Customer\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. View Account Info\n";
        cout << "6. View Transaction History\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            double startBalance;
            int accNo = customers.size() + 101; 

            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter starting balance: ";
            cin >> startBalance;

            customers.push_back(Customer(name, accNo, startBalance));
            cout << "Customer created with Account No: " << accNo << endl;
        }
        else if (choice == 2) {
            int accNo;
            double amt;
            cout << "Enter account number: ";
            cin >> accNo;

            int idx = findCustomerByAccNo(customers, accNo);
            if (idx == -1) {
                cout << "No customer found with that account number.\n";
            } else {
                cout << "Enter deposit amount: ";
                cin >> amt;
                customers[idx].account.deposit(amt);
            }
        }
        else if (choice == 3) {
            int accNo;
            double amt;
            cout << "Enter account number: ";
            cin >> accNo;

            int idx = findCustomerByAccNo(customers, accNo);
            if (idx == -1) {
                cout << "No customer found with that account number.\n";
            } else {
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                customers[idx].account.withdraw(amt);
            }
        }
        else if (choice == 4) {
            int fromAcc, toAcc;
            double amt;
            cout << "Enter sender's account number: ";
            cin >> fromAcc;
            cout << "Enter receiver's account number: ";
            cin >> toAcc;

            int fromIdx = findCustomerByAccNo(customers, fromAcc);
            int toIdx = findCustomerByAccNo(customers, toAcc);

            if (fromIdx == -1 || toIdx == -1) {
                cout << "One or both account numbers are invalid.\n";
            } else {
                cout << "Enter amount: ";
                cin >> amt;
                transferFunds(customers[fromIdx], customers[toIdx], amt);
            }
        }
        else if (choice == 5) {
            int accNo;
            cout << "Enter account number: ";
            cin >> accNo;

            int idx = findCustomerByAccNo(customers, accNo);
            if (idx == -1) {
                cout << "No customer found with that account number.\n";
            } else {
                customers[idx].showInfo();
            }
        }
        else if (choice == 6) {
            int accNo;
            cout << "Enter account number: ";
            cin >> accNo;

            int idx = findCustomerByAccNo(customers, accNo);
            if (idx == -1) {
                cout << "No customer found with that account number.\n";
            } else {
                customers[idx].account.showHistory();
            }
        }
        else if (choice == 7) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}