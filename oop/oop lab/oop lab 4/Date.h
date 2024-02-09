//#pragma once
//#include<iostream>
//#include<string>
//using namespace std;
//class date
//{
//	int day;
//	int month;
//	int year;
//public:
//
//	date()
//	{
//		day = 1;
//		month = 1;
//		year = 1926;
//		cout << "Default constructor called.\n";
//	}
//	date(int d, int m, int y)
//	{
//		day = d;
//		month = m;
//		year = y;
//		cout << "Overloaded constructor called.\n";
//	}
//	void printData()
//	{
//		cout << day << "/" << month << "/" << year << endl;
//	}
//	void input()
//	{
//		int d = 0, m = 0, y = 0;
//		cout << "enter day :";
//		cin >> d;
//		day = d;
//		cout << "enter month :";
//		cin >> m;
//		month = m;
//		cout << "enter year :";
//		cin >> y;
//		year = y;
//
//	}
//	void setData(int d, int m, int y)
//	{
//		day = d;
//		month = m;
//		year = y;
//	}
//	void setDay(int d)
//	{
//		day = d;
//	}
//	void setMonth(int m)
//	{
//		month = m;
//	}
//	void setYear(int y)
//	{
//		year = y;
//	}
//	int getDay() const
//	{
//		return day;
//	}
//	int getMonth() const
//	{
//		return month;
//	}
//	int getYear() const
//	{
//		return year;
//	}
//};
//class myVector
//{
//	int * arrPtr;
//	int capacity;
//	int currentSize;
//public:
//	myVector()
//	{
//		currentSize = 0;
//		capacity = 2;
//		arrPtr = new int[capacity];
//		for (int i = 0; i < capacity; i++)
//		{
//			arrPtr[i] = 0;
//		}
//		cout << "default array of size 2 created.\n";
//	}
//	myVector(int parameter)
//	{
//		currentSize = 0;
//		capacity = parameter;
//		arrPtr = new int[capacity];
//		for (int i = 0; i < capacity; i++)
//		{
//			arrPtr[i] = 0;
//		}
//		cout << "parameterized constructor called with array size = " << capacity << endl;
//		delete[]arrPtr;
//		arrPtr = NULL;
//	}
//	void copy(int* arr, int size)
//	{
//		cout << "***deep copy created***\n";
//		capacity = size;
//		arrPtr = new int[capacity];
//		for (int i = 0; i < capacity; i++)//makes a deep copy of arr
//		{
//			arrPtr[i] = arr[i];
//		}
//	}
//	~myVector( )//destructor
//	{
//		delete[]arrPtr;
//		arrPtr = NULL;
//		cout << "array is deleted.";
//	}
//	int get()
//	{
//		cout << "copied arr = ";
//		for (int i = 0; i < capacity; i++)
//		{
//			cout << arrPtr[i] << " ";
//		}
//		cout << endl;
//		return capacity;
//	}
//};
//class student
//{
//	string rollno;
//	string name;
//	double cnic;
//	string degree;
//	string address;
//public:
//	student()
//	{
//		rollno = "22l-6666";
//		name = "lucifer";
//		cnic = 123456789;
//		degree = "BBA";
//		address = "White House, 51st street, Washington DC";
//	}
//	student(string r, string n, int id, string d, string house)
//	{
//		rollno = r;
//		name = n;
//		cnic = id;
//		degree = d;
//		address = house;
//	}
//	string getRollno() { return rollno; }//getters
//	string getName() { return name; }
//	int getCnic() { return cnic; }
//	string getDegree() { return degree; }
//	string getAddress() { return address; }
//	void setRollno(string a) { rollno=a; }//setters
//	void setName(string a) { name=a; }
//	void setCnic(int num) { cnic=num; }
//	void setDegree(string a) {  degree=a; }
//	void setAddress(string a) {  address=a; }
//	//input
//	void input()
//	{
//		cout << "enter rollno : ";
//		getline(cin, rollno);
//		cout << "name : ";
//		getline(cin, name);
//		cout << "enter cnic : ";
//		cin >> cnic;
//		cout << "enter degree name : ";
//		getline(cin, degree);
//		cout << "enter address : ";
//		getline(cin, address);
//		cout << endl;
//	}
//	//printer function
//	void print()
//	{
//		cout << "RollNo = " << rollno << endl;
//		cout << "Name = " << name << endl;
//		cout << "CNICv = " << cnic << endl;
//		cout << "Degree = " << degree << endl;
//		cout << "Address = " << address << endl;
//	}
//	
//
//};
