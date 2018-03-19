#include "stdafx.h"
#include "MyTank.h"
#include "GameController.h"

MyTank::MyTank(TankListener &listener, const int& score , const char& element , const int& health,
	std::pair<short, short> startCoord):Tank(listener, element,health, startCoord)
{
	score_ = score;
}

MyTank::~MyTank()
{

}

int MyTank::getScore() 
{
	return score_;
}

void MyTank::setScore(int newScore)
{
	score_ = newScore;
}


void MyTank::update()
{
	
	if (GetAsyncKeyState(VK_UP) && coord.second > 3)
	{
		if (coord.second == 3)
		{
			--coord.second;
		}
		else
			coord.second -= 1;

		direction.second = -1;
		movedirection.second = -1;
		direction.first = 0;
		movedirection.first = 0;
	}
		else if (GetAsyncKeyState(VK_LEFT)&&coord.first>3 )
		{
			coord.first -= 1;

			direction.first = -1;
			movedirection.first = -1;
			direction.second = 0;
			movedirection.second = 0;
		}
		else if (GetAsyncKeyState(VK_RIGHT)&&coord.first<46)
		{
			if (coord.first==46)
			{
				++coord.first;
			}
			else
				coord.first += 1;

			direction.first = 1;
			movedirection.first = 1;

			direction.second = 0;
			movedirection.second = 0;
		}
		else if (GetAsyncKeyState(VK_DOWN)&&coord.second<46)
		{
			coord.second += 1;

			direction.second = 1;
			movedirection.second = 1;
			direction.first = 0;
			movedirection.first = 0;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
  			fire();
		}
	
	
	
}
