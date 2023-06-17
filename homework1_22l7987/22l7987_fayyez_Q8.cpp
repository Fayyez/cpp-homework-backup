//#include<iostream>
//using namespace std;
//const int Size = 10;
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
//void binomSum(const int arr[])//for summation
//{
//	int SumArr[Size]={0};
//	int end = 0;
//	for (int i = 0; i < Size; i++)
//	{
//		end = arr[i];
//		int start = 0, sum = 0;
//		while (start <= end)
//		{
//			sum += start;
//			start++;
//		}
//		SumArr[i] = sum;
//	}
//	cout << "Summed array values =\t";
//	printArray(SumArr,Size);
//}
//int main()
//{
//	const int size = 10;
//	int arr[size] = { 0 };
//	int y = sizeof(arr);
//	takeInput(arr, size);
//	binomSum(arr);
//	system("pause>0");
//	return 0;
//}
