#ifndef MYTANK_H_
#define MYTANK_H_
#include "tank.h"

class MyTank	: public Tank
{
public:
	MyTank(TankListener &listener, const int& score = 0, const char& element = '*', const int& health = 3,
															std::pair<short, short> startCoord = {20, 40});
	~MyTank();

	 int getScore();
	 void setScore(int score);
	void update() override;
	int score_;
protected:
	

};
#endif // !MYTANK_H_
