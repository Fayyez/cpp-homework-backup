//#include<iostream>
//#include<vector>
//#include<windows.h>
//#include<string>
//using namespace std;
//class course;
//class student
//{
//	string sname;
//	static int studentIdGenerator;
//	int studentId;
//	vector<course*> courses;
//
//public:
//	student(string n = "")
//	{
//		sname = n;
//		studentId = studentIdGenerator++;
//	}
//	string getname()
//	{
//		return sname;
//	}
//	int getId()
//	{
//		return studentId;
//	}
//	void enrollCourse(course* c);
//	void displayCourses();
//	void display()
//	{
//		cout << "name : " << sname << "\tID : " << studentId;
//	}
//};
//int student::studentIdGenerator = 10001;
//class course
//{
//	string cname;
//	static int codeGenerator;
//	int code;
//	vector<student*> studentsinCourse;
//
//public:
//	course(string c = "")
//	{
//		cname = c;
//		code = codeGenerator++;
//	}
//	void enrollStudent(student* s);
//	void displayStudents();
//	void display()
//	{
//		cout << "cousrse : " << cname << "\tcode : " << code;
//	}
//
//};
//int course::codeGenerator = 01;
//void student::enrollCourse(course* c)
//{
//	courses.push_back(c);
//	(*c).enrollStudent(this);
//}
//void student::displayCourses()
//{
//	int number = 1;
//	cout << "list of enrolled courses by " << sname << " is :\n";
//	for (course* i : courses)
//	{
//		cout << number++ << ") ";
//		(*i).display();
//		cout << endl;
//	}
//	cout << endl;
//}
//void course::enrollStudent(student* s)
//{
//	studentsinCourse.push_back(s);
//}
//void course::displayStudents()
//{
//	int number = 1;
//	cout << "list of students in " << cname << " is :\n";
//	for (student* i : studentsinCourse)
//	{
//		cout << number++ << ") ";
//		(*i).display();
//		cout << endl;
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	system("Color 80");
//	//some dummy objects
//	student* s1=new student("fayyez"), *s2 = new student("Danish"), *s3 = new student("bobo"),
//		*s4 = new student("eehab"), *s5 = new student("uffan");
//	course *c1=new course("maths"), *c2=new course("chem"),* c3=new course("bio");
//	s1->enrollCourse(c1);
//	s1->enrollCourse(c2);
//	s1->enrollCourse(c3);
//	s2->enrollCourse(c2);
//	s2->enrollCourse(c3);
//	s3->enrollCourse(c3);
//	//lists printing student-wise as well as course-wise
//	s1->displayCourses();
//	s4->displayCourses();
//	c3->displayStudents();
//	c1->displayStudents();
//
//	system("pause");
//	return 0;
//}