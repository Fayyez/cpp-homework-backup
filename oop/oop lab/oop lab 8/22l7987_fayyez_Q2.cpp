//#include<iostream>
//#include<string>
//#include<windows.h>
//#include<vector>
//using namespace std;
//class book
//{
//	string title, author;
//	int year;
//public:
//	book(const string& t="",const string& a="",const int& y=0)
//	{//parameterized default constructor
//		title = t;
//		author = a;
//		year = y;
//		//cout << title << " " << author << " " << year;
//	}
//	void display()
//	{
//		cout << "Book : " << title << "\tAuthor : " << author << "\tPub.Year : " << year;
//	}
//};
//class library
//{
//	vector<book*> ptr;
//	int count = 0;
//public:
//	//no need for a constructor as a default vector is created as an empty array
//	void addbook(book *bookToAdd)
//	{
//		count++;
//		ptr.push_back(bookToAdd);
//		cout << "book added successfully!!\n";
//		cout << "Total books = " << count<<endl;
//	}
//	void displayBooks(string str)
//	{
//		int number = 1;
//		cout << "list of all books in "<< str<<" is :\n";
//		for (book *i : ptr)
//		{
//			cout << number++ << ") ";
//			(*i).display();
//			cout << endl;
//		}
//		cout << endl;
//	}
//};
//int main()
//{
//	system("color 80");
//	book b1("Diwan-e-Arsh","Fayyez Farrukh",2003), b2("the hobbit","J.R.R.Tolkien",1954);
//	book b3("Harry Putar", "J.K. Rowling", 2001), b4("DUNE Messiah", "Frank Herbert", 1965);
//	library quaid_e_azam_library;
//	quaid_e_azam_library.addbook(&b1);
//	quaid_e_azam_library.addbook(&b2);
//	quaid_e_azam_library.addbook(&b3);
//	quaid_e_azam_library.addbook(&b4);
//	cout << endl;
//	quaid_e_azam_library.displayBooks("quaid-e-azam library");
//
//	system("pause");
//	return 0;
//}