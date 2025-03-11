#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int accn;
    double balance;
public:
    BankAccount(int an, double bal) : accn(an), balance(bal) {}
    
    void deposit(double dep) {
        balance += dep;
        cout << "Deposited: $" << dep << " | New Balance: $" << balance << endl;
    }
    
    void withdraw(double with) {
        if (with > balance) {
            cout << "Insufficient funds!" << endl;
            return;
        }
        balance -= with;
        cout << "Withdrawn: $" << with << " | New Balance: $" << balance << endl;
    }
    
    double getBalance() {
        return balance;
    }
    
    int getAccountNumber() {
        return accn;
    }
    
    void checkBalance() {
        cout << "Balance: " << balance << endl;
    }
};

class SavingAccount : public BankAccount {
    const double monthinter;
public:
    SavingAccount(int an, double bal, double mi) : BankAccount(an, bal), monthinter(mi) {}
    
    void applyInterest() {
        balance += balance * monthinter;
        cout << "Interest Applied! New Balance: $" << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overlimit;
public:
    CheckingAccount(int an, double bal, double ol) : BankAccount(an, bal), overlimit(ol) {}
    
    void overdraft(double amt) {
        if (amt > overlimit) {
            cout << "Overdraft Limit Exceeded!" << endl;
            return;
        }
        withdraw(amt);
    }
    
    void setOverlimit(double lim) {
        overlimit = lim;
    }
};

class BusinessAccount : public BankAccount {
    const double tax;
public:
    BusinessAccount(int an, double bal, double t) : BankAccount(an, bal), tax(t) {}
    
    void deposit(double amt) {
        double deductedamt = amt * tax;
        BankAccount::deposit(amt - deductedamt);
        cout << "Corporate Tax Deducted: $" << deductedamt << endl;
    }
};

class Customer {
    BankAccount* b;
    string name;
public:
    Customer(BankAccount* bank, string n) : b(bank), name(n) {}
    
    void deposit(double amt) {
        b->deposit(amt);
    }
    
    void withdraw(double amt) {
        b->withdraw(amt);
    }
    
    void checkBalance() {
        b->checkBalance();
    }
};
class Employee
{
    protected:
    string name;
    int empid;
    public:
    Employee(string n,int e):name(n),empid(e){}
};
class Teller:public Employee {
    BankAccount* b;
public:
    Teller(BankAccount* bank, string n, int e) : b(bank), Employee(n,e) {}
    
    void deposit(double amt) {
        b->deposit(amt);
    }
    
    void withdraw(double amt) {
        b->withdraw(amt);
    }
    
    void checkBalance() {
        b->checkBalance();
    }
    
    void freeze() {
        cout << name << "'s account has been frozen!" << endl;
    }
};

class Manager:public Employee {
    BankAccount* b;
public:
    Manager(BankAccount* bank, string n, int e) : b(bank),Employee(n,e) {}
    
    void deposit(double amt) {
        b->deposit(amt);
    }
    
    void withdraw(double amt) {
        b->withdraw(amt);
    }
    
    void checkBalance() {
        b->checkBalance();
    }
    
    void freeze() {
        cout << name << "'s account has been frozen!" << endl;
    }
    
    void update(CheckingAccount* ch, double lim) {
        ch->setOverlimit(lim);
    }
};

int main() {
    SavingAccount sAcc(101, 1000, 0.05);
    CheckingAccount cAcc(102, 500, 200);
    BusinessAccount bAcc(103, 3000, 0.10);

    Customer cust(&sAcc, "Alice");
    Teller teller(&cAcc, "Bob",2);
    Manager manager(&bAcc, "Charlie", 3);

    cout << "\nCustomer Operations:\n";
    cust.deposit(200);
    cust.withdraw(100);
    cust.checkBalance();
    
    cout << "\nTeller Operations:\n";
    teller.deposit(300);
    teller.withdraw(150);
    teller.checkBalance();
    teller.freeze();

    cout << "\nManager Operations:\n";
    manager.deposit(500);
    manager.withdraw(250);
    manager.checkBalance();
    manager.freeze();

    cout << "\nApplying Interest for Savings Account:\n";
    sAcc.applyInterest();
    
    return 0;
}