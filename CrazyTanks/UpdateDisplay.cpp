#include "stdafx.h"
#include "UpdateDisplay.h"


void UpdateDisplay::drowElemnt(const std::pair<short, short> &elementPos, char element)
{
	HANDLE hOut;
	COORD Position = { elementPos.first, elementPos.second };
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, Position);
	std::cout << element;
}

void UpdateDisplay::cleanDisplay(const std::pair<short, short> &boardSize, char element)
{
	for (int i = 0; i < boardSize.first; ++i)
	{
		drowElemnt({ 0, i }, '*');
		drowElemnt({ i, boardSize.first - 1}, '*');
		drowElemnt({ i, 0 }, '*');
		drowElemnt({ boardSize.first - 1, i }, '*');
	}
	
	for (int y = 1; y < boardSize.second - 1; ++y)
	{
		for (int x = 1; x < boardSize.first - 1; ++x)
		{
				HANDLE hOut;
				COORD Position = { x, y };
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut, Position);
				std::cout << " ";
		}
	}


}