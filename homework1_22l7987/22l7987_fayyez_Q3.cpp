//#include<iostream>
//using namespace std;
//void printArray(char arr[], int size)//for printing array
//{
//	for (int x = 0; x < size; x++)
//	{
//		cout << arr[x];
//	}
//	cout << endl;
//}
//void ReverseString(char arr[],int size)
//{
//	int pointer = 0, i = 0, count1 = 0, noToReverse = 0;
//	for(;arr[pointer]!='\0';)//to check for array ending
//	{
//		int count = 0;//counts the letters in a word
//		for (; i < size && arr[i] != ' ' && arr[i]!='\0'; i++)
//		{
//			count++;
//		}
//		count1 += count;
//		for (int k=0; k < count / 2; k++)//reverses single words
//		{
//			int temp = arr[count1-1 - k];
//			arr[count1-1 - k] = arr[noToReverse];
//			arr[noToReverse] = temp;
//			noToReverse++;
//		}
//		i++; count1++;//to jump to next word
//		noToReverse = i;
//		pointer = i;
//	}
//}
//int main()
//{
//	const int size = 50;
//	char arr[size] = { 0 };
//	cout << "enter your desired string and i will  reverse it for my master : ";
//	cin.getline(arr,size-1);//last space for null terminator
//	ReverseString(arr, size);
//	cout << "here you go your grace :\n";
//	printArray(arr, size);
//	system("pause>0");
//	return 0;
//}