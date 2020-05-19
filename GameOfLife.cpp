#include "GameOfLife.h"

GameOfLife::GameOfLife()
{
}


GameOfLife::GameOfLife(int x, int y) :rows(x), cols(y), lifecells(0)
{
	
	if (Today == NULL)
	{
		Today = new char*[rows];
		for (int i = 0; i < rows; i++)
		{
			Today[i] = new char[cols];
			for (int j = 0; j < cols; j++)
			{
				Today[i][j] = DEATH;
				
			}
		}
	}

	Today[1][1] = BIRTH;
	Today[1][2] = BIRTH;
	Today[1][3] = BIRTH;
	Today[2][2] = BIRTH;

	Run();

}



/* compute next generation cycle */
void  GameOfLife::BirthOrDeath(char **Today)
{

	Clone(Today);

	for (int i(0); i < rows; i++)
	{
		for (int j(0); j < cols; j++)
		{
			if ((j + 1) < cols && Next[i][j + 1] == 'x')
			{
				lifecells ++;
			}

			if ((j - 1) >= 0 && Next[i][j - 1] == 'x')
			{
				lifecells++;
			}

			if ((j - 1) >= 0 && (i - 1) >= 0 && Next[i - 1][j - 1] == 'x')
			{
				lifecells++;
			}

			if ((i - 1) >= 0 && Next[i - 1][j] == 'x')
			{
				lifecells++;
			}

			if ((i - 1) >= 0 && (j + 1) < cols && Next[i - 1][j + 1] == 'x')
			{
				lifecells++;
			}

			if ((i + 1) < rows && (j - 1) >= 0 && Next[i + 1][j - 1] == 'x')
			{
				lifecells++;
			}

			if ((i + 1) < rows && Next[i + 1][j] == 'x')
			{
				lifecells++;
			}

			if ((i + 1) < rows && (j + 1) < cols && Next[i + 1][j + 1] == 'x')
			{
				lifecells++;
			}
			// case 1: the cell dies
			if (lifecells < 2 || lifecells > 3)
			{
				Today[i][j] = DEATH;
			}
			// case 2: the cell stays same
			else if (lifecells == 2)
			{
				Today[i][j] = Next[i][j];
			}
			// case 3: the cell stays alive or is "born"
			else if (lifecells == 3)
			{
				Today[i][j] = BIRTH;
			}

			lifecells = 0;
		}
	}

	Release(Next);
}


void GameOfLife::Clone(char **Today)
{

	Next = new char*[rows];

	for (int i(0); i < rows; i++)
	{
		Next[i] = new char[cols];

		for (int j(0); j < cols; j++)
		{
			Next[i][j] = Today[i][j];
		}
	}
}
void GameOfLife::Release(char** mem)
{

	if (mem != NULL)
	{
		for (int i(0); i < rows; i++)
		{
			delete[] mem[i];
		}

		delete[] mem;
	}
}
void GameOfLife::Print(char **Today)
{

	std::cout << "\n";

	for (int i(0); i < rows; i++)
	{
		//std::cout << std::setw(5);

		for (int j(0); j < cols; j++)
		{
			std::cout << Today[i][j];
		}

		std::cout << "\n";
	}
}

void GameOfLife::Run()
{
	int n=5;
	while( n >0)
	{
		Print(Today);
		BirthOrDeath(Today);
		n--;

	}
}