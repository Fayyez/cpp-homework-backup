//#include<iostream>
//#include<windows.h>
//using namespace std;
//void allocateMemeory(int **& arr,int & row,int & col)
//{
//	do {//get valid row
//	cout << "Enter number of rows : ";
//	cin >> row;
//	if (row < 1) cout << "invalid input\n";
//	} while (row < 1);
//
//	do {// get valid column
//		cout << "Enter number of cols : ";
//		cin >> col;
//		if (col < 1) cout << "invalid input\n";
//	} while (col < 1);
//	
//	arr = new int* [row];//declare&allocate array arr[row][col]
//	for (int i = 0; i < row; i++)
//	{
//		arr[i] = new int[col];
//	}
//}
//void getData(int * const * const & arr, const int row,const int col)
////Q1: if we write const before int then arr would become a const pointer to 
////   const pointer to a "const integer value" ,i.e., the integer value itself 
////   which arr is ultimately used to point to would become unchangeable and hence,
////   getdata won't be able to take any user input into those memory locations.
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			do {// get valid column
//				cout << "Enter index ("<<i<<","<<j<<") : ";
//				cin >> arr[i][j];
//				while (cin.fail())//to prevent character input
//				{
//					cin.clear();
//					cin.ignore(INT_MAX, '\n');
//					cout << "You can only enter numbers.\n";
//					cout << "Enter a number.\n";
//					cin >> arr[i][j];
//				}
//				if (arr[i][j] < 10) cout << "invalid input. Only +ve values > 10 are allowed\n";
//			} while (arr[i][j] < 10);
//		}
//	}
//	system("pause");
//	system("CLS");
//}
//int** fetchData(int * const * const & ogArr,const int & ogRow, const int & ogCol,int & fd_row)
//{
//	int** arr = NULL;//to save fetched data
//    fd_row = 3;
//	arr = new int* [fd_row];
//	int size1 = 1, size2 = 1, size3 = 1;//sizes start from 1 for sentinel value
//	for (int i = 0; i < ogRow; i++)//to get number of column of fetched array
//	{
//		for (int j = 0; j < ogCol; j++)
//		{
//			if (ogArr[i][j] % 2 == 0 && j % 2 != 0)//even value && odd column
//			{
//				size1++;
//			}
//			else if(ogArr[i][j] % 2 != 0 && j % 2 == 0)//odd value in even column
//			{
//				size2++;
//			}
//			int checkPrime=2,counter=0;//least possible number in ogArr is 10 so nocheck for 1 is needed
//			while(checkPrime++ <= ogArr[i][j]/2)
//			{ 
//				if (ogArr[i][j] % checkPrime == 0)//if ogArr[i][j] is a multiple of checkPrime
//				{
//					counter++;
//					break;
//				}
//			}
//			if (!counter)
//			{
//				size3++;
//			}
//		}
//	}	
//	arr[0] = new int[size1];
//	arr[1] = new int[size2];
//	arr[2] = new int[size3];
//	arr[0][size1 - 1] = -1;
//	arr[1][size2 - 1] = -1;
//	arr[2][size3 - 1] = -1;
//	int x = 0, y = 0, z = 0;
//	for (int i = 0; i < ogRow; i++)//to fill columns of fetched array
//	{
//		for (int j = 0; j < ogCol; j++)
//		{
//			if (ogArr[i][j] % 2 == 0 && j % 2 != 0)//even value && odd column
//			{
//				arr[0][x++] = ogArr[i][j];
//			}
//			else if (ogArr[i][j] % 2 != 0 && j % 2 == 0)//odd value in even column
//			{
//				arr[1][y++] = ogArr[i][j];
//			}
//			int checkPrime = 2, counter = 0;
//			while (checkPrime++ < ogArr[i][j] / 2)
//			{
//				if (ogArr[i][j] % checkPrime == 0)
//				{
//					counter++;
//					break;
//				}
//			}
//			if (!counter) arr[2][z++] = ogArr[i][j];
//		}
//	}
//	return arr;
//}
//void printData(const int* const* const& arr, const int row, const int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			cout << *(*(arr + i) + j)<<" ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//void displayData(const int* const* const& arr, const int row)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; arr[i][j]!=-1; j++)
//		{
//			cout << *(*(arr + i) + j) << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//void releaseResources(int**& arr, const int& row)
//{
//	for (int i = 0; i < row; i++)
//	{
//		delete[]arr[i];
//		arr[i] = NULL;
//	}
//	delete[]arr;
//	arr = NULL;
//}
//int main()
//{
//	int** ogArr = NULL, ** fetched = NULL,row=0,col=0, fd_row=0;
//	allocateMemeory(ogArr,row,col);
//	getData(ogArr, row, col);
//	system("color 70");
//	cout << "original Array is :\n";
//	printData(ogArr, row, col);
//	fetched = fetchData(ogArr,row,col,fd_row);
//	cout << "Fetched Array is :\n";
//	displayData(fetched,fd_row);
//	releaseResources(ogArr, row);
//	releaseResources(fetched, fd_row);
//
//	return 0;
//}