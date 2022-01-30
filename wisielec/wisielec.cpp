// wisielec.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "cmd.h"
using namespace std; 

int main(int argc, char** argv)
{
   srand(time(nullptr));
   gameFiles gf = parseOrDie(argc, argv);
   vector<vector<string>> categories_keywords = read_csv(gf.input_file_path, true);
   vector<vector<string>> statistics = read_csv(gf.output_file_path, false);
   vector<player> PlayerList = LoadPlayersFromCSV(statistics);
   GameLoop(categories_keywords, &PlayerList);
   write_csv(gf.output_file_path,&PlayerList);
  
    return 0;
}