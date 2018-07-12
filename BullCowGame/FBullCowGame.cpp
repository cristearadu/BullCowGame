#include "FBullCowGame.h"
#include <map>
//to make syntax Unreal friendly
#define TMap std::map 

using int32 = int;
FBullCowGame::FBullCowGame() { Reset(); } //Default constructor


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} }; //level of gameplay
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; //must be an isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))//if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; 
	}
	else if (!IsLowerCase(Guess)) //if the guess isn't all lowercase 
	{
		return EGuessStatus::Not_Lowercase; 
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// recieves a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//incremet the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;

	//loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();//assuming the same length as guess

	for (int32 i = 0; i < WordLength; i++)
	{
		//compare letters against the hidden guess
		for (int32 j = 0; j < WordLength; j++)
		{
			if(Guess[j] == MyHiddenWord[i]) //if they match then
			{ 
				if (i == j) // if they're in the same place
				{
					// increment bulls
					BullCowCount.Bulls++;
				}
				else
				{	
					//increment cows
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) { bGameIsWon = true; }
	else { bGameIsWon = false; }
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup our map
	// loop through all letters of the word
	for (auto Letter : Word) //for all letters of the word
	{
		Letter = tolower(Letter); //handle mixed case

		if (LetterSeen[Letter]) // if the letter is in the map
		{
			return false; //we do NOT have an isogram
		}
		else
		{
			LetterSeen[Letter] = true; //add the letter to the map as seen
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}
