#include<iostream>
#include<cstdlib>
using namespace std;
void* arrOp(void* arr,int size)
{
    int* sum = new int(0);
    for (int i = 0; i < size; i++) {
        *sum += ((int*)arr)[i];
    }
    return (void*)sum;
}
int main(int argc,char* argv[])
{
    if (argc < 2) 
    {
        cout << "Usage: " << *argv << " num1 num2 num3 ..." << endl;
        return 1;
    }
    int* arr=new int[argc-1];
    for(int i=0;i<argc-1;i++)
    {
        arr[i]=atoi(argv[i+1]);
    }
   void* newArr=arrOp((void*) arr,argc-1);
   cout<<"Sum: "<<*(int*)newArr;
    delete[] arr;
}
