#include<iostream>

using namespace std;

void rotateRight(int *arr, int n)
{
    
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

    rotateRight(arr,n);

    cout<<"The output array is : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}