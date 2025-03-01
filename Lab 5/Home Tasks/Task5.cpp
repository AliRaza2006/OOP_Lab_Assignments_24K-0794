#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
class Car
{
    private:
    mutable float engineHp;
    mutable int seating_cap;
    mutable int no_of_speakers;
    public:
    Car():engineHp(0),seating_cap(0),no_of_speakers(0){}
    void setEngineHp(float hp) const{
        engineHp=hp;
    }
    void setSeatingCap(int sc) const{
        seating_cap=sc;
    }
    void setNoOfSpeakers(int ns) const{
        no_of_speakers=ns;
    }
    float getEngineHp(){return engineHp;}
    int getSeatingCap(){return seating_cap;}
    int getNoOfSpeakers(){return no_of_speakers;}
    void display()
    { 
        cout<<"Engine Horse Power: "<<getEngineHp()<<endl;
        cout<<"Seating capacity: "<<getSeatingCap()<<endl;
        cout<<"Number Of Speakers: "<<getNoOfSpeakers()<<endl;
        Sleep(5000);
        system("cls");
    }
};
int main()
{
    Car c1;
    c1.display();
    c1.setEngineHp(500);
    c1.setNoOfSpeakers(2);
    c1.setSeatingCap(10);
    cout<<"New Values: "<<endl;
    c1.display();
    cout<<"Thank you for using our program!";
    Sleep(5000);
    system("exit");
}