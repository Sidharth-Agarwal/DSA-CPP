// Bit Manipulation

#include<iostream>

using namespace std;

int main()
{
    int l;

    cout<<"Enter the starting range : ";
    cin>>l;

    int r;

    cout<<"Enter the ending range : ";
    cin>>r;

    // Approach XOR(l-1) ^ XOR(r)

    int left = 0;

    if((l-1)%4 == 0)
    {
        left = l-1;
    }

    else if((l-1)%4 == 1)
    {
        left = 1;
    }

    else if((l-1)%4 == 2)
    {
        left = l;
    }

    else
    {
        left = 0;
    }

    int right = 0;

    if(r%4 == 0)
    {
        right = r;
    }

    else if(r%4 == 1)
    {
        right = 1;
    }

    else if(r%4 == 2)
    {
        right = r+1;
    }

    else
    {
        right = 0;
    }

    cout<<"The output is : "<<(left^right);
}