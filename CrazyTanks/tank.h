#ifndef TANK_H_
#define TANK_H_


#include <cstddef>
#include <vector>


class TankListener;

class Tank
{
public:
	Tank(TankListener &listener, const char& element = '#', const int& health = 1, 
								 const std::pair<short, short>& startCoord = {2, 2}, 
								 const std::pair<short, short>& directionOfTank = { 0, 0 });
		~Tank();




		bool isAlive(const Tank& unit);
		const int getHealth();
		void setHealth(int health = 1);
		void setMoveDirection(const std::pair<short,short>& newDirection);
		void setDirection(const std::pair<short, short>& newDirection);
		const std::pair<short, short>& getCoord() const;

		virtual void draw();
		virtual void update();
		
		static const std::vector<std::pair<short, short>>localCoords;
	
		
protected:
		int tankHealth_;
		char tankBody_;
		TankListener &listener;

		std::pair<short, short>coord = {5, 5};

		void fire() const;
	    std::pair<short, short> movedirection;
	    std::pair<short, short> direction;
};
#endif // !TANK_H_
