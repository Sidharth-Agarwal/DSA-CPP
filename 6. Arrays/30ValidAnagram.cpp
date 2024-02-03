// LeetCode - Problem : 242

#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

bool validAnagram(string first, string second)
{
    if(first.size()!=second.size())
    {
        return false;
    }

    unordered_map<char,int> check;

    for(int i=0;i<first.size();i++)
    {
        check[first[i]]++;
    }

    for(int i=0;i<second.size();i++)
    {
        check[second[i]]--;
    }

    
}

int main()
{
    string first;
    
    cout<<"Enter the first string : ";
    cin>>first;

    string second;

    cout<<"Enter the second string : ";
    cin>>second;


}