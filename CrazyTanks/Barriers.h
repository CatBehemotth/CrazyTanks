#ifndef BARRIERS_H_
#define BARRIERS_H_
#include <cstddef>

class Barriers
{
public:
	Barriers(const std::pair<short, short>& startCoords/*, const std::pair<short, short>& direction*/);
	~Barriers();

	void draw();

	const std::pair<short, short>& getPosition() const;
	static const std::vector<std::pair<short, short>>localCoords;

	std::pair<short, short>coord = { 20, 30};

private:
	char barrierSymbol_;
	std::pair<short, short> startPosition_;
	//std::pair<short, short> endPosition;
	

};
#endif // !BARRIERS_H_
