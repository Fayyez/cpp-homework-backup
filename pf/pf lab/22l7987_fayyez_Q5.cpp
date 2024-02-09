//#include<iostream>
//#include<stdio.h>
//using namespace std;
//void takeInput(int arr[], int size)//take input of for array
//{
//	for (int i = 0; i < size; i++) {
//		cout << "enter element " << i << " : ";
//		cin >> arr[i];
//	}
//}
//void bubbleSort(int arr[],int size)//bubble sort for ascending order
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int k = 0; k < size - 1; k++)
//		{
//			if (arr[k] > arr[k + 1])
//			{
//				int temp = arr[k + 1];
//				arr[k + 1] = arr[k];
//				arr[k] = temp;
//			}
//		}
//	}
//}
//void printArray(int arr[], int size)//for printing array
//{
//	for (int x = 0; x < size; x++)
//	{
//		cout << arr[x] << "\t";
//	}
//	cout << endl;
//}
//int main()
//{
//	const int size = 10;
//	int arr[size] = { 0 };
//	takeInput(arr, size);
//	bubbleSort(arr, size);
//	cout << "sorted array :\n";
//	printArray(arr, size);
//	return 0;
//}