//#include<iostream>
//using namespace std;
//void takeInput(int arr[], int size)//take input of for array
//{
//	for (int i = 0; i < size; i++) {
//		cout << "enter element " << i << " : ";
//		cin >> arr[i];
//	}
//}
//void printArray(int arr[], int size)//for printing array
//{
//	for (int x = 0; x < size; x++)
//	{ cout << arr[x] << "\t"; }
//	cout << endl;
//}
//void insertionSort(int arr[],int size)//sort array in asecding order
//{
//	for (int i = 1; i < size; i++)
//	{
//		int k = i - 1, insert=arr[i];
//		while (k >= 0 && arr[k] > insert)
//		{
//			arr[k + 1] = arr[k];
//			k--;
//		}
//		arr[k + 1] = insert;
//
//	}
//}
//int binarySearch(int arr[], int size, int key)
//{
//	int left = 0, right = size - 1, mid = -1;
//	while (left <= right)
//	{
//	    mid = (left + right) / 2;	
//		if (arr[mid] == key) { return mid; }
//		else if (arr[mid] > key) right = mid - 1;
//		else left = mid + 1;
//	}
//	return mid;
//}
//int main()
//{
//	const int size = 10;
//	int arr[size] = { 0 };
//	takeInput(arr, size);
//	int key;
//	cout << "enter key to be searched ; ";
//	cin >> key;
//	insertionSort(arr, size);
//	cout << "sorted array :\t";
//	printArray(arr, size);
//	int index = binarySearch(arr, size, key);
//	if (index == -1)
//	{
//		cout << "key is not present in the given array!\n";
//	}
//	else cout << "key is present at index : " << index;
//	system("pause>0");
//	return 0;
//}