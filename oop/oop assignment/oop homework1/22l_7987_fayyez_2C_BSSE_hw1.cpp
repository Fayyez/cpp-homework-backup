#include<iostream>
#include<windows.h>
using namespace std;
//Q1:if passed by value the their user entered values woulf be lost as memory blocks are destroyed
//   outside of code blocks resulting in memory leak
//Q2:if pointer is passed as a const ptr to const int then we can't take any input from user or change the already stored values
//Q3:dellocation is necessory to prevent memory leak as memory blocks in heap are otherwise not destroyed automatically
//   rellocateing pointer p (passed by-ref)to the newly created pointer temp so that the pointer location can be accessed later when 
//   local pointer temp is destroyed outside of its code block
//Q4:then all alterations made in growArray() will be lost, size will remain the same as in getData() and pointer p will keep pointing 
//   to the address of og array in heap in main() causing memory leak (as heap memory used to stored temp array will no longer be accessible)
//Q5:taking parameters by-reference means that no alias is created for the variables hence saving memory
//Q6:for the sake of memory integrity, i.e.,to avoid accidental changes in pointer p which may result in memory leak
//Q7:const ptr to const int because the funtion printArray() is not supposed to alter any data stord in the dynamic array created through pointer p
//Q8:taing int by-reference saves memory as no alias is created for the int and taking size as a const int is to ensure code integrity, i.e., to 
//   prevent accidental changes in the data of size
//Q9:if we receive the pointer as a const pointer to an int, then it cant be re-alloted to any other memory location. The const pointer can be deallocated 
//   using keyword "delete" but it can't be rellocated to NULL as it would result in an error
//
void allocateMemory(int*& ptr, int& size) 
{
	do {
		cout << "Enter positve size for the array my master : ";
		cin >> size;
		if (size < 1)
		{
			cout << "ghalat input he yaawr.";
		}
	} while (size < 1);
	ptr = new int[ size ];
}
void getData(int*const & p,int*const & q)
{
	for (int i = 0; p+i<=q; i++)
	{
		do {
			cout << "Enter positve value for index "<<i<<" : ";
			cin >> *(p+i);
			if (*(p + i) < 1)
			{
				cout << "ghalat input he yaawr.";
			}
		} while (*(p + i) < 1);
	}
}
void growArray(int*& p, int& size)
{
	int new_size;
	do {//get now size
		cout << "Enter new size for the array my master"<<
			"(greater than the double of previous size) : ";
		cin >> new_size;
		if (new_size <= size*2)
		{
			cout << "ghalat input he yaawr.";
		}
	} while (new_size < size * 2);

	int* temp = new int[new_size];
	int i = 0;
	for (;i <size; i++)//copy data of p array to temp aray
	{
		*(temp + i) = *(p + i);
	}
	for (; i<new_size ; i++)//get data in remaining indices of array
	{
		do {
			cout << "Enter positve value for index " << i << " : ";
			cin >> *(temp+ i);
			if (*(temp + i) < 1)
			{
				cout << "ghalat input he yaawr." << endl;
			}
		} while (*(temp + i) < 1);
	}
	delete[] p;
	p = temp;
	size = new_size;
	
}
void printArray(const int * const& p,const int & size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << endl;
}
int* shrinkArray(int* p, int& size)//return type is a pointer to int
{
	int new_size;
	do {//get now size
		cout << "Enter new size for the array my master" <<
			"(less than half of previous size) : ";
		cin >> new_size;
		if (new_size > size / 2 || new_size<1)
		{
			cout << "ghalat input he yaawr."<<endl;
		}
	} while (new_size > size / 2 || new_size < 1);
	int* temp = new int[new_size];
	for (int i=0; i < new_size; i++)//copy data of first new_size indices of p array to temp array
	{
		*(temp + i) = *(p + i);
	}
	delete[]p;
	size = new_size;
	return temp;
}
void getDistinct(int*& p, int& size)
{
	int no_distinct = 0;
	for (int i = 0; i < size; i++)//counts the number of distinct elements in p
	{
		bool unique = true;
		for (int j = 0; j < size; j++)
		{
			if (i == j) continue;
			if (p[i] == p[j])
			{
				unique = false;
			}
		}
		if (unique) no_distinct++;
	}
	int* temp = new int[no_distinct], index_to_insert = 0;
	for (int i = 0; i < size; i++)//copies the distinct elements in the temp array
	{
		bool unique = true;
		for (int j = 0; j < size; j++)
		{
			if (i == j) continue;
			if (p[i] == p[j])
			{
				unique = false;
			}
		}
		if (unique)
		{
			temp[index_to_insert]=p[i];
			index_to_insert++;
		}
		
	}
	delete[] p;
	p = temp;
	size = no_distinct;
}
void releaseResources(int *&  p)
{
	delete [] p;
	p = NULL;
}
int main()
{
	system("color 70");
	int size = 0, * p = NULL;
	allocateMemory(p,size);//creates a dynamic array = size 
	int* q = p + (size - 1);//q pointd to last indx of array
	getData(p, q);
	cout << "\narray is :\n";
	printArray(p, size);
	growArray(p,size);//gets a new size which is atleast double that of og array
	cout << "\nbigger array is :\n";
	printArray(p, size);//prints all the values yo
	p=shrinkArray(p, size);
	cout << "\nsmaller array is :\n";
	printArray(p, size);
	getDistinct(p, size);
	cout << "\narray of distinct elements is :\n";
	printArray(p, size);
	releaseResources(p);
	return 0;
}