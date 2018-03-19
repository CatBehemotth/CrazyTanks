#include "stdafx.h"
#include "Bullet.h"
#include "UpdateDisplay.h"


Bullet::Bullet(const std::pair<short, short>& startCoords, const std::pair<short, short>& direction):
position(startCoords),
direction(direction)
{
}


Bullet::~Bullet()
{
}

void Bullet::update()
{
		position.first += direction.first;
		position.second += direction.second ;	
}

void Bullet::draw()
{
		UpdateDisplay::drowElemnt(position, '*');	
}

const std::pair<short, short>& Bullet::getPosition() const
{
	return position;
}
