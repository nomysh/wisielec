/** @file */ 
#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include<cctype>
#include<algorithm>

/** maksymalny prog bledow przy zgadywaniu hasla*/
#define MAX_TRY_COUNT 12

/** maksymalna dlugosc imienia gracza */
#define MAX_NAME_SIZE 16 

/** znak specjalny oddzielajacy hasla w pliku*/
#define CSV_SELECTOR ';' 

/** struktura obslugujaca flagi*/
struct cmdParam  
{
	/** skrocona wersja flagi, reprezentuje forme -f*/
	std::string short_name; 
	/** Pelna nazwa flagi, repzentuje forme --flag*/
	std::string long_name;
	/** Opis danej flagi, komunikat wyswietlany uzytkownikowi*/
	std::string description;
	
	/** domyslny konstruktor, tworzy zmienna z pustymi polami */
	cmdParam() {
		this->short_name = "";
		this->long_name = "";
		this->description = "";

	};
	/**konstruktor zlozony z krotkiej nazwy -f, dlugiej nazwy --flag oraz jej opisu */
	cmdParam(std::string s, std::string l, std::string desc) {
		this->short_name = s;
		this->long_name = l;
		this->description = desc;
	};
};

/** struktura obslugujaca pliki wejsciowe i wyjsciowe, hasla i rekordy*/
struct gameFiles 
{
	//** Sciezka do pliku wejsciowego*/
	std::string input_file_path;
	//** Sciezka do pliku wyjsciowego*/
	std::string output_file_path;

	/**Konstruktor zlozony z pliku wejsciowego oraz wyjsciowego */
	gameFiles()
	{
		this->input_file_path = "";
		this->output_file_path = "";
	};
	
	/**Konstruktor zlozony z pliku wejsciowego oraz wyjsciowego 
	@param in plik wejsciowy
	@param out plik wyjsciowy*/
	gameFiles(std::string in, std::string out)
	{
		this->input_file_path = in;
		this->output_file_path = out;
	};
};

/** struktura bedaca interpretacja profilu gracza (imie, jego zwyciestwa i porazki)*/
struct player 
{
	/** Imie gracza*/
	std::string name;
	/** liczba wygranych gracza*/
	int wins;
	/** liczba przegranych gracza*/
	int loses; 

	/** domyslny konstruktor, tworzy gracza z pustymi statystykami (wygrane oraz przegrane)
	@param name_input imie gracza
	*/
	player(std::string name_input)
	{
		this->name = name_input;
		this->wins = 0;
		this->loses = 0;
	};
	
