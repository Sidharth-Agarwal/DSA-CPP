// Coding Ninjas

#include<iostream>

using namespace std;

int main()
{
    int arr[10];
    int *arr1 = new int[100];

    cout << "Enter the elements in the first array : ";
    for (int i = 0; i < 10;i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the elements in the second array : ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr1[i];
    }

    cout << "The elements of the first array are : ";
    for (int i = 0; i < 10;i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    cout << "The elements of the second array are : ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
}