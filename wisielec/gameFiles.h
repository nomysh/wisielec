#ifndef GAMEFILES_H
#define GAMEFILES_H
#include<string>

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
gameFiles parseOrDie(int argc, char** argv);

#endif GAMEFILES_H
