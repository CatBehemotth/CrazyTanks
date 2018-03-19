#include "stdafx.h"
#include "Barriers.h"
#include "UpdateDisplay.h"

const std::vector<std::pair<short, short>> Barriers::localCoords = { { -1, 0 },{ 0, 0 },{ 1, 0 } };

Barriers::Barriers(const std::pair<short, short>& startCoords/*,const std::pair<short, short>& finiteCoordinates*/):
	coord(startCoords)
	
	
{
	barrierSymbol_ = '+';
}

Barriers::~Barriers()
{

}



void Barriers::draw()
{
	for (auto &local_coord : localCoords)
	{
		std::pair<short, short> localCoord = { local_coord.first + coord.first, local_coord.second + coord.second };
		UpdateDisplay::drowElemnt(localCoord, barrierSymbol_);
	}
}

const std::pair<short, short>& Barriers::getPosition() const
{
	return startPosition_;
}
