#ifndef GUESS_H
#define GUESS_H

#include <utility>
#include <ctime>

// Austin Chandler - this is my own work and what we did in class

class Guess {
private:
	int aGuess[4];
	bool isValid(int) const; 
public:
	Guess();
	void setGuess(int, int, int, int);
	void setMaster();
	int operator[](int) const;
};

//implementations
Guess::Guess()
{
	aGuess[0] = aGuess[1] = aGuess[2] = aGuess[3] = -1;
	srand(time(NULL));
}

int Guess::operator[](int index) const
{
	return aGuess[index];
}

void Guess::setGuess(int a, int b, int c, int d)
{
	if (isValid(a)) aGuess[0] = a;
	if (isValid(b)) aGuess[1] = b;
	if (isValid(c)) aGuess[2] = c;
	if (isValid(d)) aGuess[3] = d;
}

bool Guess::isValid(int a) const
{
	return (0 <= a && a <= 5);
}

void Guess::setMaster()
{
	aGuess[0] = rand() % 6;
	aGuess[1] = rand() % 6;
	aGuess[2] = rand() % 6;
	aGuess[3] = rand() % 6;
}

#endif
