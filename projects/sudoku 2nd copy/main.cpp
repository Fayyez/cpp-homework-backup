#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<windows.h>
using namespace std;
const int row = 9, column = 9;//coordinates of the sudoku board
const int leaderboard_size = 7;

//Function Prototypes
string displayMainMenu(int);//displays main menu on console
/*Main Menu allows user to 1)play(continue to operation menu), 2)see credits, 3)see instructions*/
string displayOperationMenu(int);//to display operation menu on console
/*Main Menu allows user to 1)start new game(creates a new template from a solution), 2)open an existing game,
 3)go back to main menu*/
string displayModeSelectionMenu(int);//displays mode selection menu
/*Main Menu allows user to select a mode from easy, medium or hard which correspond to different numbers of #
 hints given in the template*/
string displaySavingMenu(int);//displays saving menu
/*allows usr to save his progress in any one of three slots*/
void createTemplate(int solution[][column], int Template[][column], int board[][column], int solution_current[][column], int);//creats a new sudoku template
void validateOption(string&, string, string, string);//validate choice of user from all the menus
void displayCredits(int);//show credits
void displayInstructions(int);//show instructions on console
bool validateNumber(string);//take inout between 1 and 9 only
void setCord(int, int);//to set coordinate of cursor on console
void printSudoku(int board[][column], int Template[][column],int);//print the sudoku board on console
void printSudoku(int board[][column], int Template[][column]);//print sudoku board for get solution (without score)
void takeInput(int Template[][column], int board[][column], int solution_current[][column], string slot,int&score);//function prototypes
bool checkRowColumnBox(int arr[][column], int i, int j, int valueToInsert);//validates user input into board
void createHeading(string, char);
void setColor(int);//change text color
void shuffle(int arr[][column]);//shuffles a 2D-array to make new solution
void showLoadingScreen(int);//shows a loading screen just like graphics which might give us extra absolutes
void sideMenu(string,string, int Template[][column], int board[][column],int user_score);//for side options of playing screen, i.e., save & quit from playing
void getSolution(string, int Template[][column], int solution_current[][column]);//to print solved sudoku board in case user asks for it in playing screen (takeInput)
bool checkEnding(int baord[][column]);//returns true when board is complete
void DisplayEndingScreen(int go);//displays kamaal kism ki ending screen FOR EXTRA ABSOLUTES 
void showLeaderBoard(int score[], string name[]);//leader board contain top 7 players with their scores
void sortArray(int arr[], int size, string name[]);//to sort leaderboard list

