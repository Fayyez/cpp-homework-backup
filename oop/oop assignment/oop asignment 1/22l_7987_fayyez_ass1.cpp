#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
void readSentence(char*& cArr, ifstream & read)
{
	int i = 0;
	for(; !read.eof();i++)//copies data from txt file into 1d array
	{
		if (read.eof()) break;
		read >>noskipws >> cArr[i];
	}
	cArr[i-1] = '\0';
}
void deallocate2dChar(char** &arr, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		delete[]arr[i];
		arr[i] = nullptr;
	}
	delete[]arr;
	arr = nullptr;
}
void deallocate3dChar(char***&arr,const int x)
{
	for (int i = 0; i < x; i++)
	{
		int j = 0;
		for (;arr[i][j][0]!='\0'; j++)
		{
			delete[]arr[i][j];
			arr[i][j] = nullptr;
		}
		delete[]arr[i][j];
		arr[i][j] = nullptr;
		delete[]arr[i];
		arr[i] = nullptr;
	}
	delete[]arr;
	arr = nullptr;
}
void printDic(const char* const* const& dic, const int &size)
{
	for (int i = 0; i < size; i++)
	{
		cout <<i+1<<") "<< dic[i] << endl;
	}
	cout << endl;
}
void deallocate1dChar(char*& arr)
{
	delete[]arr;
	arr = nullptr;
}
bool notPresent(const char *const* const & dataDic, char * const&word,const int & size,int & index)
{
	int wordLength = strlen(word);
	bool present = false;
	for (int i = 0; i < size; i++)//compares each row with the word to find duplicate
	{
		if (dataDic[i][0] == word[0])
		{
			present = true;
			int j = 1;
			for (; dataDic[i][j] != '\0' && word[j] != '\0'; j++)
			{
				if (dataDic[i][j] != word[j])
				{
					present = false;
					break;
				}
			}
			if (present && strlen(dataDic[i]) == wordLength)
			{				
				index = i;
				return false;//if duplicate found then returns false

			}
		}
	}
	return true;//returns true if duplicate is not found in dictionary
}
void growDic(char **& dataDic,char *const &word,int & rows,int columns)
{
	int newSize = rows + 1;
	char** newArr = new char *[newSize];
	for (int i = 0; i<rows; i++)//copies old dictionary
	{
		newArr[i] = new char[strlen(dataDic[i])+1];
		for (int j = 0;dataDic[i][j]!='\0'; j++)
		{
			newArr[i][j] = dataDic[i][j];
		}
		newArr[i][strlen(dataDic[i])] = '\0';//stores null terminator at end of each row
	}
	newArr[newSize - 1] = new char[columns + 1];
	for (int i = 0; word[i] != '\0'; i++)//to copy the new word
	{
		newArr[newSize - 1][i] = word[i];
	}
	newArr[newSize - 1][columns] = '\0';

	deallocate2dChar(dataDic, rows);
	rows = newSize;
	dataDic = newArr;
	newArr = nullptr;
}
void tokenize(char**&dic,char *const & data,int&size)//toknizes the 1d array for blank space & full stop
{
	char * wordToCheck = new char[50];
	int i = 0,temp=0;
	while(data[i]!='\0')
	{
		int x = 0;
		while (data[i] != ' ' && data[i] != '.' && data[i] != '\0')
		{
			wordToCheck[x++] = data[i++];
		}
		wordToCheck[x] = '\0';
		if (notPresent(dic,wordToCheck,size,temp))//checks for duplicates
		{
			growDic(dic,wordToCheck,size,strlen(wordToCheck));
		}
		while (data[i] == ' ' || data[i] == '.') i++;
	}
	deallocate1dChar(wordToCheck);
}
void inputSynonyms(char ***& synonyms,const char *const* const & dataDic,const int & y,const int & x)
{
	int k = 0;
	char* temp = new char [50];//stores synonym from user
	synonyms[x][0] = new char[strlen(dataDic[x]) + 1];
	while (dataDic[x][k]!='\0')//to save the og word in 1st rows
	{
		synonyms[x][0][k] = dataDic[x][k];
		k++;
	}
	synonyms[x][0][k] = '\0';
	for (int i = 1; i <= y; i++)//gets the synonyms from user
	{
		cin.clear();
		cin.ignore();
		cout << "Enter synonymn # " << i << " : ";
		deallocate1dChar(temp);
		char* temp = new char[50];
		cin.getline(temp, 49);//gets one synonym from user
		synonyms[x][i] = new char[strlen(temp) + 1];
		int z = 0;
		while (temp[z] != '\0')
		{
			synonyms[x][i][z] = temp[z];
			z++;
		}
		synonyms[x][i][z] = '\0';
	}
	deallocate1dChar(temp);
}
void getSynonyms(char***& synonyms, const char *const *const& dataDic,const int& numberOfwords, int *& countOfSynonyms,const int startingWord)
{
	int l = 0;
	char option = 'n';
	int numberOfSynonyms = 0;
	for (int i = startingWord; i < numberOfwords; i++)
	{
		option = 'n';
		numberOfSynonyms = 0;
		cout << "Do you wish to add synonyms for \"" << dataDic[i] << "\" (y/n) ? ";
     	cin >> option;
		while (option!='y'&&option!='n')//validate option
		{
			cin.ignore();
			cin.clear();
			cout << "invalid input.\n";
			cout << "enter again : ";
			cin >> option;
		}
		if (option == 'y')
		{
			cout << "How many synonyms of " << dataDic[i] << " do you wish to add my master : ";
			while(!(cin >> numberOfSynonyms) || numberOfSynonyms<0)//validates number of synonyms for each word
			{
				cin.clear();
				cin.ignore();
				cout << "invalid input.\nEnter again : ";
			}
		}//following snippit also runs if user wants to add no synonym to save the og word in synonyms[][]
		countOfSynonyms[l++] = numberOfSynonyms;//keep record of how many synonyms for each word are present
		synonyms[i] = new char* [abs(numberOfSynonyms)+2];//extra block will store only null terminator as sentinel value
		inputSynonyms(synonyms, dataDic, numberOfSynonyms,i);//allocates blocks for synonyms of dataDic[i]
		synonyms[i][numberOfSynonyms + 1] = new char[1];
		synonyms[i][numberOfSynonyms+1][0] = '\0';//save null terminator for last row of each synonyms block
	}
}
void initialize3dWithNull(char *** & synonyms, const int&size)
{
	for (int i = 0; i < size; i++)
	{
		synonyms[i] = nullptr;
	}
	cout << "***synonyms initialized with null***\n\n";
}
void findMatchingWordsInDic(const char*const*const&dataDic,const char*const& sentence, const int & size)
{
	char * wordToCheck = new char[50];
	int i = 0,matches=0,temp=0;
	while (sentence[i] != '\0')
	{
		int x = 0;
		while (sentence[i] != ' ' && sentence[i] != '.' && sentence[i] != '\0')
		{
			wordToCheck[x++] = sentence[i++];
		}
		wordToCheck[x] = '\0';
		if (!notPresent(dataDic, wordToCheck, size,temp))//checks for duplicates
		{
			matches++;
			cout <<"\"" << wordToCheck<<"\"" << " was found in dictionary, master!!\n";
		}
		while (sentence[i] == ' ' || sentence[i] == '.') i++;
	}
	cout << "total instances of repitition = " << matches << endl;
	deallocate1dChar(wordToCheck);

}
void replaceSynonyms(const char*const*const*const &synonyms,const int & size,  char * const*const&dataDic,char* &sentence,const int*const&noOfSynonyms )
{
	char* wordtoStore = new char[50], **temp=nullptr, option = 'n';
	int i = 0,wordsInTemp=0,k=0;
	while (sentence[i] != '\0')//breaks down sentence in each word
	{
		k = 0;
		while (sentence[i] != ' ' && sentence[i] != '.' && sentence[i] != '\0')
		{
			wordtoStore[k++] = sentence[i++];
		}
		wordtoStore[k] = '\0';
		growDic(temp, wordtoStore, wordsInTemp, strlen(wordtoStore));//stores the word in temp[][]
		while (sentence[i] == ' ' || sentence[i] == '.') i++;
	}
	cout << "\ntokenized sentence is :\n";
	printDic(temp, wordsInTemp);//to check if sentence was properly tokenized
	for (int i = 0; i < wordsInTemp; i++)
	{
		int index = 0;//saves the index of synonyms[][] or dictionary[] in which the word was found
		if (!notPresent(dataDic, temp[i], size,index))//if word is found in dictionary
		{
			cout << endl;
			cout << "\"" << temp[i] << "\" is found in dictionary!!\n";
			option = 'n';
			cout << "do you wish to replace \"" << temp[i] << "\" with its synonym master (y/n) ? ";
			cin >> option;
			while (option != 'y' && option != 'n')//validate option
			{
				cin.ignore();
				cin.clear();
				cout << "invalid input.\n";
				cout << "enter again : ";
				cin >> option;
			}
			if (option == 'n') continue;
			else if (noOfSynonyms[index] == 0)//if no synonym is present
			{
				cout << "i'm extremely ashamed master that i couldn't find a suitable synonym. Please forgive your slave.\n";
			}
			else if (option == 'y'&& noOfSynonyms[index]>0)//if synonym is present & user wants to replace it
			{
				int z = 1;
				cout << "Available options are :\n";
				while (z <= noOfSynonyms[index])//display available options
				{
					cout << z << ") " << synonyms[index][z]<<endl;
					z++;
				}
				do {//get which synonym to choose from user with validation
					cout << "please select one from above my master : ";;
					while (!(cin >> z))//validation of int input
					{
						cin.clear();
						cin.ignore();
						cout << "invalid input.\nEnter again : ";
					}
					if (z<1 || z>noOfSynonyms[index])
					{
						cout << "invalid input.";
					}
				} while (z<1 || z>noOfSynonyms[index]);
				deallocate1dChar(temp[i]);//to delete the last word
				temp[i] = new char[strlen(synonyms[index][z])+1];//declare a new row equal to size of synonym
				for (int j = 0; synonyms[index][z][j] != '\0'; j++)//replaces that word in temp with its synonym in synonym[][]
				{
					temp[i][j] = synonyms[index][z][j];
				}
				temp[i][strlen(synonyms[index][z])] = '\0';
			}
		}
	}
	cout << "sentence after replacing :\n";
	printDic(temp, wordsInTemp);
	int l = 0;
	deallocate1dChar(sentence);
	sentence = new char[2500];
	for (int i = 0; i < wordsInTemp; i++)//copies temp into sentence
	{
		if (i != 0) l++;
		for (int j = 0; j < strlen(temp[i]); j++)
		{
			sentence[l++] = temp[i][j];
		}
		sentence[l] = ' ';
	}
	sentence[l] = '.'; sentence[l+1] = '\0';
	deallocate2dChar(temp, wordsInTemp);
	deallocate1dChar(wordtoStore);
}
int main()
{
	system("color 04");
	ifstream read1("inputText.txt"), read2("case1.txt");
	char *cArr = new char[2500], ** dataDic=nullptr,*** synonyms=nullptr, * useCase1=new char[2500];
	int rowsOfDic_1 = 0, rowsOfDic_2 = 0;
	//task 1
	readSentence(cArr,read1); 
	cout <<"text to be tokenized is :\n" << cArr << endl;
	tokenize(dataDic,cArr,rowsOfDic_1);
	int* numberOfSynonymsOfEachWord = new int[rowsOfDic_1];
	cout << "Data Dictionary :\n";
	printDic(dataDic, rowsOfDic_1);
	rowsOfDic_2 = rowsOfDic_1;//2 stores words added from sentence 2
	system("pause");
	system("CLS");
	system("color 9f");
	//task2
	synonyms = new char** [rowsOfDic_1];
	initialize3dWithNull(synonyms,rowsOfDic_1);
	getSynonyms(synonyms,dataDic,rowsOfDic_1,numberOfSynonymsOfEachWord,0);
	//task3
	system("pause");
	system("CLS");
	system("color 8f");
	readSentence(useCase1, read2);
	cout <<"2nd Sentence is :\n" << useCase1 << endl<<endl;
	findMatchingWordsInDic(dataDic, useCase1, rowsOfDic_1);
	tokenize(dataDic,useCase1,rowsOfDic_2);//bonus of task3, stores unique words of useCase1 in dictionary
	cout << "\n***FOR BONUS***\n";
	cout << "Updated Data Dictionary :\n";
	printDic(dataDic, rowsOfDic_2);
	//task 4
	system("pause");
	system("CLS");
	system("color 08");
	cout << "sentence before replacement :\n"<<useCase1;
	replaceSynonyms(synonyms,rowsOfDic_1,dataDic,useCase1,numberOfSynonymsOfEachWord);
	system("pause");
	system("CLS");
	system("color 04");
	cout << "sentence after replacement :\n" << useCase1;
	//deallocation of all memory in heap
	deallocate2dChar(dataDic, rowsOfDic_1);
	deallocate1dChar(cArr);
	deallocate1dChar(useCase1);
	deallocate3dChar(synonyms, rowsOfDic_1);
	system("pause>0");
	return 0;
}