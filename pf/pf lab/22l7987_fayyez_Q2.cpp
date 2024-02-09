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
//	{
//		cout << arr[x] << "\t";
//	}
//	cout << endl;
//}
//void rotateArray(int arr[], int size, int factor)//rotates to left
//{
//	cout << "array after shifting " << factor << " times :\n";
//	for(int shift=1;shift<=factor;shift++)
//	{
//		for (int i = 0; i < size-1; i++)
//		{
//			int temp = arr[i + 1];
//			arr[i + 1] = arr[i];
//			arr[i] = temp;
//		}	
//    }
//	printArray(arr, size);
//}
//int main()
//{
//	const int size = 10;
//	int arr[size] = { 0 };
//	takeInput(arr, size);
//	int d = 0;
//	cout << "enter times you want to rotate the array : ";
//	cin >> d;
//	rotateArray(arr, size, d);
//	return 0;
//}