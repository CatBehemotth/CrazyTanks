#ifndef COORD_H_
#define COORD_H_

class Coord
{
public:
	Coord();
	Coord(int newX=0, int newY = 0);
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	Coord& operator +=(const Coord& op);

	friend Coord operator +(const Coord& object1, const Coord& object2);
	friend bool operator ==(const Coord& object1, const Coord& object2);
	~Coord();

private:
	int x;
	int y;
};
#endif // !COORD_H_
