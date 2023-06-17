#include<iostream>
#include"date.h";
using namespace std;
int main()
{
	student s1;
	cout << "rollno = " << s1.getRollno() << endl;
	cout << "name = " << s1.getName() << endl;
	cout << "cnic = " << s1.getCnic() << endl;
	cout << "degree = " << s1.getDegree() << endl;
	cout << "address = " << s1.getAddress() << endl;

	s1.setName("Habib Jalib");
	cout << "name (after setter) = " << s1.getName() << endl;
	s1.input();
	s1.print();

	return 0;
}