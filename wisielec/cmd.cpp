#include "cmd.h"
#include<sstream>
#include<vector>
using namespace std;

string parse_file(char* input)
{
	string s = input;
	if (s.compare(0,1,"-") == 0)
	{
		return "";
	}
	return s;
};

void printParam(cmdParam in)
{
	cout << "[" << in.short_name << "  | " << in.long_name << " ]:  " << in.description;
};

gameFiles parseOrDie(int argc, char** argv)
{
	cmdParam help = cmdParam("-h", "--help", "Show the help menu");
	cmdParam input = cmdParam("-i", "--input", "Show the help menu");
	cmdParam output = cmdParam("-w", "--output", "Show the help menu");
	bool input_found = false;
	bool output_found = false;
	string input_file_path;
	string output_file_path; 
	if (argc < 2) {
		cout << "No input parameters provided. Exiting" << endl;
		cout << "Please provide input and outfiles with their directory" << endl;
		cout << "For example: -w file1.txt -i file2.txt" << endl;// Print Help screen
		exit(1);
	}
	else {
		for (int i = 1; i < argc; i++)
		{
			//cout << argv[i] << endl;
			if (argv[i] == help.short_name || argv[i] == help.long_name)
			{
				cout << "Please provide input and outfiles with their directory" << endl;
				cout << "For example: -w file1.txt -i file2.txt" << endl;
			}
			if (argv[i] == input.short_name || argv[i] == input.long_name)
			{
				input_found = true;
				input_file_path = parse_file(argv[i + 1]);
				if (input_file_path == "")
				{
					cout << "input flag provided, but no file was given. Exiting\n";
					exit(1);
				}
			}
			if (argv[i] == output.short_name || argv[i] == output.long_name)
			{
				output_found = true;
				output_file_path = parse_file(argv[i + 1]);
				if (output_file_path == "")
				{
					cout << "input flag provided, but no file was given. Exiting\n";
					exit(1);
				}
			}
		}
	}
	cout << input_file_path << "|" << output_file_path << endl;
	if (input_found == true && output_found == true)
	{
		return gameFiles(input_file_path, output_file_path);
	}
	else
	{
		cout << "help guide\n";
		exit(1);
	}
	
};

void instruction()
{
	cout << "Your aim im the game is to prevent man from being hung." << endl;
	cout << "Guess keyword by giving single characters." << endl;
	cout << "Whenever you are mistaken, part of gallow is drawn. Guess the word before man is hanged!" << endl;
	cout << "I===" << endl;
	cout << "I  O" << endl;
	cout << "I -|-" << endl;
	cout << "I / /" << endl;
};
void Clear()
{
	cout << "\x1B[2J\x1B[H";
}
void printHangman(int score) {
	switch (score)
	{
	default:
		cout << "\nScore out of bounds\n";
		break;
	case 0:
		break;
	case 1:
		cout << "I" << endl;
		break;
	case 2:
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 3:
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 4:
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 5:
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 6:
		cout << "I===" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 7:
		cout << "I===" << endl;
		cout << "I  O" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 8:
		cout << "I===" << endl;
		cout << "I  O" << endl;
		cout << "I  |" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 9:
		cout << "I===" << endl;
		cout << "I  O" << endl;
		cout << "I -|" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 10:
		cout << "I===" << endl;
		cout << "I  O" << endl;
		cout << "I -|-" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		break;
	case 11:
		cout << "I===" << endl;
		cout << "I  O" << endl;
		cout << "I -|-" << endl;
		cout << "I /" << endl;
		cout << "I" << endl;
		break;
	case 12:
		cout << "I===" << endl;
		cout << "I  O" << endl;
		cout << "I -|-" << endl;
		cout << "I / /" << endl;
		cout << "I YOU ARE DEAD" << endl;
		cout << "GAME OVER" << endl;
		break;
	}


}
void printVector(vector<char> in)
{
	for (int i = 0; i < static_cast<int>(in.size()); i++)
	{
		cout << in[i] << " ";
	}
	cout << endl;
};
void printStatus(vector<char> invalid_guess, vector<char>hashed_vector)
{
	cout << "-> Incorrect guesses:  " << endl;
	
	printVector(invalid_guess);
	cout << "\n Codeword: \n";

	printVector(hashed_vector);
};

