// XOR Approach

#include<iostream>

using namespace std;

int singleOccurence(int *arr, int n)
{
    int ans = 0;

    for(int i=0;i<n;i++)
    {
        ans = ans^arr[i];
    }

    return ans;
}

int main()
{
    int n;
    
    cout<<"Enter the size of the array : ";
    cin>>n;

    int *arr = new int[n];

    cout<<"Enter the elements of the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int single = singleOccurence(arr,n);

    cout<<"The number with single occurence is : "<<single;
}