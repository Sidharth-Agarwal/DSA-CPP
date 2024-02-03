#include<iostream>

using namespace std;

int linearSearch(int *arr, int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }

    return -1;
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

    int x;

    cout<<"Enter the element to search : ";
    cin>>x;

    int index = linearSearch(arr,n,x);

    if(index == -1)
    {
        cout<<"Element not present in the array.";
    }
    else
    {
        cout<<"Index of the element is : "<<index;
    }
}