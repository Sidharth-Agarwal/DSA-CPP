#include<iostream>
#include<bits/stdc++.h>

using namespace std;

set<int> arrayUnion(int *arr1, int n, int *arr2, int m)
{
    set<int> ans;

    for(int i=0;i<n;i++)
    {
        ans.insert(arr1[i]);
    }

    for(int j=0;j<m;j++)
    {
        ans.insert(arr2[j]);
    }

    return ans;
}

int main()
{
    int n;

    cout<<"Enter the size of the first array : ";
    cin>>n;

    int *arr1 = new int[n];

    cout<<"Enter the elements of the first array : ";
    
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

    int m;

    cout<<"Enter the size of the second array : ";
    cin>>m;

    int *arr2 = new int[m];

    cout<<"Enter the elements of the second array : ";

    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    set<int> ans = arrayUnion(arr1,n,arr2,m);

    cout<<"The union of the two arrays is : ";

    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}