void NewPlayer()
{
	string name;
	char confirm;
	bool exit = false;
	cout << "Welcome to Hangman game. Please insert your name: \n";
	cin >> name;
	while (true)
	{
		cout << "Is " << name << " correct?  (Y/N)" << endl;
		cin >> confirm;
		switch (confirm)
		{
			case 'Y':
			case 'y':
				cout << "Good, now it's time to play\n\n" << endl;
				exit = true;
				break;
			case 'N':
			case 'n':
					cout << "Insert corect name: ";
					cin >> name;
					cout << "Is " << name << " correct?  (Y/N)" << endl;
					cin >> confirm;
			default:
				cout << "Unkown value. Please try again. Is " << name << " correct? (Y/N)" << endl;
				cin >> confirm;
				break;
		}
		if (exit)
			break;
	}
};
void printMenu()
{
	cout << "Main Menu" << endl;
	cout << "-> 1 | Start New Game  " << endl;
	cout << "-> 2 | Statistics" << endl;
	cout << "-> 3 | How Do I play?" << endl;
	cout << "-> 9 | Exit game " << endl;

};
void end_game(std::vector<char>hashed_vector, std::vector<char>keyword_vector)
{
	if (hashed_vector == keyword_vector)
	{
		
		cout << "Congratulations! You have guess the secret word corectly!\n";
	}
	else
	{
		cout << "Oh no! You've lost! Best luck next time\n";
	}
};
int StringToInt(string dirty )
{
	stringstream dirty_Value(dirty);
	int clean = 0;
	dirty_Value >> clean;
	return clean;
};
void NewGame()
{
	string keyword = "rabarbar";
	//Typ gry
	//string keyword = getKeywordFromFile()
	int keyword_size = keyword.length();
	vector<char>keyword_vector; //codeword  
	vector<char>invalid_guess; //incorrect
	vector<char>hashed_vector; //answer
	char guess;
	int score = 0;
	bool guessed_char = false; 
	for (int i = 0; i < keyword_size; i++)
	{
		keyword_vector.push_back(keyword.c_str()[i]);
		hashed_vector.push_back('*');
		//cout << "Keyword["<<i<< "] " << keyword_vector.at(i)<< " ";
		//cout << hashed_vector.at(i);
	}
	
	while ( hashed_vector!=keyword_vector && score < MAX_TRY_COUNT) //answers!= keyword && misses<Max_try_count 
	{
		printStatus(invalid_guess, hashed_vector);

		cout << "\n\n Enter your guess ";
		cin >> guess;

		for (int i = 0; i < static_cast<int>(keyword.length()); i++)
		{
			if (guess == keyword[i])
			{
				hashed_vector[i] = guess;
				guessed_char = true;
			}
		}
		if (guessed_char)
		{
			cout << "Correct " << endl; 
		}
		else
		{
			cout << "Inccorect! Try again.\n";
			invalid_guess.push_back(guess);
			score++;
		}
		guessed_char = false; 
		printHangman(score);
		}
	end_game(hashed_vector, keyword_vector);
	}


void GameLoop()
{
	string choice;
	while (true)
	{
		printMenu();
		cin >> choice; 

		switch (StringToInt(choice))
		{
		case 0:
			cout << "Input not understood. Please try again :) \n";
			break;
		case 1:
			NewPlayer();
			NewGame();
			break;
		case 2:
			//statystyki 
			break;
		case 3:
			instruction();
			break;
		case 9:
			return;
		default:
			cout << "Invalid value. Please try again :)\n";
			break;

	

		}
	}
};