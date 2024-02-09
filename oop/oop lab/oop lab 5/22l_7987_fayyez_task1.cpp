#include<iostream>
#include<windows.h>
using namespace std;
class matrix {

	int** p, rows;
public:
	matrix()
	{
		rows = 0;
		p = nullptr;
	}
	void setRows(int r)
	{
		rows = r;
	}
	void setP(int ** arr)
	{
		p = arr;
	}
	int getRows() const
	{
		return rows;
	}
	void inputMatrix()
	{
		p = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			p[i] = new int[rows];
		}
		for (int i = 0; i < rows; i++)
		{
			
			for (int j = 0; j < rows; j++)
			{
				cout << "enter index (" << i << "," << j << ") = ";
				cin >> *(*(p + i) + j);
			}
		}
	}
	void displayMatrix( )
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout << p[i][j]<< " ";
			}
			cout << endl;
		}
	}
	void deallocate(int r)
	{
		for (int i = 0; i < r; i++)
		{
			delete[]p[i];
			p[i] = nullptr;
		}
		delete[]p;
		p = nullptr;
	}
	void rotateOuterlayerBy1(int r)
	{
		for (int j = 0; j < r-1; j++)
		{
			swap(p[0][j], p[0][j + 1]);
		}
		for (int i = 0; i < r - 1; i++)
		{
			swap(p[i][r-1], p[i+1][r-1]);
		}
		for (int j = r-1; j > 0; j--)
		{
			swap(p[r-1][j],p[r-1][j-1]);
		}
		for (int i = r-1; i > 1; i--)
		{
			swap(p[i][0],p[i-1][0]);
		}
	}
	~matrix()
	{
		cout << "deallocated & destroyed\n";
	}
};
int main()
{
	matrix m1;
    int dimension = 0;
	cout << "enter dimension : ";
	cin >> dimension;
	m1.setRows(dimension);
	m1.inputMatrix();
	system("CLS");
	cout << "given matrix :\n";
	m1.displayMatrix();
	m1.rotateOuterlayerBy1(dimension);
	cout << "after rotation :\n";
	m1.displayMatrix();
	m1.deallocate(dimension);
	return 0;

}
