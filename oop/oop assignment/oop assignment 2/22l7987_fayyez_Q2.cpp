//#include<iostream>
//#include<Windows.h>
//#include<iomanip>
//using namespace std;
//class stringButBetter
//{
//	char* arr;
//	int size;
//
//public:
//
//	//constructors and destructor
//	stringButBetter();
//	stringButBetter(char *);
//	~stringButBetter();
//	stringButBetter(const stringButBetter&);
//
//	//methods
//	void print();
//	int length();
//	void convertToUpper();
//	void convertToLower();
//	char at(int);
//	stringButBetter substring(int, int);
//	int getStartingIndex(const stringButBetter&);
//	bool compare(const stringButBetter&);
//	//add wale functions for concate, prepend and +
//	stringButBetter add(stringButBetter&) const;
//	stringButBetter add(char) const;
//	stringButBetter add(const int) const;
//	stringButBetter add(float) const;
//
//	//concates & prepends
//	stringButBetter concate(stringButBetter&);
//	stringButBetter concate(char);
//	stringButBetter concate(const int&);
//	stringButBetter concate(float);
//	stringButBetter prepend(stringButBetter&);
//	stringButBetter prepend(char);
//	stringButBetter prepend(const int&);
//	stringButBetter prepend(float);
//
//	//operator overloading
//	stringButBetter operator =(const stringButBetter&);
//	char& operator [](int);
//
//	//addition overlaoding 
//	stringButBetter operator + (stringButBetter&);
//	stringButBetter operator + (char);
//	stringButBetter operator + (const int);
//	stringButBetter operator + (const float&);
//	friend stringButBetter& operator + (char, stringButBetter&);
//	friend stringButBetter& operator + (const int, stringButBetter&);
//	friend stringButBetter& operator + (const float&, stringButBetter&);
//
//	//comparison operators
//	bool operator == (const stringButBetter& obj);
//	bool operator != (const stringButBetter& obj);
//	bool operator > (const stringButBetter& obj);
//	bool operator < (const stringButBetter& obj);
//
//	//iostream operators
//	friend ostream& operator << (ostream&, stringButBetter&);
//	friend istream& operator << (istream&, stringButBetter&);
//};
//stringButBetter temp;
//stringButBetter alpha;//for add methods
//stringButBetter beta;
////constructors and destructor
//stringButBetter::stringButBetter()
//{//default constructor; initializes the string with only a null terminator
//	size = 1;
//	arr = new char[size];
//	arr[0]='\0';
//}
//stringButBetter::stringButBetter(char * word)
//{//parameterized constructor;
//	int newSize = 1;
//	for (int i = 0; word[i]!='\0'; i++)newSize++;//to get size of word
//	size = newSize;
//	arr = new char[size];
//	arr[size - 1] = '\0';
//	for (int i = 0; word[i] != '\0'; i++)
//	{//copies word into arr
//		arr[i] = word[i];
//	}
//}
//stringButBetter::stringButBetter(const stringButBetter & obj)
//{//copy constructor
//	this->size = obj.size;
//	arr = new char[size];
//	for (int i = 0; i<size; i++)
//	{
//		this->arr[i] = obj.arr[i];
//	}
//}
//stringButBetter::~stringButBetter()
//{//destructor
//	delete[] arr;
//	arr = nullptr;
//}
//
////methods
//int stringButBetter::length()
//{
//	return size - 1;
//}
//void stringButBetter::print()
//{
//	cout <<size<<": "<< arr << endl;
//}
//void stringButBetter::convertToLower()
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		if (arr[i] >= 65 && arr[i] <= 90)
//		{
//			arr[i] = arr[i] + 32;
//		}
//	}
//}
//void stringButBetter::convertToUpper()
//{
//	for (int i = 0; i < size-1; i++)
//	{
//		if (arr[i] >= 97 && arr[i] <= 122)
//		{
//			arr[i] -= 32;
//		}
//	}
//}
//char stringButBetter::at(int index)
//{
//	while (!(index >= 0 && index < size - 1))
//	{
//		cout << "invalid index, enter value under " << size - 2 << " : ";
//		cin >> index;
//	}
//	return arr[index];
//}
//stringButBetter stringButBetter::substring(int start, int end)
//{
//	while (start < 0 || start >= size - 1)
//	{//validate starting index for substring
//		cout << "invalid starting point. Enter a value under " << size - 2 << " : ";
//		cin >> start;
//	}
//	while (end < start || end >= size - 1)
//	{//validate ending index for substring
//		cout<<"invalid end-point. Enter a value b/w " << size - 2 << " and "<<start<<": ";
//		cin >> end;
//	}
//	delete[] temp.arr;
//	temp.size = end-start+2;
//	temp.arr = new char[temp.size];
//	int k = 0;
//	for (int i = start; i <= end; i++)
//	{//copy relevent substring from calling object to temp arr & return temp object
//		temp.arr[k++] = arr[i];
//	}
//	temp.arr[k] = '\0';
//	return temp;
//}
//int stringButBetter::getStartingIndex(const stringButBetter& obj)
//{
//	bool found = false;
//	int k = 1;
//	for (int i = 0; i < size - 1; i++)
//	{
//		if (arr[i] == obj.arr[0])
//		{
//			found = true;
//			for (int j = i + 1; j < size - 1 && k < obj.size - 1; j++)
//			{
//				if (arr[j] != obj.arr[k++])
//				{
//					found = false;
//					break;
//				}
//			}
//			if (found&&k==obj.size-1) return i;
//		}
//	}
//	return -1;
//
//}
//bool stringButBetter::compare(const stringButBetter& obj)
//{//return true if both strings are of same size with same values at each index (case sensitive)
//	return (*this == obj);
//}
////add wale functions for concate, prepend and +
//stringButBetter stringButBetter::add( stringButBetter& obj) const
//{//adds a string to calling object
//	delete []alpha.arr;
//	alpha.size = size + obj.length();
//	alpha.arr = new char[alpha.size];
//	int k = 0;
//	for (int i = 0; i < size - 1; i++)
//	{//copy the calling object into alpha
//		alpha.arr[k++] = arr[i];
//	}
//	for (int i = 0; i < obj.size - 1; i++)
//	{//copy the data in arguement into alpha
//		alpha.arr[k++] = obj.arr[i];
//	}
//	alpha.arr[k] = '\0';
//	return alpha;
//}
//stringButBetter stringButBetter::add(char characterToInsert) const
//{//adds a single char to calling object
//	delete[]alpha.arr;
//	alpha.size = size + 1;
//	alpha.arr = new char[alpha.size];
//	int k = 0;
//	for (int i = 0; i < size - 1; i++)
//	{//copy the calling object into alpha
//		alpha.arr[k++] = arr[i];
//	}
//	alpha.arr[k++] = characterToInsert;
//	alpha.arr[k] = '\0';
//	return alpha;
//}
//stringButBetter stringButBetter::add(const int a) const
//{
//	delete[]alpha.arr;
//	int numberOfDigits = 0;
//	int num = a;
//	while (abs(num) > 0)
//	{//to get number of digits in the int value
//		numberOfDigits++;
//		num /= 10;
//	}
//	if (a < 0)
//	    alpha.size = size + numberOfDigits + 1;
//	else 
//		alpha.size = size + numberOfDigits;
//	alpha.arr = new char[alpha.size];
//	int k = 0;
//	for (int i = 0; i < size - 1; i++)
//	{//copy the calling object into alpha
//		alpha.arr[k++] = arr[i];
//	}
//	if (a < 0)
//		alpha.arr[k++] = '-';
//	k = alpha.size - 2;
//	num = abs(a);
//	for (int i = 0; i < numberOfDigits; i++)
//	{
//		alpha.arr[k--] = (num % 10) + 48;
//		num /= 10;
//	}
//	alpha.arr[alpha.size - 1] = '\0';
//	return alpha;
//
//}
//stringButBetter stringButBetter::add( float a) const
//{
//	delete[]beta.arr;
//	beta.arr = nullptr;
//	int numberOfDecimalDigits = 0;//to store the number of decimal places in float
//	int num = a;
//	//float wholeValueOfDecimal=num;
//	beta = add(num);//add the whole number part of float
//	float decimalNumber = (a-num);//stores the decimal part of float
//	decimalNumber = abs(decimalNumber);
//	decimalNumber = round(decimalNumber * 10000) / 10000;
//	while (decimalNumber != (int)decimalNumber)
//	{
//		decimalNumber *= 10;
//	}
//	num = round(decimalNumber * 10000) / 10000;
//	if (decimalNumber > 0)
//	{
//		beta = beta.add('.');
//		beta = beta.add(num);
//	}
//	return beta;
//}
//
////concates & prepends
//stringButBetter stringButBetter::concate(stringButBetter& obj) 
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(*this);
//	temp = temp.add(obj);
//	return temp;
//}
//stringButBetter stringButBetter::concate(char characterToInsert)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(*this);
//	temp = temp.add(characterToInsert);
//	return temp;
//}
//stringButBetter stringButBetter::concate(const int& x)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(*this);
//	temp = temp.add(x);
//	return temp;
//}
//stringButBetter stringButBetter::concate(float x)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(*this);
//	temp = temp.add(x);
//	return temp;
//}
//
//stringButBetter stringButBetter::prepend(stringButBetter& obj)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(obj);
//	temp = temp.add(*this);
//	return temp;
//}
//stringButBetter stringButBetter::prepend(char characterToInsert)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(characterToInsert);
//	temp = temp.add(*this);
//	return temp;
//}
//stringButBetter stringButBetter::prepend(const int& x)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(x);
//	temp = temp.add(*this);
//	return temp;
//}
//stringButBetter stringButBetter::prepend(float x)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(x);
//	temp = temp.add(*this);
//	return temp;
//}
//
//
////operator overloading
//stringButBetter stringButBetter::operator =(const stringButBetter& obj)
//{
//	size = obj.size;
//	delete[]arr;
//	arr = new char[size];
//	for (int i = 0; i < size-1; i++)
//	{
//		arr[i] = obj.arr[i];
//	}
//	arr[size - 1] = '\0';
//	return *this;
//}
//char& stringButBetter::operator [] (int index)
//{//
//	while (!(index >= 0 && index < size - 1))
//	{
//		cout << "invalid index, enter value under " << size - 2 << " : ";
//		cin >> index;
//	}
//	return arr[index];
//}
//
////addition operator
//stringButBetter stringButBetter::operator + ( stringButBetter& obj)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp=temp.add(*this);
//	temp=temp.add(obj);
//	return temp;
//}
//stringButBetter stringButBetter::operator + (char a)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(*this);
//	temp = temp.add(a);
//	return temp;
//}
//stringButBetter stringButBetter::operator + (const int a)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(*this);
//	temp = temp.add(a);
//	return temp;
//}
//stringButBetter stringButBetter::operator + (const float & a)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(*this);
//	temp = temp.add(a);
//	return temp;
//}
//stringButBetter& operator + (char a, stringButBetter& obj)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(a);
//	temp = temp.add(obj);
//	return temp;
//}
//stringButBetter& operator + (const int a, stringButBetter& obj)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(a);
//	temp = temp.add(obj);
//	return temp;
//}
//stringButBetter& operator + (const float& a, stringButBetter& obj)
//{
//	delete[]temp.arr;
//	temp.size = 1;
//	temp.arr = new char[temp.size];
//	temp.arr[0] = '\0';
//	temp = temp.add(a);
//	temp = temp.add(obj);
//	return temp;
//}
//
//
////comparison operators
//bool stringButBetter::operator == (const stringButBetter& obj)
//{
//	if (size != obj.size) return false;//when two strings have different sizes then they are obv not same
//	else//when sizes are same
//	{
//		bool found = true;
//		for (int i = 0; i < size - 1; i++)
//		{//compares values of each index till null terminator in both strings of same size
//			if (this->arr[i] != obj.arr[i])
//			{
//				found = false;
//				return found;
//			}
//		}
//		return found;
//	}
//}
//bool stringButBetter::operator != (const stringButBetter& obj)
//{
//	return !(*this == obj);
//}
//bool stringButBetter::operator > (const stringButBetter& obj)
//{
//	if (size > obj.size)
//		return true;
//	else return false;
//}
//bool stringButBetter::operator < (const stringButBetter& obj)
//{
//	if (size < obj.size)
//		return true;
//	else return false;
//}
//
////data streams
//ostream& operator<<(ostream& out, stringButBetter& obj)
//{
//	out << obj.arr;
//	return out;
//}
//istream& operator >> (istream& in, stringButBetter& obj)
//{
//	char arrToInsert[101]{'\0'};
//	cout << "Enter string to insert (upto 100 chars) : ";
//	cin.ignore();
//	cin.clear();
//	cin.getline(arrToInsert, 100);
//	stringButBetter enteredString(arrToInsert);
//	obj = enteredString;
//	return in;
//}
//int main()
//{
//	system("color 8f");
//	char temp[] = "Object~Oriented~Programming";
//	char temp2[] = "hello peter";
//	stringButBetter s4(temp2);//default constructor declare empty array will null terminator only
//	stringButBetter s2(temp);//parameterized constructor initializes the string with given char array[]
//	stringButBetter s3(s2);//copy constructor
//	cout << "s2 = " << s2 << endl;
//	s2.convertToUpper();//converts all alphabets to upercase
//	cout << "s2 (in upperCase) = " << s2 << endl;
//	s2.convertToLower();//converts all alphabets to lowercase
//	cout << "s2 (in lowerCase) = " << s2 << endl;
//	cout << "length of s2 = " << s2.length() << endl;
//	stringButBetter sub = s2.substring(0, 27);//get a substring from (index_start,index_end)
//	cout << "required substring = " << sub << endl;
//	if (s2.getStartingIndex(sub) == -1)
//	{
//		cout << "***substring not found***\n";
//	}
//	else cout << "starting index of \"" << sub << "\" = " << s2.getStartingIndex(sub) << endl;
//	s3.convertToLower();
//	////comparisons
//	system("pause>0");
//	system("CLS");
//	cout << "s2 = " << s2 << endl;
//	cout << "s3 = " << s3 << endl;
//	cout << "s4 = " << s4 << endl;
//	if (s3.compare(s2)) cout << "s2 and s3 are same.\n";
//	else cout << "s2 and s3 are not same\n";
//	if (s2 != s4) cout << "s2 & s4 are not same.\n";
//	else cout << "s2 & s4 are same.\n";
//	//concatenate, prepends and +
//	char a = 'a';
//	float f1 = -12.3012;
//	cin >> s4;
//	cout << "s4 = " << s4 << endl;
//	stringButBetter sum;
//	sum = s4 + -420;
//	cout << "string + int  = " << sum << endl;
//	stringButBetter sum2 = s4 + a ;
//	cout << "string + char = " << sum2 << endl;
//	stringButBetter sum3 = f1 + s4;
//	cout << "float + string = " << sum3 << endl;
//
//	system("pause");
//	return 0;
//}