int main()
{
	
	ifstream Slot1_read("Slot1.txt"), Slot2_read("Slot2.txt"), Slot3_read("Slot3.txt");//reading streams for boards & Templates
	ifstream Template1_read("Template1.txt"), Template2_read("Template2.txt"), Template3_read("Template3.txt");
	ifstream Solved1_read("Solved1.txt"), Solved2_read("Solved2.txt"), Solved3_read("Solved3.txt");//in case user asks for the solution
	ifstream Slot1_score_read("Slot1_score.txt"), Slot2_score_read("Slot2_score.txt"), Slot3_score_read("Slot3_score.txt");//to read scores of slots
	ifstream leaderboard_read("SudokuLeaderBoard.txt"), leaderboard_score_read("scores.txt");//to read from leaderboard (containing top 7 player names)

	int solution1[row][column] = {//possible solutions of sudoku to get the template from
		4,3,5,2,6,9,7,8,1,
		6,8,2,5,7,1,4,9,3,
		1,9,7,8,3,4,5,6,2,
		8,2,6,1,9,5,3,4,7,
		3,7,4,6,8,2,9,1,5,
		9,5,1,7,4,3,6,2,8,
		5,1,9,3,2,6,8,7,4,
		2,4,8,9,5,7,1,3,6,
		7,6,3,4,1,8,2,5,9 };
	int solution2[row][column] = {
		7,3,5,6,1,4,8,9,2,
		8,4,2,9,7,3,5,6,1,
		9,6,1,2,8,5,3,7,4,
		2,8,6,3,4,9,1,5,7,
		4,1,3,8,5,7,9,2,6,
		5,7,9,1,2,6,4,3,8,
		1,5,7,4,9,2,6,8,3,
		6,9,4,7,3,8,2,1,5,
		3,2,8,5,6,1,7,4,9 };
	int solution3[row][column] = {
		1,5,2,4,8,9,3,7,6,
		7,3,9,2,5,6,8,4,1,
		4,6,8,3,7,1,2,9,5,
		3,8,7,1,2,4,6,5,9,
		5,9,1,7,6,3,4,2,8,
		2,4,6,8,9,5,7,1,3,
		9,1,4,6,3,7,5,8,2,
		6,2,5,9,4,8,1,3,7,
		8,7,3,5,1,2,9,6,4 };

	int Template[row][column] = { 0 };//template contains hints from solution and zeroes for all other indices
	int board[row][column] = { 0 };//initiate the board with zeroes
	int solution_current[row][column] = { 0 };//to store a solution of sudoku board in case user asks for it
	string leaderboard[leaderboard_size] = { "-","-","-","-","-","-","-" };//contains names of top 7 players
	int leaderboard_score[leaderboard_size] = { 0 };//contains scores of top 7 players
	int user_score=0;
	int playersInLeaderboard = 7;

	if (leaderboard_read.is_open())//if the are names in leaderboard then read into leaderboard[], scores in file into scores array
	{
		for (int i = 0; i < 7; i++)//reads scores
		{
			leaderboard_score_read >> leaderboard_score[i];
		}

		for (int i = 0; i < 7; i++)//reads names into leaderboard
		{
			char name_temp[25];//temp char to store the name as getline doesnt work for string[]
			leaderboard_read.getline(name_temp, 25, '\n');//getline instead of >> so white spaces are not skipped
			string str_name(name_temp);//temp string to convert the char[] into a string type variable
			leaderboard[i] = str_name;//store the temp str to relevant leaderboard index
		}
		leaderboard_score_read.close();
		leaderboard_read.close();
	}
	
	string option_mainMenu, option_operationMenu, option_difficultyLevel, option_savingMenu;//variables for user choice of different menus 
	do {//main loop for main menu
		PlaySound(TEXT("main_plus_pink"), NULL, SND_ASYNC);//play welcome to main mainu sound in english & urdu 
		option_mainMenu = displayMainMenu(1);//returns user choice of main menu
		if (option_mainMenu == "c")//if user asks for credits
		{
			displayCredits(1);
			continue;//go back to main menu
		}

		else if (option_mainMenu == "l")//if user asks for instructions
		{
			showLeaderBoard(leaderboard_score,leaderboard);
			continue;//go back to main menu
		}

		else if (option_mainMenu == "p")//if user asks for playing game go to operation menu
		{
			do {
				PlaySound(TEXT("pink_panther.wav"), NULL, SND_ASYNC);//play pink panther theme
				option_operationMenu = displayOperationMenu(1);//show operation & return user choice
				
				if (option_operationMenu == "n")
				{
					user_score = 10000;//reset score to 10,000 points for every new game

					for (int i = 0; i < row; i++)//reinitialize with zeros to create a new empty array
					{
						for (int j = 0; j < column; j++)
						{
							Template[i][j] = 0;
							board[i][j] = 0;
						}
					}
 		
					int hints_total = 0;//stores how many hints to print based on difficulty level
					option_difficultyLevel= displayModeSelectionMenu(1);//return user choice of difficulty level
					if (option_difficultyLevel == "e") { hints_total = 45; }
					else if (option_difficultyLevel == "m") { hints_total = 30; }
					else { hints_total = 15; }

					srand((unsigned int)time(0));//create a random number for choice of solution
					int choiceOfSolution = rand() % 3;//select one random solution to create Template from
					if (choiceOfSolution == 0) createTemplate(solution1, Template, board, solution_current,hints_total);
					if (choiceOfSolution == 1) createTemplate(solution2, Template, board, solution_current, hints_total);
					if (choiceOfSolution == 2) createTemplate(solution3, Template, board, solution_current, hints_total);
					option_savingMenu = displaySavingMenu(1);//get which slot to write in from user

					if (option_savingMenu == "1")//write new template&board into slot 1
					{
						ofstream Slot1_write("Slot1.txt"), Template1_write("Template1.txt"), Solved1_write("Solved1.txt"), Slot1_score_write("Slot1_score.txt");
						Slot1_score_write << user_score;
						for(int i = 0; i < row; i++)
						{
							for (int j = 0; j < column; j++)
							{
								Slot1_write << board[i][j] << " ";//create board file
								Template1_write << Template[i][j] << " ";//create template file
								Solved1_write << solution_current[i][j] << " ";//create solution file
							}
						}
						Slot1_write.close();//closing all files
						Template1_write.close();
						Solved1_write.close();
						Slot1_score_write.close();
					}
					if (option_savingMenu == "2")//write new template&board into slot 2
					{
						ofstream Slot2_write("Slot2.txt"), Template2_write("Template2.txt"), Solved2_write("Solved2.txt"), Slot2_score_write("Slot2_score.txt");
						Slot2_score_write<<user_score;
						for (int i = 0; i < row; i++)
						{
							for (int j = 0; j < column; j++)
							{
								Slot2_write << board[i][j] << " ";//create board file
								Template2_write << Template[i][j] << " ";//create template file
								Solved2_write << solution_current[i][j] << " ";//create solution file
							}
						}
						Slot2_write.close();
						Template2_write.close();
						Solved2_write.close();
						Slot2_score_write.close();
					}
					if (option_savingMenu == "3")//write new template & board into slot 3
					{
						ofstream Slot3_write("Slot3.txt"), Template3_write("Template3.txt"), Solved3_write("Solved3.txt"), Slot3_score_write("Slot3_score.txt");
						Slot3_score_write << user_score;

						for (int i = 0; i < row; i++)
						{
							for (int j = 0; j < column; j++)
							{
								Slot3_write << board[i][j] << " ";//create board file
								Template3_write << Template[i][j] << " ";//create template file
								Solved3_write << solution_current[i][j] << " ";//create solution file
							}
						}
						Slot3_write.close();
						Template3_write.close();
						Solved3_write.close();
						Slot3_score_write.close();
					}
				}

				else if (option_operationMenu == "s")
				{
					option_savingMenu = displaySavingMenu(1);
					if (option_savingMenu == "1")//reading Template & board from slot 1
					{
						if (!Slot1_read.is_open())//if slot is empty, prompt user & go back to operation menu
						{
							cout << "**** OOPS SLOT 1 IS EMPTY, START NEW GAME or SELECT ANOTHER SLOT ****\n\n";
							system("pause");
							continue;
						}
						else//when slot 1 has a file
						{
							Slot1_score_read >> user_score;//gets the score from slot 1
							for (int i = 0; i < row; i++)//read board and Template from slot 1
							{
								for (int j = 0; j < column; j++)
								{
									Slot1_read >> board[i][j];
									Template1_read >> Template[i][j];
									Solved1_read >> solution_current[i][j];//reads the solution of the template									
								}
							}
							Slot1_read.close();
							Template1_read.close();
							Solved1_read.close();
							Slot1_score_read.close();

						}
					}
					else if (option_savingMenu == "2")//reading Template & board from slot 2
					{
						if (!Slot2_read.is_open())//if slot 2 is empty, prompt user & go back to operation menu
						{
							cout << "**** OOPS, SLOT 2 IS EMPTY, START NEW GAME or SELECT ANOTHER SLOT ****\n\n";
							system("pause");
							continue;
						}
						else//when slot 2 has a file
						{
							Slot2_score_read >> user_score;//gets the score from slot 2
							for (int i = 0; i < row; i++)//read board and Template from slot 2
							{
								for (int j = 0; j < column; j++)
								{
									Slot2_read >> board[i][j];
									Template2_read >> Template[i][j];
									Solved2_read >> solution_current[i][j];//reads the solution of the template

								}
							}
							Slot2_read.close();
							Template2_read.close();
							Solved2_read.close();
							Slot2_score_read.close();
						}
					}
					else if (option_savingMenu == "3")//reading Template & board from slot 3
					{
						if (!Slot3_read.is_open())//if slot 3 is empty, prompt user & go back to operation menu
						{
							cout << "**** OOPS, SLOT 3 IS EMPTY, START NEW GAME or SELECT ANOTHER SLOT ****\n\n";
							system("pause");
							continue;
						}
						else//when slot 3 has a file
						{
							Slot3_score_read >> user_score;//gets the score from slot 3
							for (int i = 0; i < row; i++)//read board and Template from slot 3
							{
								for (int j = 0; j < column; j++)
								{
									Slot3_read >> board[i][j];
									Template3_read >> Template[i][j];
									Solved3_read >> solution_current[i][j];//reads the solution of the template		
								}
							}
							Slot3_read.close();
							Template3_read.close();
							Solved3_read.close();
							Slot3_score_read.close();
						}
					}
				}

				else if (option_operationMenu == "m") continue;

				PlaySound(TEXT("loading_screen.wav"), NULL, SND_ASYNC);//loading screen music
				showLoadingScreen(1);//just for extra absolutes

				do
				{//actual game

					takeInput(Template, board,solution_current, option_savingMenu, user_score);//takes input, prompts for repeating values

					if (!checkEnding(board))//if board is completed then display ending
					{
						DisplayEndingScreen(1);//diplay the ending screen
						
						if (user_score >= leaderboard_score[leaderboard_size - 1])//if user is among top 7 scorers
						{
							leaderboard_score[leaderboard_size - 1] = user_score;//add user_score to last index of top 7 score list
							string text = "\tCONGRATULATIONS, YOU ARE AMONG TOP 7 SCORERS OF ALL TIME\n\t\t\t\t        YOUR NAME WILL BE ADDED TO OUR LEADERBOARD";
							string name;
							createHeading(text, '~');
							do {
								cout << "Tell us your name (20 characters) : ";//ask user his name
								getline(cin,name);
								if (name.length() > 20)//when name is too long
								{
									cout << "input is too long. Please enter less than 20 characters.\n";
								}
							} while (name.length() > 20);//if name is greater than 24 characters then dont allow as it disturbs leaderboard
							leaderboard[leaderboard_size - 1]=name;//store name to last index of top 7 name list
							sortArray(leaderboard_score, leaderboard_size, leaderboard);//sort the leaderboard
							ofstream leaderboard_write("SudokuLeaderBoard.txt"), leaderboard_score_write("scores.txt");
							for (int i = 0; i < leaderboard_size; i++)
							{
									leaderboard_write << noskipws << leaderboard[i] << endl;//write name into leaderboard file
									leaderboard_score_write << leaderboard_score[i]<<endl;//write score into score file	
							}
							leaderboard_write.close();
							leaderboard_score_write.close();
						}
						showLeaderBoard(leaderboard_score, leaderboard);
						
						//after game is completed, delete that slot files from system
						if (option_savingMenu == "1")
						{
							remove("Slot1.txt");
							remove("Template1.txt");
							remove("Solved1.txt");
							remove("Slot1_score.txt");
						}
						else if(option_savingMenu == "2")
						{
							remove("Slot2.txt");
							remove("Template2.txt");
							remove("Solved2.txt");
							remove("Slot2_score.txt");
						}
						else if (option_savingMenu == "3")
						{
							remove("Slot3.txt");
							remove("Template3.txt");
							remove("Solved3.txt");
							remove("Slot1_score.txt");
						}
					}

				} while (!checkEnding(board));//loop exits when board is completed with valid input values, goes back to operation menu

			} while (option_operationMenu!="m");
		}

	} while (1);//infinite loop for the main menu

	return 0;
}
string displayMainMenu(int go)//display the main menu and return user choice 
{
	system("CLS");
	system("color f8");
	string heading = "\n\t\t\t\t      WELCOME TO BEST SUDOKU GAME EVER MADE\n";
	createHeading(heading, '=');
	string option;
	cout << "\n\t<p> TO PLAY\n";//display options for user
	cout << "\t<l> TO CHECK LEADERBOARD\n";//to display instructions
	cout << "\t<c> TO SEE GAME CREDITS\n\n";//to display game credits
	validateOption(option, "p", "l", "c");//input validation
	return option;

}
string displayOperationMenu(int go)
{
	system("CLS");
	system("color f1");
	string heading = "\t\t\tOPERATIONS MENU";//heading
	createHeading(heading, '=');
	string option="garbage";//store user choice
	cout << "\n\t<n> FOR NEW GAME\n";//to start a new game
	cout << "\t<s> FOR SAVED GAME\n";//to start a saved game
	cout << "\t<m> FOR GOING BACK TO MAIN MENU\n\n";//to go back to MainMenu || break the loop
    validateOption(option, "n", "s", "m");//input validation
	return option;
}
string displayModeSelectionMenu(int)
{
	system("CLS");
	system("color 1f");
	string heading = "\t\t\tMODE SELECTION";//heading
	createHeading(heading, '=');
	string option = "garbage";//stor usser choice of difficulty level
	cout << "\nPlease select a Difficulty level :\n";//display options for user
	cout << "\n\t<e> FOR EASY\n";
	cout << "\t<m> FOR MEDIUM\n";
	cout << "\t<h> FOR HARD\n\n";
	validateOption(option, "e", "m", "h");//input validation
	return option;
}
string displaySavingMenu(int go)//displays saving menu
{
	system("CLS");
	system("color 4e");
	string heading = "\t\t\tSAVING MENU";//heading
	
	createHeading(heading, '=');
	string option = "garbage";//to store the slot to save the board and template into
	cout << "SELECT ONE OF THESE SLOTS :\n\n";
	cout << "\n\t<1> TO SAVE INTO SLOT-1\n";
	cout << "\t<2> TO SAVE INTO SLOT-2\n";
	cout << "\t<3> TO SAVE INTO SLOT-3\n\n";
	validateOption(option, "1", "2", "3");//validation of user input
	return option;//return user choice
}
void createTemplate(int solution[][column], int Template[][column], int board[][column], int solution_current[][column], int hints_total)//create a new template
{
	shuffle(solution);//shuffle the solution thrice to 
	shuffle(solution);//create a new solution
	shuffle(solution);

	for (int i = 0; i < row; i++)//copies the solution into solution_current for future use
	{
		for (int j=0;j<column;j++)
		{
			solution_current[i][j] = solution[i][j];
		}
	}

	for (int n = 0; n < hints_total; n++)//copies upto hints_total indices of solution into template
	{
		int i = rand() % 9;//gets random rows i and columns j to copy
		int j = rand() % 9;
		Template[i][j] = solution[i][j];
	}

	for (int copy_row = 0; copy_row < row; copy_row++)//copies Template into board
	{
		for (int copy_column = 0; copy_column < column; copy_column++)
		{
			board[copy_row][copy_column] = Template[copy_row][copy_column];
		}
	}

}
void validateOption(string&input, string op1, string op2, string op3)//validations for menu
{
	do {//input must be either op1, op2 or op3
		cout << "enter your choice here : ";
		cin >> input;
		cin.ignore();
		if (input != op1 && input != op2 && input != op3)
		{
			cout << "Invalid input. Try again\n";
		}
	} while (input != op1 && input != op2 && input != op3);

}
void displayCredits(int go)
{
	system("CLS");
	system("Color 08");
	string text = "\t\t\t  CREDITS";
	createHeading(text, '~');
	setColor(80);
	
	cout << "\n\t\t\t\t\t\tDIRECTOR\n\n\n";
	cout << "\t\tEXECUTIVE PRODUCERS\t\t\t\t\tMANAGEMENT TEAM\n\n\n\n\n";
	cout << "\t\tSOUND MANAGEMENT TEAM\t\t\t\t\tSPONSNERS\n\n\n\n\n";
	cout << "\t\tAUDIO CREDITS\t\t\t\t\t\tVISUAL EFFECTS BY\n\n\n\n\n\n";
	cout << "\t\tSpecial Mentions";


	setCord(0, 3);
	setColor(8);
	cout << endl << endl;
	cout << "\t\t\t\t\t   Prof.Usama Hassan\n\n\n";
	cout << "\t\tFayyez Farrukh\t\t\t\t\t\tFayyez Farrukh\n";
	cout << "\t\tDanish Shakeel\t\t\t\t\t\tDanish Shakeel\n\n\n\n";
	cout << "\t\tFayyez Farrukh\t\t\t\t\t\tSheikh Bank Limited (SBL)\n";
	cout << "\t\tDanish Shakeel\t\t\t\t\t\tHajji Super Market\n\n\n\n";
	cout << "\t\tCheb Khaled - Ces't la vie\t\t\t\tFayyez&Danish Studios\n";
	cout << "\t\tJawad Ahmad - Hame tumse piyaar he\n";
	cout << "\t\tHenry Mancini - Pink Panther\n";
	cout << "\t\tRight S.Fred - Stand Up\n\n\n";
	cout << "\t\tAbdurrehman (TA) & Co.\n\n\n";
	
	system("\n\n\npause");
}
void displayInstructions(int go)
{
	system("CLS");
	system("color 56");
	cout << "credits ABC";
	system("pause");
}
bool validateNumber(string num)
{
	string arr[9] = { "1","2","3","4","5","6","7","8","9" };//compare input with 1 to 9 
	for (int i = 0; i < 9; i++)
	{
		if (num == arr[i])
			return true;//if input is between 1 and 9, return true
	}
	cout << "only numbers between 1 and 9 are acceptable!\n";
	return false;//if input is not equal to and number between 1 and 9
}
void setCord(int x, int y)//to set coordinates of cursor on console
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void printSudoku(int board[][column],int Template[][column], int score)
{
	system("CLS");
	system("color 04");
	cout << endl << endl;
	for (int i = 0; i < row; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < column; j++)
		{
			if (board[i][j] == 0)
			{
				cout << "-    ";
				if (j % 3 == 2)  cout << " ";
			}
			else
			{
				if (j % 3 == 2)
				{
					if (board[i][j] == Template[i][j]) setColor(2);//change text color to green for template numbers
				    cout << board[i][j] << " ";
					if (board[i][j] == Template[i][j]) setColor(4);//return to red for non-template numbers
			    }
				else
				{
					if (board[i][j] == Template[i][j]) setColor(2);//change text color to green for template numbers
					cout << board[i][j];
					if (board[i][j] == Template[i][j]) setColor(4);//return to red for non-template numbers
				}
				cout << "    ";
			}
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	setColor(8);
	int x = 20, y = 1, a = 18, b = 50;
	for (int i = 0; i < a; i++)
	{
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 69, y = 1;
	for (int i = 0; i < a; i++)
	{
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 20, y = 1;
	for (int i = 0; i < b; i++)
	{
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 20, y = 19;
	for (int i = 0; i < b; i++)
	{
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 37, y = 2;
	for (int i = 0; i < a - 1; i++)
	{
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 53, y = 2;
	for (int i = 0; i < a - 1; i++)
	{
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 22, y = 7;
	for (int i = 0; i < b - 3; i++)
	{
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 22, y = 13;
	for (int i = 0; i < b - 3; i++)
	{
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 18, y = 2;
	for (int i = 1; i < 10; i++)//prints the coordinates of y-axis
	{
		setCord(x, y);
		cout << i;
		y += 2;
	}
	x = 24, y = 0;
	bool piano = false;
	for (int i = 0; i < 9; i++)//prints the coordinates of x-axis
	{
		setCord(x, y);
		cout << i + 1;
		if (i % 3 == 2) x++;
		x += 5;
	}
	x = 80, y = 6;
	setCord(x, y);
	setColor(4);
	cout << "---------------------------" << endl; y++;//the side menu
	setCord(x, y); 
	cout << "| <s>     Save & Quit     |" << endl; y++;
	setCord(x, y);
	cout << "| <q>     Quit Playing    |" << endl; y++;
	setCord(x, y);
	cout << "| <?>     Solve & End     |" << endl; y++;
	setCord(x, y);
	cout << "---------------------------\n";
	x+=9,y = 3;
	setCord(x, y);
	setColor(80);
	cout << "SCORE = " << score;
	setColor(4);

	int r = 0, c = 20;
	setCord(r, c);
}
void printSudoku(int board[][column], int Template[][column])
{
	system("CLS");
	system("color 04");
	cout << endl << endl;
	for (int i = 0; i < row; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < column; j++)
		{
			if (board[i][j] == 0)
			{
				cout << "-    ";
				if (j % 3 == 2)  cout << " ";
			}
			else
			{
				if (j % 3 == 2)
				{
					if (board[i][j] == Template[i][j]) setColor(2);//change text color to green for template numbers
					cout << board[i][j] << " ";
					if (board[i][j] == Template[i][j]) setColor(4);//return to red for non-template numbers
				}
				else
				{
					if (board[i][j] == Template[i][j]) setColor(2);//change text color to green for template numbers
					cout << board[i][j];
					if (board[i][j] == Template[i][j]) setColor(4);//return to red for non-template numbers
				}
				cout << "    ";
			}
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	setColor(8);
	int x = 20, y = 1, a = 18, b = 50;
	for (int i = 0; i < a; i++)
	{
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 69, y = 1;
	for (int i = 0; i < a; i++)
	{
		setCord(x, y);
		cout << "||";
		y++;
	}
	x = 20, y = 1;
	for (int i = 0; i < b; i++)
	{
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 20, y = 19;
	for (int i = 0; i < b; i++)
	{
		setCord(x, y);
		cout << "==";
		x++;
	}
	x = 37, y = 2;
	for (int i = 0; i < a - 1; i++)
	{
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 53, y = 2;
	for (int i = 0; i < a - 1; i++)
	{
		setCord(x, y);
		cout << "|";
		y++;
	}
	x = 22, y = 7;
	for (int i = 0; i < b - 3; i++)
	{
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 22, y = 13;
	for (int i = 0; i < b - 3; i++)
	{
		setCord(x, y);
		cout << "-";
		x++;
	}
	x = 18, y = 2;
	for (int i = 1; i < 10; i++)//prints the coordinates of y-axis
	{
		setCord(x, y);
		cout << i;
		y += 2;
	}
	x = 24, y = 0;
	bool piano = false;
	for (int i = 0; i < 9; i++)//prints the coordinates of x-axis
	{
		setCord(x, y);
		cout << i + 1;
		if (i % 3 == 2) x++;
		x += 5;
	}
	x = 80, y = 6;
	setCord(0,20);
	setColor(4);
}
void takeInput(int Template[][column], int board[][column],int solution_current[][column], string slot, int&user_score)//takes + validates input in board, saves the file
{
	PlaySound(TEXT("serious_music.wav"), NULL, SND_ASYNC);
	printSudoku(board,Template,user_score);//display the current board

	int insert = 0;//actuall value to insert in the box
	int i, j;//row,column to input value
	string num;//all inputs are taken in string for easy validation

	do {//input for row
		cout << "enter the row where you want to insert a value : ";//ask user for row to insert a value
		cin >> num;//enter a string value
		if (num == "s" || num == "q")
		{
			sideMenu(num,slot,Template,board, user_score);
		}
		else if (num == "?")
		{
			getSolution(slot,Template, solution_current);
		}
	} while (!validateNumber(num));//take input till validation is done
	i = stoi(num);//when valid value is entered, read it to i for selected row number

	do {//input for column
		cout << "enter the column where you want to insert a value : ";//ask user for row to insert a value
		cin >> num;//enter a string value
		if (num == "s" || num == "q")
		{
			sideMenu(num,slot, Template, board, user_score);
		}
		else if (num == "?")
		{
			getSolution(slot,Template, solution_current);
		}
	} while (!validateNumber(num));//take input till validation is done
	j = stoi(num);//when valid value is entered, read it to i for selected column number

	--i, --j;//user entered from 1 to 9 but array starts from 0 to 8 so decrement in both row i and column j

	if (Template[i][j] == 0)//if template has zero at [i][j], then allow input
	{
		do {//read the number to be inserted in the box
			cout << "Enter value that you want to insert in the box : ";
			cin >> num;
			if (num == "s" || num == "q")
			{
				sideMenu(num, slot, Template, board,user_score);
			}
			else if (num == "?")
			{
				getSolution(slot, Template, solution_current);
			}
		} while (!validateNumber(num));//take input from 1 to 9

		insert = stoi(num);//int insert cuz num has to be compared to an int in board

		if (checkRowColumnBox(board, i, j, insert))//if validation returns true then save the number to corresponding index in board
		{
			board[i][j] = insert;
		}
		else//if user entered a repeating value then user will be prompted to again enter the 
		{
			user_score -= 50;//50 points are deducted from score on every wrong input
			system("pause");
			takeInput(Template,board,solution_current,slot,user_score);
		}
	}
	else//when user tries to alter a hint value
	{
		cout << "\n\n**** SORRY, YOU CANNOT CHANGE A HINT ****\n\n";
		system("pause");
		takeInput(Template,board,solution_current,slot, user_score);
	}
	cin.ignore();
}
bool checkRowColumnBox(int arr[][column],int i, int j, int valueToInsert)
{
	for (int n = 0; n < column; n++)//same row i and check all columns
	{
		if (arr[i][n] == valueToInsert)
		{
			string text = "\tVALUE is REPEATED in ROW";
			createHeading(text, '*');
			return false;
		}
	}
	for (int m = 0; m < row; m++)//same column j and check all rows
	{
		if (arr[m][j] == valueToInsert)
		{
			string text = "\tVALUE is REPEATED in COLUMN";
			createHeading(text, '*');
			return false;
		}
	}
	int startOfSmallBox_row=0, startOfSmallBox_column=0;
	startOfSmallBox_row = i - i % 3;//starting row and column of relevant small box
	startOfSmallBox_column = j - j % 3;
	for (int m = 0; m < 3; m++)//check for matching values in the small box
	{
		for (int n = 0; n < 3; n++)
		{
			if (arr[startOfSmallBox_row +m][startOfSmallBox_column+n]==valueToInsert)
			{
				string text = "\tVALUE is REPEATED in SMALLBOX";
				createHeading(text, '*');
				return false;
			}
		}
	}

	return true;
}
void createHeading(string text, char pattern)
{
	int numberOfPatternsInHeading = 119;
	for (int i = 0; i <= numberOfPatternsInHeading; i++) cout << pattern;
	cout << endl << "\t\t\t"<<text << endl;
	for (int i = 0; i <= numberOfPatternsInHeading; i++) cout << pattern;
	cout << endl;
}
void setColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
void shuffle(int arr[][column])//shuffles a 2D-array to make new solution
{
	srand((unsigned)time(0));
	int shuffle_row[3][9]{ 0 };
	int shuffle_coloumn[9][3]{ 0 };
	//num += 1;
	int row_shuffle_start = 0; // indicates the start of rows which will be shuffled with row 1,2,3   
	int coloumn_shuffle_start = 0;// indicates the start of coloumns  which will be shuffled with coloumn 1,2,3 
	int num = (rand() % 2) + 1;//will take a random number to shuffle a 3X9 array
	if (num == 1)
	{
		row_shuffle_start = 3;
	}
	else if (num == 2)
	{
		row_shuffle_start = 6;
	}
	for (int i = 0; i < 3; i++)//will store the 3 row and 9 coloumn in a another array to swap respectively
	{
		for (int j = 0; j < 9; j++)
		{
			shuffle_row[i][j] = arr[i + row_shuffle_start][j];
		}
	}
	for (int i = 0, k = row_shuffle_start; i < 3; i++, k++)//it will swap 3row,9coloumn with another 3row,9coloumn within game
	{
		for (int j = 0, l = 0; j < 9; j++, l++)
		{
			arr[k][l] = arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++)//it will print the stored 3row,9coloumns with swapped one
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = shuffle_row[i][j];
		}
	}
	num = (rand() % 2) + 1;
	if (num == 1)
	{
		coloumn_shuffle_start = 3;
	}
	else if (num == 2)
	{
		coloumn_shuffle_start = 6;
	}
	for (int i = 0; i < 3; i++)//will store the 9 rows and 3 coloumn in a another array to swap respectively
	{
		for (int j = 0; j < 9; j++)
		{
			shuffle_coloumn[j][i] = arr[j][i + coloumn_shuffle_start];
		}
	}
	for (int i = 0, k = coloumn_shuffle_start; i < 3; i++, k++)//it will swap 3row,9coloumn with another 9row,3coloumn within game
	{
		for (int j = 0, l = 0; j < 9; j++, l++)
		{
			arr[l][k] = arr[j][i];
		}
	}
	for (int i = 0; i < 3; i++)//it will print the stored 3row,9coloumns with swapped one
	{
		for (int j = 0; j < 9; j++)
		{
			arr[j][i] = shuffle_coloumn[j][i];
		}
	}
}
void showLoadingScreen(int go)
{
	system("CLS");
	system("color 00");
	int x = 0, y = 50;
	int perc = 0, a = 50, b = 16;
	for (int i = 0; i < 11; i++)
	{
		system("CLS");
		setCord(a+4, b);
		cout << perc << "%";
		setCord(a - 2, b - 2);
		setColor(i + 2);
		cout << "LOADING";
		Sleep(100);
		cout << "...";
		Sleep(100);
		cout << "...";
		Sleep(100);
		cout << "...\n";
		Sleep(600);
		setColor(i + 2);
		perc += 10;
	}
}
void sideMenu(string choice,string slot, int Template[][column], int board[][column], int user_score)//choice maybe save board or quit from playing without save
{
	string confirmation;
	if (choice == "q")//if user asked to quit from playing
	{
		cout << "\n**** DO YOU WISH TO SAVE THE GAME AS WELL ? (y/n) ****\n\n";
		do {
			cout << "enter here : ";
			cin >> confirmation;
			if (confirmation != "y" && confirmation != "n")
			{
				cout << "invalid input! Try again.";
			}
		} while (confirmation != "y" && confirmation != "n");
		
		if (confirmation == "n") { main(); }//main menu is called without saving moves
	}
	if (slot == "1")//write new template&board into slot 1
	{
		ofstream Slot1_write("Slot1.txt"), Slot1_score_write("Slot1_score.txt");
		Slot1_score_write << user_score;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				Slot1_write << board[i][j] << " ";
			}
		}
		Slot1_write.close();
		Slot1_score_write.close();
	}
	if (slot == "2")//write new template&board into slot 2
	{
		ofstream Slot2_write("Slot2.txt"),  Slot2_score_write("Slot2_score.txt");
		Slot2_score_write << user_score;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				Slot2_write << board[i][j]<<" ";
			}
		}
		Slot2_write.close();
		Slot2_score_write.close();
	}
	if (slot == "3")//write new template & board into slot 3
	{
		ofstream Slot3_write("Slot3.txt"), Slot3_score_write("Slot3_score.txt");
		Slot3_score_write << user_score;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				Slot3_write << board[i][j]<<" ";
			}
		}
		Slot3_write.close();
		Slot3_score_write.close();
	}
	cout << "\n\n**** FILE SAVED SUCCESSFULLY in SLOT-" << slot << " ****\n\n";
	system("pause");
	main();//main menu is called without saving moves

}
void getSolution(string slot, int Template[][column], int solution_current[][column])//displays the solution to user & deletes that slot files
{
	system("CLS");//clear the previous screen for solution printing
	PlaySound(TEXT("TumJeetoYaHaro"), NULL, SND_ASYNC);
	printSudoku(solution_current, Template);
	cout << "\t\t        -------------------------------------------";
	cout << "\n\t\t        |  **** HERE IS A POSSIBLE SOLUTION ****  |\n";
	cout << "\t\t        |   ****  GOING BACK TO MAIN MENU  ****   |\n";
	cout << "\t\t        -------------------------------------------\n\n";

	//after user asks for complete solution, delete files of that slot
	if (slot == "1")
	{
		remove("Slot1.txt");
		remove("Template1.txt");
		remove("Solved1.txt");
		remove("Slot1_score.txt");
	}
	else if (slot == "2")
	{
		remove("Slot2.txt");
		remove("Template2.txt");
		remove("Solved2.txt");
		remove("Slot2_score.txt");
	}
	else if (slot == "3")
	{
		remove("Slot3.txt");
		remove("Template3.txt");
		remove("Solved3.txt");
		remove("Slot3_score.txt");
	}
	system("pause");
	main();//goes back to main menu
}
bool checkEnding(int board[][column])//checks if board is complete or not
{
	bool IsComplete = true;//consider board is complete
	for (int i = 0; i < row; i++)//check ever index of board
	{
		for (int j = 0; j < column; j++)
		{
			if (board[i][j] == 0)
			{
				IsComplete = false;
				return IsComplete;
			}
		}
	}
	return IsComplete;
}
void DisplayEndingScreen(int go)
{
	system("Color F7");
	PlaySound(TEXT("Right_Said_Fred_-_Stand_Up_For_The_Champions"), NULL, SND_ASYNC);
	int x = 0, y = 0;
	for (int i = 0; i < 30; i++)
	{
		x = 15;
		for (int j = 0; j < 3; j++)
		{
			x += 16;
			setCord(x, y);
			setColor((i + j + 1) % 13 + 1);
			cout << "Congratulations";
			Sleep(100);

		}
		y++;
	}
	system("pause>0");
	system("CLS");
}
void showLeaderBoard(int score[], string name[])
{
	system("CLS");
	PlaySound(TEXT("Cheb Khaled - C'est La Vie"), NULL, SND_ASYNC);
	system("color 80");
	string text = "\t\t     LEADERBOARD";
	createHeading(text, '~');
	int x = 26, y = 3;
	int s = 51, l = 20;
	for (int i = 0; i < l - 2; i++)
	{
		setCord(x, y);
		for (int j = 0; j < s; j++)
		{
			if (i == 0 && j > 0)
			{
				cout << "-";
			}
			else if (j == 1 || j == s - 1)
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
		}
		y++;
	}
	setCord(x + 1, y);
	for (int i = 0; i < s - 1; i++)
	{
		cout << "-";
	}
	x = 51, y = 4;
	for (int i = 0; i < l - 4; i++)
	{
		setCord(x, y);
		cout << "|";
		y++;
	}
	setCord(x = 36, y = 5);
	cout << "LEADERS";
	setCord(x = 60, y = 5);
	cout << "SCORES";
	x = 28, y = 6;
	setCord(x, y);
	for (int i = 0; i < s - 3; i++)
	{
		if (i == 23)
			cout << "|";
		else
			cout << "-";
	}
	x = 28, y = 8;
	for (int j = 0; j < 7; j++)
	{
		setCord(x, y);
		for (int i = 0; i < s - 3; i++)
		{
			if (i == 23)
				cout << "|";
			else
				cout << "-";

		}
		y += 2;
	}
	setCord(0, 23);
	x = 28, y = 7;
	system("Color 80");
	for (int i = 0; i < 7; i++)
	{
		setCord(x, y);
		cout << i + 1 << ") " << name[i];
		x += 26;
		setCord(x, y);
		cout << score[i];
		y += 2;
		x -= 26;
	}
	setCord(0, 25);
	system("pause");

}
void sortArray(int arr[],int size,string name[])//sort a 1d int array
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		int key = arr[i];
		string name_temp = name[i];
		while (j >= 0 && arr[j] < key)
		{
			name[j + 1] = name[j];
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		name[j + 1] = name_temp;
	}
}
