// Using Hash Sets

#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int removeDuplicates(int *arr, int n)
{
    set<int> hashSet;

    for(int i=0;i<n;i++)
    {
        hashSet.insert(arr[i]);
    }

    int size = hashSet.size();
    
    int j = 0;

    for(auto i:hashSet)
    {
        arr[j++] = i;
    }

    return size;
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