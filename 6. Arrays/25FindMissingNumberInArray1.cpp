#include<iostream>

using namespace std;

int missingNumber(int *arr, int N) 
{
    for (int i = 1; i <= N; i++)
    {
        int flag = 0;

        for (int j = 0; j < N - 1; j++) 
        {
            if (arr[j] == i) 
            {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0)
        {
            return i;
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

    int ans = missingNumber(arr, n);

    cout << "The missing number is: " << ans << endl;

    return 0;
}