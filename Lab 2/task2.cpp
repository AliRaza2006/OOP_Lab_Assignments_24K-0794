#include<iostream>
#include<cstdlib>
using namespace std;
void* add(char* el[],int size)
{
    int* c=new int[size];
    for(int i=0;i<size;i++)
    c[i]=atoi(el[i]);
    int* sum=new int(0);
    for(int i=0;i<size;i++)
    {
        *sum+=c[i];
    }
    delete[] c;
    return (void*)sum;
}
int main(int argc,char* argv[])
{
    if(argc<2)
    {
        cout<<"Too less arguments!";
        return 0;
    }
    int* result=(int*)add(argv+1,argc-1);
    cout<<"Sum: "<<*result;
    delete result;
}
