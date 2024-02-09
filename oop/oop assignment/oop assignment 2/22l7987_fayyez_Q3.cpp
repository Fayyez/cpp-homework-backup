#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
//global arrays which store corresponding values of roman & arabic numbers 
char roman[8] = { 'I','V','X','L','C','D','M'};
int arabic[7] = {  1,  5,  10, 50,100,500,1000 };
int length = 7;
class romanInt;//forward declaration
class romanInt
{
	char * number_R;//stores the roman number (only the magnitude of arabic no.,i.e., no -ves)
	int number_A;//stores the integer equivalent of roman number
	size_t size;//stores length of number_R without null terminator
public:
	
	////Constructors & Destructor////
	romanInt()
	{//default constructor initializes the roman no. as 0
		number_R = new char[1];
		number_R[0] = '\0';
		//cout << strlen(number_R);
		size = strlen(number_R);
		number_A = 0;
	}
	romanInt(char *  arr)
	{//parameterized constructor initializes roman no. with a char array[]
		number_R = new char[strlen(arr) + 1];
		for (int i = 0; i < strlen(arr) + 1; i++) number_R[i] = arr[i];
		size = strlen(number_R);
		number_A = convertToInt();
	}
	romanInt(const romanInt& obj)
	{//copy constructor
		this->number_R = new char[obj.size + 1];
		this->size = obj.size;
		for (int i = 0; i <= size; i++) this->number_R[i] = obj.number_R[i];
		this->number_A = obj.number_A;
	}
	~romanInt()
	{//destructor also deletes the char array to revent memory leak
		delete[]number_R;
		number_R = nullptr;
	}
    
	///Getters///
	char* getNumber_R() const { return number_R; }
	int getNumber_A() const { return number_A; }
	size_t getSize() const { return size; }

	////Converters & Display////
	int convertToInt();
	void growNumber_R(const char& a);
	char* convertToRoman();
	void display()
	{
		cout << number_R << " = " << number_A << endl;
	}

	////Operator Overloadings////
	//basic arithmetic operators
	romanInt operator = (const romanInt& obj);
	romanInt operator + (const romanInt& obj);
	romanInt operator - (const romanInt& obj);
	romanInt operator * (const romanInt& obj);
	romanInt operator / (const romanInt& obj);
	//comparison operators
	bool operator == (romanInt obj)
	{
		if (this->number_A == obj.number_A) return true;
		else return false;
	}
	bool operator != (romanInt obj)
	{
		if (this->number_A != obj.number_A) return true;
		else return false;
	}
	bool operator > (romanInt obj)
	{
		if (this->number_A > obj.number_A) return true;
		else return false;
	}
	bool operator < (romanInt obj)
	{
		if (this->number_A < obj.number_A) return true;
		else return false;
	}
	//increment and decrement operators
	romanInt operator ++ ();
	romanInt operator ++ (int);
	romanInt operator -- ();
	romanInt operator -- (int);

};
romanInt temporaryObj;//temp obj to be used in some methods

