#include<iostream>

using namespace std;

int missingNumber(int *arr, int N) 
{
    int xor1 = 0;
    int xor2 = 0;

    for(int i=0;i<N-1;i++)
    {
        xor2 = xor2^arr[i];
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^N;
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

    int ans = missingNumber(arr, n+1);

    cout << "The missing number is: " << ans << endl;

    return 0;
}