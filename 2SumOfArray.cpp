// Coding Ninjas

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    int sum = 0;

    int arr[n];

    cout << "Enter the elements of the array : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "The sum of the array is : " << sum;
}