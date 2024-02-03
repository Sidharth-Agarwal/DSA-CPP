#include<iostream>

using namespace std;

int metaBinarySearch(int *arr, int n, int key)
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

    int x;

    cout<<"Enter the element to search : ";
    cin>>x;

    int index = metaBinarySearch(arr,n,x);

    if(index == -1)
    {
        cout<<"Element not present in the array.";
    }
    else
    {
        cout<<"Index of the element is : "<<index;
    }
}