////Converters & Display////
int romanInt::convertToInt()
{//converts a roman number to its arabic counterpart
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (number_R[i] == roman[0])
		{//for I
			if (number_R[i + 1] == roman[1] || number_R[i + 1] == roman[2]) sum -= arabic[0];
			else sum += arabic[0];
		}
		else if (number_R[i] == roman[1]) sum += arabic[1];//for V
		else if (number_R[i] == roman[2])
		{//for X
			if (number_R[i + 1] == roman[3] || number_R[i + 1] == roman[4]) sum -= arabic[2];
			else sum += arabic[2];
		}
		else if (number_R[i] == roman[3]) sum += arabic[3];//for L
		else if (number_R[i] == roman[4])
		{//for C
			if (number_R[i + 1] == roman[5] || number_R[i + 1] == roman[6]) sum -= arabic[4];
			else sum += arabic[4];
		}
		else if (number_R[i] == roman[5]) sum += arabic[5];//for D
		else if (number_R[i] == roman[6]) sum += arabic[6];//for M
	}
	return sum;
}
void romanInt::growNumber_R(const char& a)
{//adds one char to number_R[] of calling object
	int x = 0;
	char* temp = new char[size + 2];
	for (int i = 0; i < size; i++)
	{//copies number_R to temp till null terminator
		temp[x++] = number_R[i];
	}
	temp[x++] = a;
	temp[x] = '\0';
	delete[]number_R;
	number_R = temp;
	size += 1;
}
char* romanInt::convertToRoman()
{//converts the number_A of calling object into its roman counterpart
	delete[]number_R;
	number_R = new char[1];
	number_R[0] = '\0';
	size = 0;

	int noOfCharsToAdd = 0, x = 0;
	int num = abs(number_A);
	/*for negative numbers it will take only the magnitude of the arabic number
	 and convert it into roman*/
	noOfCharsToAdd = num / 1000;//for M's = 1000
	while (noOfCharsToAdd > 0)
	{
		growNumber_R(roman[6]);
		num -= arabic[6];
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 900;//exceptional case for CM = 900
	if (noOfCharsToAdd == 1)
	{
		growNumber_R(roman[4]);
		growNumber_R(roman[6]);
		num -= 900;
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 500;//for D's = 500
	while (noOfCharsToAdd > 0)
	{
		growNumber_R(roman[5]);
		num -= arabic[5];
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 400;//exceptional case for CD = 400
	if (noOfCharsToAdd == 1)
	{
		growNumber_R(roman[4]);
		growNumber_R(roman[5]);
		num -= 400;
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 100;//for C's = 100
	while (noOfCharsToAdd > 0)
	{
		growNumber_R(roman[4]);
		num -= arabic[4];
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 90;//exceptional case for XC = 90
	if (noOfCharsToAdd == 1)
	{
		growNumber_R(roman[2]);
		growNumber_R(roman[4]);
		num -= 90;
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 50;//for L's = 50
	while (noOfCharsToAdd > 0)
	{
		growNumber_R(roman[3]);
		num -= arabic[3];
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 40;//exceptional case for XL = 40
	if (noOfCharsToAdd == 1)
	{
		growNumber_R(roman[2]);
		growNumber_R(roman[3]);
		num -= 40;
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 10;//for X's = 10
	while (noOfCharsToAdd > 0)
	{
		growNumber_R(roman[2]);
		num -= arabic[2];
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 9;//exceptional case for IX = 9
	if (noOfCharsToAdd == 1)
	{
		growNumber_R(roman[0]);
		growNumber_R(roman[2]);
		num -= 9;
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 5;//for V's = 5
	while (noOfCharsToAdd > 0)
	{
		growNumber_R(roman[1]);
		num -= arabic[1];
		noOfCharsToAdd--;
	}

	noOfCharsToAdd = num / 4;//exceptional case for IV = 4
	if (noOfCharsToAdd == 1)
	{
		growNumber_R(roman[0]);
		growNumber_R(roman[1]);
		num -= 4;
		noOfCharsToAdd--;
	}

	while (num > 0)//for I's = 1
	{
		growNumber_R(roman[0]);
		num -= arabic[0];
	}

	return this->number_R;
}

////Operator Overloadings////
//basic arithmetic operators
romanInt romanInt::operator = (const romanInt& obj)
{//assignment operator creates a deep copy of obj.number_R in calling number_R
	delete[]number_R;
	this->number_R = new char[obj.size + 1];
	this->size = obj.size;
	for (int i = 0; i <= size; i++) this->number_R[i] = obj.number_R[i];
	this->number_A = obj.number_A;
	return *this;
}
romanInt romanInt::operator + (const romanInt& obj)
{
	temporaryObj.number_A = this->number_A + obj.number_A;
	temporaryObj.number_R = temporaryObj.convertToRoman();
	return temporaryObj;
}
romanInt romanInt::operator - (const romanInt& obj)
{
	temporaryObj.number_A = this->number_A - obj.number_A;
	temporaryObj.number_R = temporaryObj.convertToRoman();
	return temporaryObj;
}
romanInt romanInt::operator * (const romanInt& obj)
{
	temporaryObj.number_A = this->number_A * obj.number_A;
	temporaryObj.number_R = temporaryObj.convertToRoman();
	return temporaryObj;
}
romanInt romanInt::operator / (const romanInt& obj)
{
	temporaryObj.number_A = this->number_A / obj.number_A;
	temporaryObj.number_R = temporaryObj.convertToRoman();
	return temporaryObj;
}
//increment and decrement operators
romanInt  romanInt::operator ++ ()
{//prefix increment operator
	number_A += 1;
	convertToRoman();
	return *this;
}
romanInt  romanInt::operator ++ (int)
{//postfix increment operator
	temporaryObj = *this;
	number_A += 1;
	convertToRoman();
	return temporaryObj;
}
romanInt  romanInt::operator -- ()
{//prefix decrement operator
	number_A -= 1;
	convertToRoman();
	return *this;
}
romanInt  romanInt::operator -- (int)
{//postfix decrement operator
	temporaryObj = *this;
	number_A -= 1;
	convertToRoman();
	return temporaryObj;
}

bool validate(char arr[])
{//to validate char array input for the parameterized constructor of romanInt
	bool present = false;
	for (int i = 0; i < strlen(arr); i++)
	{//iterate for each element of arr[]
		present = false;//suppose arr[i] is not present
		for (int j = 0; j < length; j++)
		{//check for each element of arr[] in roman[]
			if (arr[i] == roman[j])
			{
				present = true;//if found in roman[] turn, then present
				break;//to reduce iterations
			}	
		}
		if (!present)//if still not present in roman[], return false
		{
			cout << "***Invalid input***\n";
			return present;
		}
	}
	return true;
}

int main()
{
	system("color 80");
	//user inputs with validation
	char arr1[51] = { '\0' }, arr2[51] = {'\0'};
	do {
		cout << "Enter a roman number r1 (in uppercase only) : ";
		cin.getline(arr1, 50);
	} while (!validate(arr1));
	do {
		cout << "Enter a 2nd roman number r2 (in uppercase only) : ";
		cin.getline(arr2, 50);
	} while (!validate(arr2));
	//constructor calls
	romanInt r1(arr1);
	romanInt r2(arr2);
	//operator checks
	system("pause");
	system("CLS");
	cout << "r1 = ";          r1.display();
	cout << "r2 = ";          r2.display();
	romanInt sum = r1 + r2, diff = r1 - r2, product = r1 * r2, div = r1 / r2;
	cout << "\nsum = ";       sum.display();
	cout << "difference = ";  diff.display();
	cout << "product = ";     product.display();
	cout << "quotient = ";    div.display();
	cout << "pre-increment r1 = ";    (++r1).display();
	cout << "pre-decrement r1 = ";   (--r1).display();
	system("pause");
	return 0;
}