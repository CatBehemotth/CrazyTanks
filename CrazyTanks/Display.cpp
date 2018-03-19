#include "stdafx.h"
#include "Display.h"
#include "MyTank.h"

Display::Display()
{
	firstTimer_ = clock();
}

Display::~Display()
{
}

const void Display::setTimer(int time)
{
	timer_=time;
}


int Display::getTimer()
{
	return timer_;
}




void Display::drawScore(const std::pair<short, short> &elementPos, int currentScore)
{
	HANDLE hOut;
	COORD Position = { elementPos.first, elementPos.second };
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, Position);
	std::cout <<"Score: "<<currentScore;
}