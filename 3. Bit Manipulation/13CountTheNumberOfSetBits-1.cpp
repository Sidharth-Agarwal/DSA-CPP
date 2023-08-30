// Bit manipulation

#include<iostream>

using namespace std;

int main()
{
    int n;

    cout<<"Enter the number : ";
    cin>>n;

    int counter = 0;

    while(n!=0)
    {
        if(n&1 == 1)
        {
            counter++;
        }
        n = n>>1;
    }

    cout<<"The number of set bits are : "<<counter;
}