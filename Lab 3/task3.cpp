#include <iostream>
#include <string>
using namespace std;
class Glass
{
private:
    int liquidLevel;

public:
    Glass() : liquidLevel(200) {}
    void refill()
    {
        liquidLevel = 200;
        cout << "Glass refilled automatically to 200ml"<<endl;
    }
    void drink(int liquid)
    {
        liquidLevel -= liquid;
    }
    int getLiquidLevel()
    {
        return liquidLevel;
    }
};
int main()
{
    Glass water;
    int l,choice;
    while (1)
    {
        if(water.getLiquidLevel()<100)
        {
            water.refill();
        }
        cout<<"Choose from the following: "<<endl<<"1. Drink"<<endl<<"Press another key to exit the program"<<endl<<"Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter how many ml water do you want to drink?"<<endl<<"Answer: ";
            cin>>l;
            while(l>water.getLiquidLevel() || l<0)
            {
                cout<<"Invalid amount entered!"<<endl;
                cout<<"Enter how many ml water do you want to drink?"<<endl<<"Answer: ";
                cin>>l;
            }
            water.drink(l);
            cout<<"water left: "<<water.getLiquidLevel()<<endl;
            break;
            default:
            cout<<"Thank you for using our robot...";
            exit(0);
        }
    }
    
}