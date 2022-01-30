#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include<cctype>
#include<algorithm>
#define MAX_TRY_COUNT 12
#define MAX_NAME_SIZE 16
#define CSV_SELECTOR ';'
struct cmdParam
{
	std::string short_name;
	std::string long_name;
	std::string description;
	cmdParam() {
		this->short_name = "";
		this->long_name = "";
		this->description = "";

	};
	cmdParam(std::string s, std::string l, std::string desc) {
		this->short_name = s;
		this->long_name = l;
		this->description = desc;
	};
};

struct gameFiles
{
	std::string input_file_path;
	std::string output_file_path;

	gameFiles()
	{
		this->input_file_path = "";
		this->output_file_path = "";
	};

	gameFiles(std::string in, std::string out)
	{
		this->input_file_path = in;
		this->output_file_path = out;
	};
};

struct player
{
	std::string name;
	int wins;
	int loses; 

	player(std::string name_input)
	{
		this->name = name_input;
		this->wins = 0;
		this->loses = 0;
	};
	player(std::string name_input, int wins_input, int loses_input)
	{
		this->name = name_input;
		this->wins = wins_input;
		this->loses = loses_input;
	};
	player()
	{
		this->name = "";
		this->wins = 0;
		this->loses = 0;
	};
};
void printParam(cmdParam in);
std::string ParseFile(char* input);
gameFiles parseOrDie(int argc, char** argv);
void instruction();
void printHangman(int score);
void printMenu();
int StringToInt(std::string dirty);
void GameLoop(std::vector<std::vector<std::string>> in, std::vector<player> *PlayerList);
void printStatus(std::vector<char> invalid_guess, std::vector<char>hashed_vector );
void EndGame(std::vector<char>hashed_vector, std::vector<char>keyword_vector, player *P);
std::vector<std::vector<std::string>> csvRead(std::string filename, bool lower);
std::string GetKeyword(std::vector<std::vector<std::string>> csv, int category);
void csvPrint(std::vector<std::vector<std::string>> in, bool printKeywords);
int pickCategory(std::vector<std::vector<std::string>> in);
player FindPlayer(std::vector<player>*List, std::string name);
std::vector<player>LoadPlayersFromCSV(std::vector<std::vector<std::string>> in);
void PrintPlayer(player *P);
void UpdatePlayerList(std::vector<player>* List, player* p);
void printPlayerList(std::vector<player>* List);
void sortPlayerList(std::vector<player>* List);
void csvWrite(std::string filepath, std::vector<player>* List);
void NewGame(std::vector<std::vector<std::string>> in, player* P);
player NewPlayer(std::vector<player>* PlayerList);
void printVector(std::vector<char> in);
#endif LIBRARY_H