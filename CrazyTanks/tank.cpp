#include "stdafx.h"
#include "tank.h"
#include "UpdateDisplay.h"
#include "GameController.h"

const std::vector<std::pair<short, short>> Tank::localCoords = { { -1, -1 },{ 0, -1 },{ 1, -1 },
{ -1, 0 },{ 0, 0 },{ 1, 0 },
{ -1, 1 },{ 0, 1 },{ 1, 1 } };

Tank::Tank(TankListener &_listener, const char& element,const int& health,
									const std::pair<short, short>& startCoord, 
									const std::pair<short, short>& directionOfTank):
																	coord(startCoord),
																	tankBody_(element),
																	listener(_listener)
{
		tankHealth_ = health;
		movedirection = directionOfTank;
		direction = movedirection;
}
Tank::~Tank()
{

}

void Tank::setMoveDirection(const std::pair<short, short>& newDirection)
{
	movedirection = newDirection;

	if (newDirection != std::pair<short, short>{0, 0})
		direction = newDirection;
}
void Tank::setDirection(const std::pair<short, short>& newDirection)
{
	direction = newDirection;
}
const std::pair<short, short>& Tank::getCoord() const
{
	return coord;
}

void Tank::draw()
{
	for (auto &local_coord : localCoords)
	{
		std::pair<short, short> localCoord = { local_coord.first + coord.first, local_coord.second + coord.second };
		UpdateDisplay::drowElemnt(localCoord, tankBody_);
	}	
}

void Tank::update() 
{
	coord.first += movedirection.first;
	coord.second += movedirection.second;
	
	
	if (coord.first <=2 || coord.first >= 47)
	{
		movedirection.first *= -1;
	}
	else if (coord.second <= 3 || coord.second >= 47)
	{
		movedirection.second *= -1;
	}
	
	
}

void Tank::fire() const
{
	std::pair<short, short> startPos = { coord.first + direction.first * 2, coord.second + direction.second * 2 };
	listener.onFire(startPos, direction);
}

bool Tank::isAlive(const Tank& unit)
{
	if (unit.tankHealth_>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const int Tank::getHealth()
{
	return tankHealth_;
}

void Tank::setHealth(int health)
{
	tankHealth_ = health;
}