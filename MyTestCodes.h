#pragma once

//Libraries Used
#include <iostream> //Input/Output Stream For Console
#include <string>   //For String
#include <fstream>  //File Stream 
#include <vector>   //Changable Index Structure
#include <Windows.h>//For System Commands
#include <algorithm>//Easy Sorting For Arrays/Vectors ...
#include <iomanip>  //For Outputting With Given Precision
#include <cmath>    //Easy Math Functions
#include <stdio.h>  //Standart Input/Output For Given Types
#include <conio.h>  //For Getting Key Presses
#include <ctime>    //For Gettig Real Time


using namespace std;//Standart Namespace


//For Getting File's Format On Given Path
string ext(string path) 
{
	ifstream CFile(path); //Checking/Reading File
	bool opened = CFile.is_open(); //bool For Checking
	if (opened) // If Available
	{
		string ext = ""; //Set Extension To Nothing
		size_t size = path.size(); //Get Size Of Path
		size_t lastPos = size;     //Get LastPos(Will Be Used Later)
		char letter;               //Letter For Given Position
		bool ThereIsDot = false;   //Check If There Is Format
		for (size_t i = 0; i < size; i++) //Loop To Extract Chars
		{
			letter = path[i]; //Get Char On Given Index
			if (letter == '.') //If Symbol Is Dot 
			{
				lastPos = i; //Starting Index Of Format
				ThereIsDot = true; //There Is Format
			}
		}
		if (ThereIsDot) //If Format Is Given
		{
			for (size_t i = lastPos; i < size; i++) //Loop For Format Chars
			{
				letter = path[i]; //Get Char On Given Index
				ext += letter; //Get Format 
			}
			return ext; //Give Extension Of File
		}
		else
		{
			return "ERROR"; //Give ERROR If There Is No Extension
		}
	}
	else
	{
		return "ERROR"; //Give ERROR If File Not Opened
	}
}

//Print Extensions Of Given Files 
void printTypes(vector<string> paths)
{
	size_t size = paths.size(); //Number Of Files
	vector<string> text; //Text Files
	vector<string> image;//Image Files
	vector<string> audio;///Audio Files
	vector<string> video;//Video Files
	vector<string> other;//Other Files
	//Known Types
	string types[12] = { ".doc",".docx",".txt",".bmp",".jpg",".png",".avi",".mpg",".flv",".mp4",".wav",".mp3" };
	string file,type; //File And It's Type
	size_t sType = 12; //Total Knwon Types
	size_t lastPos; //LastPosition
	bool Found;///See If Format Is Found 
	for (size_t i = 0; i < size; i++) //Loop For Vector
	{
		Found = false; //Set Found To False 
		file = paths[i]; //Get File On Given Index
		type = ext(file); //Find Extension Of It
		for (size_t j = 0; j < sType; j++) 
		{
			//See If Type Is Known
			if (type == types[j])//For Array
			{
				lastPos = j; //Get Position
				Found = true; //Make It Found
				break; //Break The Nested(j) Loop
			}
		}

		if (Found) //If Type Is Known
		{
			//Text
			if (lastPos == 0 or lastPos == 1 or lastPos == 2)
			{
				text.push_back(file);
			}
			//Image
			else if (lastPos == 3 or lastPos == 4 or lastPos == 5)
			{
				image.push_back(file);
			}
			//Video
			else if (lastPos == 6 or lastPos == 7 or lastPos == 8 or lastPos == 9)
			{
				video.push_back(file);
			}
			//Audio
			else
			{
				audio.push_back(file);
			}
		}
		else
		{
			//Unknown
			other.push_back(file);
		}
		
	}
	//Size Of Given Files
	size_t sizeText = text.size();
	size_t sizeImage = image.size();
	size_t sizeVideo = video.size();
	size_t sizeAudio = audio.size();
	size_t sizeOther = other.size();


	//Printing Them
	cout << "Text Files : \n";
	for (size_t i = 0; i < sizeText; i++)
	{
		cout << text[i] << "\n";
	}
	cout << "\n";

	cout << "Image Files : \n";
	for (size_t i = 0; i < sizeImage; i++)
	{
		cout << image[i] << "\n";
	}
	cout << "\n";

	cout << "Video Files : \n";
	for (size_t i = 0; i < sizeVideo; i++)
	{
		cout << video[i] << "\n";
	}
	cout << "\n";

	cout << "Audio Files : \n";
	for (size_t i = 0; i < sizeAudio; i++)
	{
		cout << audio[i] << "\n";
	}
	cout << "\n";

	cout << "Other Files : \n";
	for (size_t i = 0; i < sizeOther; i++)
	{
		cout << other[i] << "\n";
	}
	cout << "\n";
}	 

