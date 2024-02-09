#include<iostream>
using namespace std;
void takeInput(int arr[],int size)//take input of for array
{
	for (int i = 0; i < size; i++)
	{
		cout << "enter element " << i << " : ";
		cin >> arr[i];
	}
}
void printUnique(int arr[], int size)//print only unique elements of array
{
	cout << "unique elements are :\n";
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int k = 0; k < size; k++)
		{
			if (arr[i] == arr[k]) { count++; }
		}
		if (count == 1)
		{
			cout << "elemnt at index " << i << " = " << arr[i] << " is unique\n";
		}

	}
}
int main()
{
	const int size = 10;
	int arr[size] = { 0 };
	takeInput(arr, size);
	printUnique(arr, size);
	return 0;
}