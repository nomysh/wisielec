#include "library.h"
#include<sstream>
#include<vector>
using namespace std;

string ParseFile(char* input)
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
				input_file_path = ParseFile(argv[i + 1]);
				if (input_file_path == "")
				{
					cout << "input flag provided, but no file was given. Exiting\n";
					exit(1);
				}
			}
			if (argv[i] == output.short_name || argv[i] == output.long_name)
			{
				output_found = true;
				output_file_path = ParseFile(argv[i + 1]);
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
	printHangman(MAX_TRY_COUNT);
};
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
		cout << "I / \\" << endl;
		cout << "I" << endl;
		cout << "I" << endl;
		cout << "YOU ARE DEAD" << endl;
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
player NewPlayer(vector<player> *PlayerList)
{
	string name, dirty;
	char confirm;
	bool exit = false;
	while (true)
	{
		cout << "Welcome to Hangman game. Please insert your name: \n";
		cin >> name;
		if (name.size() > MAX_NAME_SIZE || name.size() == 0)
		{
			cout << "Your name is too long. Maximal character size is " << MAX_NAME_SIZE << endl;
		}
		else
		{
			cout << "Is " << name << " correct?  (Y/N)" << endl;
			cin >> dirty;
			if (dirty.size() > 1)
			{
				cout << "Input not understood " << endl;
				continue;
			}
			confirm = dirty.front();
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
				cin >> dirty;
				if (dirty.size() > 1)
				{
					cout << "Input not understood " << endl;
					continue;
				}
				confirm = dirty.front();

			default:
				cout << "Unkown value. Please try again. Is " << name << " correct? (Y/N)" << endl;
				cin >> dirty;
				if (dirty.size() > 1)
				{
					cout << "Input not understood " << endl;
					continue;
				}
				confirm = dirty.front();
				break;
			}
		}
		
		if (exit)
			break;
	}
	player NewPlayer = FindPlayer(PlayerList, name);
	return NewPlayer;
};
void printMenu()
{
	cout << "Main Menu" << endl;
	cout << "-> 1 | Start New Game  " << endl;
	cout << "-> 2 | Statistics" << endl;
	cout << "-> 3 | How Do I play?" << endl;
	cout << "-> 9 | Exit game " << endl;

};
void EndGame(std::vector<char>hashed_vector, std::vector<char>keyword_vector, player *P)
{
	if (hashed_vector == keyword_vector)
	{
		cout << "Codeword: " << endl;
		printVector(keyword_vector);
		cout << "Congratulations! You have guess the secret word corectly!\n";
		P->wins++;
	}
	else
	{
		cout << "Oh no! You've lost! Best luck next time\n";
		cout << "Correct anwser was " << endl;
		printVector(keyword_vector);
		P->loses++;
	}
};
int StringToInt(string dirty )
{
	stringstream dirty_Value(dirty);
	int clean=0;
	dirty_Value >> clean;
	return clean;
};
int pickCategory(std::vector<std::vector<std::string>> in)
{
	//print categories
	cout << "-> 1 Random Category" << endl;
	csvPrint(in, false);
	int categoryID;
	string dirty;
	while (true)
	{
		cout << "Pick a number coresponding to the category or press 1 to pick a random one. " << endl;
		cin >> dirty;
		categoryID = StringToInt(dirty);
		if (categoryID > in.size()+1 || categoryID < 1)
		{
			cout << "No valid category found. Please select another valid one. \n";
		}
		else
		{
			break;
		}
	}
	//while case wybor
	//return wybor 
	return categoryID;
};
void NewGame(std::vector<std::vector<std::string>> in, player *P)
{
	string keyword = GetKeyword(in, pickCategory(in));
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
		guess = tolower(guess);
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
	EndGame(hashed_vector, keyword_vector, P);
	}
