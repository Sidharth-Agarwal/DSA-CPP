#include<iostream>

using namespace std;

int binarySearchRecursive(int *arr, int start, int end, int x)
{
    if(start<=end)
    {
        int mid = start+(end-start)/2;

        if(x>arr[mid])
        {
            return binarySearchRecursive(arr,mid+1,end,x);
        }
        
        else if(x<arr[mid])
        {
            return binarySearchRecursive(arr,start,mid-1,x);
        }

        else
        {
            return mid;
        }
    }

    return -1;
}

int binarySearch(int *arr, int n, int x)
{
    int start = 0;
    int end = n;

    return binarySearchRecursive(arr,start,end,x);
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