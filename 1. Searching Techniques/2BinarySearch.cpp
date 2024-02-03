#include<iostream>

using namespace std;

int binarySearch(int *arr, int n, int x)
{
    int start = 0;
    int end = n-1;
    
    while(start<end)
    {
        int mid = start+(end-start)/2;

        if(x>arr[mid])
        {
            start=mid+1;
        }
        else if(x<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            return mid;
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

    int index = binarySearch(arr,n,x);

    if(index == -1)
    {
        cout<<"Element not present in the array.";
    }
    else
    {
        cout<<"Index of the element is : "<<index;
    }
}