// BullCowGame.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
using namespace std;
void PrintIntro() {
		//introduce the game
	
		constexpr int WORLD_LENGTH = 9; //constant expression
		cout << "Welcome to Bulls and Cows, a fun word game.\n";
		cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?\n";
		cout << endl; 

		return;
	}
int main()
{	
	

	PrintIntro();

	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	//repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	//get a guess from the player
	cout << "Enter your guess: ";
	getline(cin, Guess);

	//repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;


	cout << endl;
	return 0;
}

