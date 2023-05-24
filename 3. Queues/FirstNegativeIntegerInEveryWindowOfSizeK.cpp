#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;
    
    // process the first window of size k
    for(int i=0;i<k;i++)
    {
        if(arr[i] < 0)
        {
            dq.push_back(i);   
        }
    }
    
    // store answer of first k sized window
    if(dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    
    
    // process the remaining windows
    for(int i=k;i<n;i++)
    {
        // removal
        if(!dq.empty() && i-dq.front() >= k)
        {
            dq.pop_front();
        }
        
        // addition
        if(arr[i] < 0)
        {
            dq.push_back(i);
        }
        
        // ans store
        if(dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    
    return ans;
}

int main()
{
    long long int n;
    cin >> n;

    long long int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long int k;
    cin >> k;

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);

    for(auto it : ans)
    {
        cout << it << " ";
    }
}