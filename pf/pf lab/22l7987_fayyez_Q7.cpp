//#include<iostream>
//#include<string>
//using namespace std;
//void takeInput(char arr[], int size)//take input of for array
//{
//	cout << "tell your slave " << size << " characters : (only first 5 characters will be considered, master) : ";
//	cin >> arr;
//}
//void printArray(char arr[], int size)//for printing array
//{
//	for (int x = 0; x < size; x++)
//	{
//		cout << arr[x] << "\t";
//	}
//	cout << endl;
//}
//bool PalindromeString(char arr[], int size)
//{
//	int pairIndex = size - 2;
//	for (int indexToCheck = 0; indexToCheck < size / 2; indexToCheck++)
//	{
//		if (arr[indexToCheck] != arr[pairIndex - indexToCheck])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	const int size = 6;
//	char arr[size] = { 0 };
//	takeInput(arr, size);
//	cout << "Master, your array is : ";
//	printArray(arr, size);
//	bool check1 = PalindromeString(arr, size);
//	if (check1 == true)
//	{
//		cout << "you have entered a palindrome my master.\n";
//	}
//	else cout << "your string is not a palindrome my master.";
//	system("pause>0");
//	return 0;
//}