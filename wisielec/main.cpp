// wisielec.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "library.h"
using namespace std; 

int main(int argc, char** argv)
{
   srand(time(nullptr));
   gameFiles gf = parseOrDie(argc, argv);
   vector<vector<string>> categories_keywords = csvRead(gf.input_file_path, true);
   vector<vector<string>> statistics = csvRead(gf.output_file_path, false);
   vector<player> PlayerList = LoadPlayersFromCSV(statistics);
   GameLoop(categories_keywords, &PlayerList);
   csvWrite(gf.output_file_path,&PlayerList);
  
    return 0;
}