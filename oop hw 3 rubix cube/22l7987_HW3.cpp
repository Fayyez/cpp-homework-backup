//#include<iostream>
//#include<windows.h>
//#include<cstdlib>
//#include<time.h>
//#include<cstring>
//#include<stdio.h>
//#include<wincon.h>
//#pragma comment(lib, "winmm.lib")
//using namespace std;
//
//void setCord(int columnPos, int rowPos)
//{//to set cordonates on console
//	HANDLE handle; 
//	COORD coord;
//	coord.X = columnPos;
//	coord.Y = rowPos;
//	handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(handle, coord);
//}
//void setColor(int desiredColor)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
//}
//const int colors = 6;
//// Color Codes:
//// 1: Red
//// 2: Blue
//// 3: Green
//// 4: White
//// 5: Yellow
//// 6: Orange
//
//void set_color(const int& i)
//{//sets the colors of backgrond according to the color code
//	if (i == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
//	else if (i == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
//	else if (i == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
//	else if (i == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
//	else if (i == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
//	else if (i == 6) setColor(96);
//}
//
//class face
//{
//	int** side;
//	const int size = 3;
//	static int color_code;
//
//public:
//	//constructors & destructor//
//	face()
//	{//default constructor for one face of rubrik's cube
//		side = new int* [size];
//		for (int i = 0; i < size; i++)
//		{//initialize a 3X3 int array
//			this->side[i] = new int[size];
//			for (int j = 0; j < size; j++)
//			{/*
//			 will automatically assign a color periodically
//			 to objects created from 1 to 6*/
//				side[i][j] = color_code;
//			}
//		}
//		color_code++;
//	}
//	~face()
//	{//destructor with 2D deallocation
//		for (int i = 0; i < size; i++)
//		{
//			delete[]this->side[i];
//			this->side[i] = NULL;
//		}
//		delete[]this->side;
//		this->side = NULL;
//	}
//	//methods//
//	int getSize() const { return size; }
//	void exposeSide()
//	{
//		cout << string(13, '~');
//		for (int i = 0; i < size; i++)
//		{ cout << "\n|";
//			for (int j = 0; j < size; j++)
//			{	
//				set_color(side[i][j]);
//				cout << " " << side[i][j] << " |";
//			}
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//		}
//		cout << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//		cout << string(13, '~');
//		cout << endl;
//	}
//	void exposeSide(int x,int y)
//	{
//		setCord(x, y++);
//		cout << string(13, '~');
//		for (int i = 0; i < size; i++)
//		{
//			setCord(x, y++);
//			cout << "|";
//			
//			for (int j = 0; j < size; j++)
//			{
//				set_color(side[i][j]);
//				cout << " " << side[i][j] << " |";
//			}
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//		}
//		cout << endl;
//		setCord(x, y);
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
//		cout << string(13, '~');
//		cout << endl;
//	}
//	void rotateAniclockwise(int x)
//	{//rotates a face anticlockwise x times
//		for (int k = 0; k < x; k++)
//		{
//			for (int j = 0; j < size - 1; j++)
//			{
//				swap(side[0][j], side[0][j + 1]);
//			}
//			for (int i = 0; i < size - 1; i++)
//			{
//				swap(side[i][size - 1], side[i + 1][size - 1]);
//			}
//			for (int j = size - 1; j > 0; j--)
//			{
//				swap(side[size - 1][j], side[size - 1][j - 1]);
//			}
//			for (int i = size - 1; i > 1; i--)
//			{
//				swap(side[i][0], side[i - 1][0]);
//			}
//		}
//	}
//	int*& operator[](int row)
//	{ 
//		return side[row];
//	}
//};
//int face::color_code = 1;
//class cube
//{
//	face * front, * back;
//	face * left, * right;
//	face * top, * bottom;
//	face* face_array[6];
//	
//public:
//	//constructors&destructor//
//	cube()
//	{//creates 6 faces of the cube with different colors each
//		front = new face; back = new face;
//		left = new face; right = new face;
//		top = new face; bottom = new face;
//		face_array[0] = front;
//		face_array[1] = back;
//		face_array[2] = left;
//		face_array[3] = right;
//		face_array[4] = top;
//		face_array[5] = bottom;
//	}
//	~cube()
//	{//destructor which also deallocates all the faces of the cube
//		delete front; delete back;
//		delete left; delete right;
//		delete top; delete bottom;
//		front = back = left = right = top = bottom = NULL;
//	}
//	//methods//
//	void validateOption(int& option1,int& option2)
//	{//validates option 1 against option 2 in range of 1-6
//		while (option1 < 1 || option1>6 || option1 == option2)
//		{
//			if (option1 == option2)
//			{ cout << "***Can't replace a side with itself***\n"; }
//			cout << "Invalid input. Select again : ";
//			cin >> option1;
//		}
//	}
//	void swapAnySide()
//	{
//		string names[6] = { "front","back","left","right","top","bottom" };
//		int option1=-1,option2=0;
//		
//		//taking user choices for the twofaces to be replaced
//		cout << "SELECT a Face, master :\n";
//		for (int i = 0; i < 6; i++)
//		{ cout << i + 1 << ") ENTER " << i + 1 << " for " << names[i] << endl; }
//		cout << "\nHere : ";
//		cin >> option1;
//		face_array[option1-1]->exposeSide();
//		validateOption(option1, option2);
//		cout << "which face do you wish to replace "<<names[option1-1] << " with, my master ? : \n";
//		for (int i = 0; i < 6; i++)
//		{ cout << i + 1 << ") ENTER " << i + 1 << " for " << names[i] << endl; }
//		cout << "\nHere : ";
//		cin >> option2;
//		validateOption(option2, option1);
//		//actual swapping 
//		for (int i = 0; i < front->getSize(); i++)
//		{
//			for (int j = 0; j < front->getSize(); j++)
//			{
//				swap( (*(face_array[option1 - 1]))[i][j], (*(face_array[option2 - 1]))[i][j]);
//			}
//		}
//		face_array[option1 - 1]->exposeSide();
//	}
//	void swap_front_top()
//	{//done by swapping the pointers to front & top face of cube
//		swap(front, top);
//		cout << "***SWAPPED***\n\n";
//	}
//	void rotate_left_column()
//	{//rotatews the front side 3 times and adjusts other sides accordingly
//		front->rotateAniclockwise(2);//rotates the front side
//		int size = front->getSize();
//		for (int i = 0; i < size; i++)//these loops will swap the remaining sides
//		{
//			swap((*left)[i][2],(*bottom)[0][i]);
//		}
//		for (int i = 0; i < size; i++)
//		{
//			swap((*left)[i][2], (*right)[size - 1 - i][0]);
//		}
//		for (int i = 0; i < size; i++)
//		{
//			swap((*left)[i][2], (*top)[2][size - 1 - i]);
//		}
//		cout << "***ROTATED***\n\n";
//	}
//	//displaying the cube//
//	void displayCube()
//	{
//		int x = 0, y = 2;
//		cout << "\n\n  **FRONT**";
//		x += 10;
//		setCord(x, y);
//		cout << "\t\t**LEFT**";
//		cout << "\t     **TOP**\n";
//		front->exposeSide();
//		left->exposeSide(21,3);
//		top->exposeSide(42, 3);
//		cout << endl << endl;
//		x = 0; y += 7;
//		setCord(x, y);
//		cout << "  **BACK**";
//		x += 10;
//		setCord(x, y++);
//		cout << "\t       **RIGHT**";
//		cout << "\t   **BOT-TOM**\n";
//		back->exposeSide();
//		right->exposeSide(21, y);
//		bottom->exposeSide(42, y);
//		cout << endl << endl;
//	}
//};
//void Welcome(const char c)
//{//display the welcome screen for the game
//	setCord(0, 15);
//	cout << string(211, c) << endl;
//	cout << "\t\t\t\t\t\t***WELCOME***\n";
//	cout << string(211, c) << endl;
//}
//void Ending()
//{//displays the ending screen for the game
//	system("Color F7");
//	int x = 0, y = 0;
//	for (int i = 0; i < 39; i++)
//	{
//		x = 2;
//		for (int j = 0; j < 3; j++)
//		{
//			x += 26;
//			setCord(x, y);
//			setColor((i + j + 1) % 13 + 1);
//			cout << "JHEELE inniya Mohabbatan!!";
//		}
//		Sleep(60);
//		y++;
//	}
//	system("pause>0");
//	system("CLS");
//}
//int main()
//{
//	system("color f0");
//	//setColor(96);//is black txt with orange background
//	srand(static_cast<unsigned int>(time(0)));
//	int option = 0;
//	cube c1;//declared the rubrik's cube
//	//welcome screen & initialization
//	Welcome('`');
//	system("pause>0");
//	system("CLS");
//	setCord(12, 0);
//	cout << "***INITIALIZING A CUBE FOR YOU***";
//	c1.displayCube();
//	system("pause");
//	system("CLS");
//	//start of game
//	PlaySound(TEXT("serious_music"), NULL, SND_ASYNC);
//	//PlaySound(TEXT("Cheb Khaled - C'est La Vie"), NULL, SND_ASYNC);
//	do
//	{//loop to run the main game
//		system("CLS");
//		option = -1;//to store user choice
//		cout << "1) ENTER 1 To Rotate front\n";
//		cout << "2) ENTER 2 To Replace front & Top\n";
//		cout << "3) ENTER 3 To Exit\n";
//		while (option < 1 || option > 3)
//		{//validate user choice of action to perform
//			cout << "HERE (1-3) : ";
//			cin >> option;
//		}
//		if (option == 1) c1.rotate_left_column();
//		else if (option == 2)
//		{
//			//c1.swapAnySide();
//			c1.swap_front_top();
//		}
//		else if (option == 3)
//		{//display ending screen & terminate loop
//			Ending();
//			continue;
//		}
//		system("pause");
//		system("CLS");
//		
//		cout << "\t\t***YOUR CUBE***";
//		c1.displayCube();
//		system("pause");
//	} while (option != 3);
//
//	return 0;
//
//}