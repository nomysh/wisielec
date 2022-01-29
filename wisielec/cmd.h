#ifndef CMD_H
#define CMD_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#define MAX_TRY_COUNT 12
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
};
void printParam(cmdParam in);
gameFiles parseOrDie(int argc, char** argv);
void instruction();
void printHangman(int score);
void printMenu();
int StringToInt(std::string dirty);
void GameLoop(std::vector<std::vector<std::string>> in);
void printStatus(std::vector<char> invalid_guess, std::vector<char>hashed_vector );
void end_game(std::vector<char>hashed_vector, std::vector<char>keyword_vector);
std::vector<std::vector<std::string>> read_csv(std::string filename);
std::string GetKeyword(std::vector<std::vector<std::string>> csv, int category);
void print_csv(std::vector<std::vector<std::string>> in);
#endif CMD_H