void GameLoop(std::vector<std::vector<std::string>> in, vector<player> *PlayerList)
{
	player P;
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
			P = NewPlayer(PlayerList);
			PrintPlayer(&P);
			NewGame(in, &P);
			UpdatePlayerList(PlayerList,&P);
			break;
		case 2:
			sortPlayerList(PlayerList);
			printPlayerList(PlayerList);
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
string GetKeyword(vector<vector<string>> csv,int category) {
	int tmp = category-2;
	if (category==1 )
	{
		tmp= 1 + rand() % (csv.size()-1 );
	
	}
	vector<string>chosenCategory = csv.at(tmp);
	cout << "Your category is " << chosenCategory.front()<<endl;
	int random = 1+ rand() % (chosenCategory.size()-1);
	return chosenCategory.at(random);
	//randomizowanie hasla 
	
};
vector<vector<string>> csvRead(std::string filename, bool lower) {
	std::vector<string> row;
	vector<vector<string>> result;
	std::ifstream myFile(filename);

	if (!myFile.is_open()) throw std::runtime_error("Could not open file");
	string line, item;

	if (myFile.is_open()) {
		while (getline(myFile, line))
		{
			row.clear();
			stringstream str(line);
			while (getline(str, item, CSV_SELECTOR))
			{
				if (lower)
				{
					std::transform(item.begin(), item.end(), item.begin(),
						[](unsigned char c) { return std::tolower(c); });
				}
				
				row.push_back(item);
			}

			result.push_back(row);
		}
	}
	myFile.close();
	return result;
}
void csvWrite(string filepath,vector<player> * List) 
{
	fstream fout;
	fout.open(filepath, ios::out | ios::trunc);
	for (int i = 0; i < static_cast<int>(List->size()); i++)
	{
		fout << List->at(i).name << CSV_SELECTOR << List->at(i).wins << CSV_SELECTOR << List->at(i).loses << endl;
	}
};
void csvPrint(vector<vector<string>> in, bool printKeywords=false)
{
	for(int i = 0; i < static_cast<int>(in.size()); i++)
	{
		// Categories
		std::vector<string> categories = in.at(i);
		cout << "-> " << i + 2 << " Category: " << categories.front();
		if (printKeywords){
			cout << "Keywords: ";
			for (int j = 1; j < static_cast<int>(categories.size()); j++)
			{
				cout << "[ " << categories.at(j) << " ] ";
			}
		}
		cout << endl;
	}
}
vector<player>LoadPlayersFromCSV(vector<vector<string>> in)
{
	vector<player>PlayerList;
	for (int i = 0; i < static_cast<int>(in.size()); i++)
	{
		std::vector<string> row = in.at(i);
		
		player NewPlayer = player(row.front(),StringToInt(row.at(1)), StringToInt(row.at(2)));
		PlayerList.push_back(NewPlayer);
	}
	return PlayerList;
}
player FindPlayer(vector<player>* List, string name)
{
	player P = player(name);
	for (int i = 0; i < static_cast<int>(List->size()); i++)
	{
		if (List->at(i).name == name)
		{
			P = List->at(i);
		}

	}
	return P;
}
void PrintPlayer(player* P)
{
	cout << "Player " << P->name << " has " << P->wins << " wins and " << P->loses << " loses. " << endl;
}
void UpdatePlayerList(vector<player>* List, player* p)
{
	bool found = false;
	for (int i = 0; i < static_cast<int>(List->size()); i++)
	{
		if (List->at(i).name == p->name)
		{
			List->at(i) = *p;
			found = true;
		}
	}
	if (!found) {
		List->push_back(*p);
	}
}
void printPlayerList(vector<player>* List)
{
	for (int i = 0; i < static_cast<int>(List->size()); i++)
	{
		cout << i+1 << " - >";
		PrintPlayer(&List->at(i));
	}
}
void sortPlayerList(vector<player>* List)
{
	sort(List->begin(), List->end(), [](player a, player b) {
		if (a.wins == b.wins)
		{
			return a.loses < b.loses;
		}
		return a.wins > b.wins;
		});
}