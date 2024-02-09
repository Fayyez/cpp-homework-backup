#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;
void getAchieversList(const int *const * const &scores,const int row,const int col,int**& achievers)
{
	achievers = new int* [col];//number of scores's columns indicate number of teams hence rows of achievers
	for (int j = 0; j < col; j++)
	{
		int count = 1;
		for (int i = 0; i < row; i++)
		{
			if (scores[i][j] >= 300)  count++;
		}
		achievers[j] = new int[count];
		achievers[j][count - 1] = -1;
	}
	for (int j = 0; j < col; j++)
	{
		int x = 0;
		for (int i = 0; i < row; i++)
		{
			if (scores[i][j] >= 300)
			{
				achievers[j][x++] = scores[i][j];
			}
		}
	}
}
void printData(const int* const* const& arr, const int row, const int col)
{
	string countries[5] = { "Aus","Eng","Ind","Pak","NZ" };
	for (int i = 0; i < row; i++)
		cout << countries[i]<<' ';
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		
		for (int j = 0; j < col; j++)
		{
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void displayData(const int* const* const& arr, const int row)
{
	string countries[5] = { "Australia","England","India","Pakistan","New-Zealand" };
	for (int i = 0; i < row; i++)
	{
        cout << countries[i] << " --> ";
		for (int j = 0; arr[i][j] != -1; j++)
		{
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void releaseResources(int**& arr, const int& row)
{
	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
		arr[i] = NULL;
	}
	delete[]arr;
	arr = NULL;
}
int main()
{
	system("color 8f");
	ifstream readScore("scores.txt.txt");
	int** scores = NULL, ** achievers = NULL, row = 5, col=5;
	scores = new int* [col];
	for (int i = 0; i < col; i++)
	{
		scores[i] = new int[row];
	}
	for (int i = 0; i < col; i++)
	{
		int temp = 0;
		for (int j = 0; j < row; j++)
		{
			readScore >> temp;
			scores[j][i] = temp;
		}
	}
	readScore.close();
	cout << "Top 5 team scores (column-wise) :\n";
	printData(scores, row, col);
	getAchieversList(scores,row,col,achievers);
	cout << "eligible players of team (row-wise) :\n";
	displayData(achievers, col);
	releaseResources(scores, row);
	releaseResources(achievers, col);
	return 0;
}