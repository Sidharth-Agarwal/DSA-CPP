#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> concatenateArray(vector<int> &arr)
{
    vector<int> ans(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++)
    {
        ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{
    int n;

    cout<<"Enter the size of the array : ";
    cin>>n;

    vector<int> arr;

    cout<<"Enter the elements of the array : ";

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;

        arr.push_back(x);
    }

    vector<int> concatenate = concatenateArray(arr);

    cout<<"Concatenation of the array is : ";

    for(int i=0;i<concatenate.size();i++)
    {
        cout<<concatenate[i]<<" ";
    }
}