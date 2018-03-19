#include "coord.h"
Coord::Coord()
{
	x = 0;
	y = 0;
}
Coord::Coord(int new_X, int new_Y)
{
	x - new_X;
	y = new_Y;
}
int Coord::getX()
{
	return x;
}
int Coord::getY()
{
	return y;
}
void Coord::setX(int new_X)
{
	x = new_X;
}
void Coord::setY(int new_Y)
{
	y = new_Y;
}
Coord& Coord::operator +=(const Coord& op)
{
	x += op.x;
	y += op.y;
	return *this;
}
Coord operator +(const Coord& object1, const Coord& object2)
{
	return Coord(object1.x + object2.x, object1.y + object2.y);
}
bool  operator ==(const Coord& object1, const Coord& object2)
{
	return object1.x == object2.x && object1.y == object2.y;
}