	/** Konstruktor zlony z imienia gracza oraz jego wyniku (wygrane oraz przegrane) importowany z pliku 
	@param name_input imie gracza
	@param wins_input liczba zwyciestw gracza 
	@param loses_input liczba porazek gracza
	*/
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

/** Funkcja drukuje na ekran flagi.
@param in nazwa wprowadzonej flagi.
*/
void printParam(cmdParam in); 

/** Funcja sprawdza czy otrzymany string zaczyna sie od '-', czy jest flaga.
@param input wskaznik na pierwszy element string.
@return s zwraca oryginalny input jako string.
		  zwraca pusty string .
*/
std::string isStringFlag(char* input);

/** Funkcja sprawdza, czy otrzymane pliki sa prawidlowe.
* @param argc ile argumentow zostalo przekazanych do programu 
* @param argv podane argumenty
* @return gameFiles sciezka do pliku wejsciowego oraz wyjsciowego 
*/
gameFiles parseOrDie(int argc, char** argv);

/** Funkcja drukuje na ekran instrukcje jak grac w gre.
*/
void instruction();

/** Funkcja drukuje na ekran szubienice po podaniu nieprawidlowego znaku.
@param score liczba nieprawidlowych prob.
*/
void printHangman(int score);

/** Funkcja drukuje na ekran menu glowne gry.
*/
void printMenu();

/** Funkcja konwertuje stringa na inta.
@param dirty wartosc stringa.
@return clean wartosc string jako int.
*/
int stringToInt(std::string dirty);

/** Funckja obslugujaca menu gry.
@param in vector vectorow zawierajacy kategorie oraz hasla.
@param PlayerList lista graczy przeczytana z pliku.
*/
void gameLoop(std::vector<std::vector<std::string>> in, std::vector<player> *PlayerList);

/** Funkcja drukuje na ekran Nieprawdilowe znaki oraz zakodowane haslo.
@param invalid_guess niepoprawne znaki.
@param hashed_vector zakodowane haslo.
*/
void printStatus(std::vector<char> invalid_guess, std::vector<char>hashed_vector );

/** Funkcja oznajmia koniec gry, wygrana lub przegrana oraz dopisuje wynik do statystyk.
@param hashed_vector zakodowane haslo.
@param keyword_vector zgadywane haslo.
@param P profil grajacego gracza.
*/
void endGame(std::vector<char>hashed_vector, std::vector<char>keyword_vector, player *P);

/** Funkcja czyta z pliku wejsciowego kategorie oraz hasla, badz statystyki
* @param filename nazwa czytanego pliku
* @param lower jezeli true, zamienia duze litery na male
* @return result zapisane  wartosci z pliku
*/
std::vector<std::vector<std::string>> csvRead(std::string filename, bool lower);

/** Funkcja losuje haslo z wybranej, badz wylosowanej kategorii.
@param csv vector vectorow zawierajacy kategorie oraz hasla.
@param cateogry numer wybranej kategorii.
*/
std::string getKeyword(std::vector<std::vector<std::string>> csv, int category);

/** Funkcja drukuje na ekran zawartosc pliku
@param in vector vectorow zawierajacy kategorie oraz hasla
@return string  wybrana, badz wylosowana kategoria
*/
void csvPrint(std::vector<std::vector<std::string>> in);

/** Funkcja umozliwia wybor kategorii, badz jej wylosowanie
@param in vector vectorow vector vectorow zawierajacy kategorie oraz hasla
@return categoryID nr wybranej kategorii 
*/
int pickCategory(std::vector<std::vector<std::string>> in);

/** Funkcja szuka gracza w liscie. Jezeli istnieje zwraca jego profil, jezeli nie zwraca pusty profil
@param List lista graczy
@param name imie gracza 
@return P imie gracza 
*/
player findPlayer(std::vector<player>*List, std::string name);

/** Funkcja czyta liste graczy z pliku
@param vector vectorow zawierajacy statystyki
@return P Lista Graczy
*/
std::vector<player>loadPlayersFromCSV(std::vector<std::vector<std::string>> in);

/** Funkcja drukuje wynik danego gracza
@param *P dane gracza
*/
void printPlayer(player *P);

/** Funkcja aktualizuje liste graczy o nowy wynik
@param List lista graczy
@param p aktualny gracz
*/
void updatePlayerList(std::vector<player>* List, player* p);

/** Funkcja drukuje na ekran liste graczy (ranking)
@param List lista graczy
*/
void printPlayerList(std::vector<player>* List);

/** Funkcja sortujaca graczy po liczbie zwyciestw 
@param List lista graczy
*/
void sortPlayerList(std::vector<player>* List);

/** Funkcja zapisuje do pliku statystyki gracza 
@param filepath sciezka do  pliku, 
@param List lista graczy 
*/
void csvWrite(std::string filepath, std::vector<player>* List);

/** Funkcja obslugujaca faktyczna gre
@param in vector vectorow zawierajacy kategorie oraz hasla
@param P profil gracza
*/
void newGame(std::vector<std::vector<std::string>> in, player* P);

/** Funkcja umozliwia zalogowanie sie do gry 
@param PlayerLista lista graczy
@return NewPlayer profil nowego gracza
*/
player newPlayer(std::vector<player>* PlayerList);

/** Funkcja drukuje na ekran string.
@param in vector, ktory chcemy wyswietlic.
*/
void printVector(std::vector<char> in);
#endif LIBRARY_H