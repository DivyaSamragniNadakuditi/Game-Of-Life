#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>
#include <iomanip>

#define BIRTH 'x'
#define DEATH '#'

class GameOfLife
{
private:
	char ** Today = NULL;
	char  ** Next;
	int rows, cols, lifecells;
	void Run();
	void Release(char** mem);
	void Clone(char **Today);
	void BirthOrDeath(char **Today);
public:
	GameOfLife();
	GameOfLife(int, int);
	
	void Print(char **Today);
};
#endif