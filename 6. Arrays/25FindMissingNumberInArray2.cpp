#include<iostream>

using namespace std;

int missingNumber(int *arr, int N) 
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

    int ans = missingNumber(arr, n);

    cout << "The missing number is: " << ans << endl;

    return 0;
}