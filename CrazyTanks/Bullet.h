#ifndef BULLET_H_
#define BULLET_H_

class Bullet
{
public:
	Bullet(const std::pair<short, short>& startCoords, const std::pair<short, short>& direction);
	~Bullet();

	void update();
	void draw();

	const std::pair<short, short>& getPosition() const;
private:
	std::pair<short, short> position;
	std::pair<short, short> direction;
};

#endif // !BULLET_H_