//Set Text Color For Console
void setColor(string color)
{
	HANDLE col; 
	col = GetStdHandle(STD_OUTPUT_HANDLE); //Command Will Be Used
	int col_code = 7; //Default White Code
	//Check Colors
	if (color == "blue")
	{
		col_code = 1;
	}
	else if (color == "green")
	{
		col_code = 2;
	}
	else if (color == "cyan")
	{
		col_code = 3;
	}
	else if (color == "red")
	{
		col_code = 4;
	}
	else if (color == "purple")
	{
		col_code = 5;
	}
	else if (color == "darkYellow")
	{
		col_code = 6;
	}
	else if (color == "white")
	{
		col_code = 7;
	}
	else if (color == "grey")
	{
		col_code = 8;
	}
	else if (color == "brightBlue")
	{
		col_code = 9;
	}
	else if (color == "brightGreen")
	{
		col_code = 10;
	}
	else if (color == "brightCyan")
	{
		col_code = 11;
	}
	else if (color == "brightRed")
	{
		col_code = 12;
	}
	else if (color == "pink")
	{
		col_code = 13;
	}
	else if (color == "yellow")
	{
		col_code = 14;
	}
	else if (color == "brightWhite")
	{
		col_code = 15;
	}
	else
	{
		//Set Default White If Given Colour Is Unknown 
		col_code = 7;
	}
	//SetColor
	SetConsoleTextAttribute(col, col_code);
}

//Make String's All Char's To LowerCase
string lower(string input)
{
	size_t size = input.size();//Get Size Of String
	char symbol; // Char For Every Index
	string ans = ""; //Set Answer to Empty String
	for (size_t i = 0; i < size; i++) //Loop To Extract String
	{
		symbol = tolower(input[i]); //Set Char To It's Lowercase
		ans += symbol; //Add It To Answer String
	}
	return ans;//Give Answer
}

//Make String's All Char's To UpperCase
string upper(string input)
{
	size_t size = input.size(); //Get Size Of String
	char symbol;// Char For Every Index
	string ans = "";//Set Answer to Empty String
	for (size_t i = 0; i < size; i++)//Loop To Extract String
	{
		symbol = toupper(input[i]);//Set Char To It's Uppercase
		ans += symbol; //Add It To Answer String
	}
	return ans;//Give Answer
}

//Delete Every Space In String
string noSpace(string input)
{
	size_t size = input.size(); //Get Size Of String
	char symbol; // Get A Char For Every Index
	string ans = ""; //Set Answer To Empty String
	for (size_t i = 0; i < size; i++) //Loop For Extracting Char From String
	{
		symbol = input[i]; //set Symbol To Given Index's Char
		if (symbol != ' ')//If Symbol Is Not Space
		{
			ans += symbol; //Add It To Ansewr
		}
	}
	return ans; //Give Answer
}

//Check If Given String Is Palindrome
bool strPalindrome(string input1)
{
	//Note:
	//For Int Use It With (strPalindrome(stoi(number)))
	//Does Not Matter If:
	//LowerCase Or UpperCase
	//Has Space Or Not

	string def1 = lower(noSpace(input1));// Get Input As Lowercase And Nospace 
	string def2 = def1;//Take Copy Of It
	reverse(def1.begin(), def1.end()); //Reverse String
	return def1 == def2; //Check If They Are Same
}

//Convert Int To Char
char getChar(int num)
{
	//Note :
	//Here Char Will Not Have 
	//The Value It Has On ASCII
	//It Will Be Number Itself
	//Like:
	//getChar(5) Is Equal To '5'
	//Only Works With 1 digit
	char ans = num + 48;
	//Add 48 Beacuse
	//0's Value Is 48 On ASCII Table
	return ans; //Give Answer
}

int getInt(char symbol)
{
	//Note:
	//Same Rule Works On This One Too:
	//getInt('9') = 9
	//Only Works With 1 digit

	int ans = int(symbol) - 48; 
	//0's Value Is 48 On ASCII Table
	return ans; //Give Answer
}

//A FileManager Class
//Based On Ext() AndprintTypes() Functions
class FileManager
{
	//User Can Not See:
	private:

		string path, format;
		//Any File Or Format
		ifstream file;
		//To Check If File Exsists
		vector<string> paths;
		//Vector(All) Given Files
	
	//User Can See:
	public:

		//Add A File 
		void attach(string input) 
		{
			path =  input;//Get Private String As Input
			format = ext(path);//Also Find Format Of Its
			file.open(path);//Open That File
			paths.push_back(path);//Attach It To Vector
		}

		//Check If All Files Opened
		bool Opened()
		{
			size_t size = paths.size(); //Number  Of
			bool worked = true;//Check If Worked
			for (size_t i = 0; i < size; i++) //Loop
			{
				file.open(paths[i]); //Open File
				if (!file.is_open()) //If File Does Not Open
				{
					worked = false;//Not Worked
				}
			}
			return worked;//Return If Worked
		}
		
		//Print Those
		void show()
		{
			//Use Old Function Here
			printTypes(paths);
		}
	
};

//Print Every Char On ASCII Table
//Color Would Be Green Or LightGreen 
void ASCII()
{

	srand(time(NULL));
	char symbol;
	int color;
	string col;
	setColor("green");
	cout << "ASCII TABLE" << endl;
	for (int i = 28; i < 255; i++)
	{
		do
		{
			color = rand();
		} while (color != 0 and color != 1);
		if (color == 0)
		{
			col = "green";
		}
		else
		{
			col = "brightGreen";
		}
		setColor(col);
		col = -1;
		symbol = i;
		cout << i << '.' << ' ' << symbol << ' ';
	}
	cout << endl;
	setColor("white");
}
