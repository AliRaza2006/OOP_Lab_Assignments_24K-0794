#include<iostream>
#include<string>
using namespace std;
class Engine
{
    private:
    bool isRunning;
    public:
    void start()
    {
        cout<<"Engine started"<<endl;
        isRunning=1;
    }
    void stop()
    {
        cout<<"Engine stopped"<<endl;
        isRunning=0;
    }
};
class Car
{
    Engine engine;
    public:
    void startCar()
    {
        engine.start();
    }
    void stopCar()
    {
        engine.stop();
    }
};
int main()
{
    Car car;
    car.startCar();
    car.stopCar();
}