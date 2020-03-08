#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Guess.h"

using namespace std;

// Austin Chandler - This is my own work and what we did in class

class Game {
private:
	Guess userGuess;
	Guess secretCode;
	int wp, bp, numGuesses;

public:
	Game();
	void getUserGuess();
	void giveFeedback();
	bool isWinner();
	bool isLoser();
	void playGame();
};

//implementation
//constructor
Game::Game()
{
	wp = bp = numGuesses = 0;
}

void Game::playGame()
{
	//set the secret code
	secretCode.setMaster();
	//If I want to see the secret code I can uncomment the below line 
	//cout << secretCode[0] << " " << secretCode[1] << " " << secretCode[2] << " " << secretCode[3] << endl;

	//while there is not a winner and not a loser; keep playing
	do {
		//get user guess, give feedback, and check for winner
		getUserGuess();
		giveFeedback();
		numGuesses++;
		if ((5 - numGuesses) != 0) cout << "You have " << (5 - numGuesses) << " guesses left" << endl << endl;
		if (isWinner())
			cout << "You  Win!" << endl;
			//end the game
		else if (isLoser())
			cout << "You ran out of guesses... Better luck next time!" << endl << "The secret code was: " << secretCode[0] << " " << secretCode[1] << " " << secretCode[2] << " " << secretCode[3] << endl;
			//end the game
	} while (!isWinner() && !isLoser());
}

//set guess limit and check for loser
bool Game::isLoser()
{
	if (numGuesses < 5)
		return false;
	else
		return true;
}

//look for 4 black pegs to determine winner
bool Game::isWinner()
{
	if (bp == 4)
		return true;
	else
		return false;
}

//getting a guess from the user
void Game::getUserGuess()
{
	int a, b, c, d;
	cout << "Please enter 4 integers from 0-5: ";
	cin >> a >> b >> c >> d;
	userGuess.setGuess(a, b, c, d);
	cout << "A Guess of " << userGuess[0] << " " << userGuess[1] << " " << userGuess[2] << " " << userGuess[3] << " yields" << endl;
}

//giving feedback
void Game::giveFeedback()
{
	int guessColors[6];
	int codeColors[6];
	bp = wp = 0;
	//count black pegs
	for (int i = 0; i < 4; i++) {
		if (userGuess[i] == secretCode[i])
			bp++;
	}

	//count white pegs
	//make two new arrays to hold the number of colors; initialize both to 0
	for (int i = 0; i < 6; i++) {
		guessColors[i] = 0;
		codeColors[i] = 0;
	}

	//add number of each color in user guess to the array of guess colors
	for (int i = 0; i < 4; i++) {
		guessColors[userGuess[i]]++;
	}

	//add number of each color in secret code to the array of code colors
	for (int i = 0; i < 4; i++) {
		codeColors[secretCode[i]]++;
	}

	//compare the arrays to find white pegs
	for (int i = 0; i < 6; i++) {
		if (codeColors[i] < guessColors[i]) {
			wp += codeColors[i];
		}
		else {
			wp += guessColors[i];
		}
	}

	//subtract black pegs to remove any duplicates
	wp -= bp;
	cout << wp << " white peg(s) and " << bp << " black peg(s) " << endl;
}

#endif