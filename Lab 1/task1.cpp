#include<iostream>
#define ARRAYSIZE 5
using namespace std;
int main()
{
    float arr[ARRAYSIZE];
    bool issame=true;
    int i;
    for(i=0;i<ARRAYSIZE;i++)
    {
        cout<<"Number "<<i+1<<": ";
        cin>>*(arr+i);
    }
    // checking if all the numbers are same?
    for(i=1;i<ARRAYSIZE;i++)
    {
        if(*arr!=*(arr+i))
        {
            issame=false;
            break;
        }
    }
    if(issame)
    cout<<*arr<<" is the second highest number."<<endl;
    else
    {
    int arr2[ARRAYSIZE];
    for(i=0;i<ARRAYSIZE;i++)
    {
        *(arr2+i)=*(arr+i);
    }
    int max=*arr;
    int min=*arr;
    for(i=1;i<ARRAYSIZE;i++)
    {
        if(max<*(arr+i))
            max=*(arr+i);
        if(min>*(arr+i))
            min=*(arr+i);
    }
    // if max is repeated than make that values set to (minimum value minus 2)
    // I made min-2 cuz if there are only 2 values repeated throughout so i have to set max value to lower than the minimum too
    for(i=0;i<ARRAYSIZE;i++)
    {
        if(*(arr+i)==max)
        {
            *(arr2+i)=min-2;
        }
    }
    int max2=*arr2;
    for(i=1;i<ARRAYSIZE;i++)
    {
        if(max2<*(arr2+i))
            max2=*(arr2+i);
    }
    cout<<"Second highest value is: "<<max2;
    }
}