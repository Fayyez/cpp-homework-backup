//#include<iostream>
//#include<cmath>
//#include<Windows.h>
//#include<iomanip>
//using namespace std;
//class vectorType
//{
//private:
//	double* x;
//	double* y;
//	double* z;
//public:
//	vectorType(double, double, double);
//	vectorType(const vectorType&);
//	~vectorType();
//	void print();
//	vectorType operator = (const vectorType&);
//	double operator *(const vectorType&);
//	double length();
//	double angle(const vectorType&);
//	vectorType operator + (const vectorType&);
//	vectorType operator - (const vectorType&);
//	vectorType& operator ++();
//	vectorType& operator ++(int);
//	vectorType& operator --();
//	vectorType& operator --(int);
//	friend istream& operator >> (istream&, vectorType&);
//	friend ostream& operator << (ostream&, vectorType&);
//	friend bool operator == (vectorType&, vectorType&);
//	friend bool operator != (vectorType&, vectorType&);
//};
//vectorType::vectorType(double a=0, double b=0, double c=0)//default parameterized constructor 
//{
//	x = new double; *x = a; 
//	y = new double; *y = b;
//	z = new double; *z = c;
//}
//vectorType::vectorType(const vectorType& obj)//copy constructor
//{
//	x = new double; *x = *obj.x;
//	y = new double; *y = *obj.y;
//	z = new double; *z = *obj.z;
//}
//vectorType::~vectorType()//destructor with memory desllocstion
//{
//	delete x, y, z;
//	x = nullptr;
//	y = nullptr;
//	z = nullptr;
//}
//vectorType temp;//global object of vectorType to be used as a temp variable;
//vectorType temp2;
//vectorType vectorType::operator = (const vectorType& obj)//assignment operator overloading
//{
//	*x = *obj.x;
//	*y = *obj.y;
//	*z = *obj.z;
//	return *this;
//}
//void vectorType::print()
//{
//	cout << "vetor = " << *x << " " << *y << " " << *z << endl;
//}
//double vectorType::operator *(const vectorType& obj)//returns the dot product of two vectors as double value
//{
//	double dotProduct=0;
//	dotProduct = (*x * *obj.x) + (*y * *obj.y) + (*z * *obj.z);
//	return dotProduct;
//}
//double vectorType::length()//returns length of the calling vector rounded to 3 decimal spaces
//{
//	double length=0;
//	length = pow(*x, 2) + pow(*y, 2) + pow(*z, 2);
//	length = sqrt(length);
//	return length;
//}
//double vectorType::angle(const vectorType& obj)
////return the angle between calling vector & obj in parameter in radians as a double value
//{
//	vectorType temp1=obj;//obj is copied in to temp1 cuz obj cant be accessed as it is passsed as const
//	double angle=0;
//	if ((*this * temp1) - (*this).length() * temp1.length() < 0.01 && (*this * temp1) - ((*this).length() * temp1.length()) >= 0)
//	{//when dot product is max, angle is 2pie=0 degrees.
//		cout << "Vectors are parallel\n";
//		return 0;
//	}
//	else if ((*this * temp1) + ((*this).length() * temp1.length()) > -0.01 && (* this * temp1) + ((*this).length() * temp1.length()) <= 0)
//	{//when dot product is min, angle is pie=180 degrees.
//		cout << "Vectors are anti-parallel\n";
//		return 3.1415;
//	}
//	angle = acos( (*this * temp1) / (this->length() * temp1.length()));
//	if (angle > 3.14159)
//	{//for 180<=angle<360
//		angle -= 3.14159;
//	}
//	angle = round(angle * 100) / 100;
//	
//	return angle;
//}
//vectorType vectorType::operator + (const vectorType& obj)
//{//addition operator overloading
//	*temp.x = *this->x + *obj.x;
//	*temp.y = *this->y + *obj.y;
//	*temp.z = *this->z + *obj.z;
//	return temp;
//}
//vectorType vectorType::operator - (const vectorType& obj)
//{//subtraction operator overloading
//	*temp.x = *this->x - *obj.x;
//	*temp.y = *this->y - *obj.y;
//	*temp.z = *this->z - *obj.z;
//	return temp;
//}
//vectorType& vectorType::operator ++()
//{//prefix increment operator
//	*x+=1; *y+=1; *z+=1;
//	return *this;
//}
//vectorType& vectorType::operator ++(int)
//{//postfix increment operator
//	*temp.x = *x;
//	*temp.y = *y;
//	*temp.z = *z;
//	*x += 1; *y += 1; *z += 1;
//	return temp;
//}
//vectorType& vectorType::operator --()
//{//prefix decrement operator
//	*x -= 1; *y -= 1; *z -= 1;
//	return *this;
//}
//vectorType& vectorType::operator --(int)
//{//postfix decrement operator
//	*temp.x = *x;
//	*temp.y = *y;
//	*temp.z = *z;
//	*x -= 1; *y -= 1; *z -= 1;
//	return temp;
//}
//istream& operator >> (istream& input, vectorType& obj)
//{
//	cout << "enter x component : ";
//	input >> *obj.x;
//	cout << "enter y component : ";
//	input >> *obj.y;
//	cout << "enter z component : ";
//	input >> *obj.z;
//	return input;
//}
//ostream& operator << (ostream& out, vectorType& obj)
//{
//	out << "(" << *obj.x << "," << *obj.y << "," << *obj.z << ")\n";
//	return out;
//}
//bool operator == ( vectorType& obj1,  vectorType& obj2)
//{
//	if (*obj1.x == *obj2.x && *obj1.y == *obj2.y && *obj1.z == *obj2.z)
//	{
//		return true;
//	}
//	else return false;
//}
//bool operator != (vectorType& obj1, vectorType& obj2)
//{
//
//	if (*obj1.x != *obj2.x || *obj1.y != *obj2.y || *obj1.z != *obj2.z)
//	{
//		return true;
//	}
//	else return false;
//}
//int main()
//{
//	system("color 8f");
//	vectorType u(2,2,2);
//	vectorType v(2,2,2);
//	cout << "u = " << u << "v = " << v;
//	double angle = v.angle(u);
//	cout << "theta (in radians) = " << angle << endl;
//	cin >> v;
//	double dotProduct = u * v;
//	vectorType difference = u - v;
//	vectorType sum = u + v;
//	cout << "u + v = " << sum;
//	cout<< "u - v = " << difference;
//	cout << "u * v = " << dotProduct << endl;
//	double length = u.length();
//	cout << "|u| = " << length << endl;
//	cout << "prefix increment :\n";
//	cout << "++u = " << ++u << endl;
//	//postfix decrement & assignment
//	v = (u--);
//	cout << "after assigmnet of decremented u :\n";
//	cout << "v = " << v <<"and u = "<<u;
//	cout << "checking for equivalency :\n";
//	if (v == u) cout << "equal\n";
//	if (v != u) cout << "unequal\n";
//	system("pause>0");
//	return 0;
//}
