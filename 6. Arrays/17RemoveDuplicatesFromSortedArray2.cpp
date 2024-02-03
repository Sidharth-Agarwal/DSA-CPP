// Using 2 Pointers

#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int removeDuplicates(int *arr, int n)
{
    int i = 0;

    for(int j=1;j<n;j++)
    {
        if(arr[i]!=arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    
    return i+1;
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

    int ans = removeDuplicates(arr,n);

    cout<<"The final array is : ";

    for(int i=0;i<ans;i++)
    {
        cout<<arr[i]<<" ";
    }
}