// Bit Manipulation

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    int ans = 0;

    for(int i=0;i<=n;i++)
    {
        ans = ans^i;
    }

    cout<<"The output is : "<<ans;
}