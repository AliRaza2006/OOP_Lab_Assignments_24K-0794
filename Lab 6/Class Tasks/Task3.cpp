#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee 
{
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual ~Employee() {}
};

class IOrderTaker 
{
public:
    virtual void takeOrder(string order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer 
{
public:
    virtual void prepareOrder(string order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller 
{
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker 
{
public:
    Waiter(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override 
    {
        cout << "Waiter " << name << " is taking order: " << order << endl;
    }
};

class Chef : public Employee, public IOrderPreparer 
{
public:
    Chef(int i, string n) : Employee(i, n) {}
    void prepareOrder(string order) override 
    {
        cout << "Chef " << name << " is preparing: " << order << endl;
    }
};

class Cashier : public Employee, public IBiller 
{
public:
    Cashier(int i, string n) : Employee(i, n) {}
    void generateBill(double amount) override 
    {
        cout << "Cashier " << name << " generated bill: $" << amount << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller 
{
public:
    Manager(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override 
    {
        cout << "Manager " << name << " is taking order: " << order << endl;
    }
    void generateBill(double amount) override 
    {
        cout << "Manager " << name << " generated bill: $" << amount << endl;
    }
};

class Menu 
{
protected:
    vector<pair<string, double>> items;
public:
    virtual double calculateTotal() = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu 
{
public:
    void addItem(string name, double price) 
    {
        items.push_back({name, price});
    }
    double calculateTotal() override 
    {
        double total = 0;
        for (auto& item : items) total += item.second;
        return total;
    }
};

class BeverageMenu : public Menu 
{
public:
    void addItem(string name, double price) 
    {
        items.push_back({name, price});
    }
    double calculateTotal() override 
    {
        double total = 0;
        for (auto& item : items) total += item.second * 1.1;
        return total;
    }
};

int main() 
{
    vector<IOrderTaker*> orderTakers;
    vector<IOrderPreparer*> orderPreparers;
    vector<IBiller*> billers;

    Waiter w1(101, "Ali");
    Chef c1(102, "Sara");
    Cashier ca1(103, "Ahmed");
    Manager m1(104, "Zain");

    orderTakers.push_back(&w1);
    orderTakers.push_back(&m1);
    orderPreparers.push_back(&c1);
    billers.push_back(&ca1);
    billers.push_back(&m1);

    orderTakers[0]->takeOrder("Pizza");
    orderPreparers[0]->prepareOrder("Pizza");
    double total = 15.99;
    billers[0]->generateBill(total);

    return 0;
}