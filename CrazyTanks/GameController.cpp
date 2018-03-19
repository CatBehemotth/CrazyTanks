#include "stdafx.h"
#include "GameController.h"
#include "UpdateDisplay.h"
#include "MyTank.h"
#include <stdio.h>
#include "Display.h"
#include "Barriers.h"



const char tankBody[3]={'@','$','#'};
int randomBodyElement = 0;
int nBarriers = 0;


std::pair<short, short> startPos = { 24, 47 };
std::pair<short, short> scoreLocation = { 0, 50 };
std::pair<short, short> timeLocation = { 0, 52 };
GameController::GameController()
{

	addBarrier({ randomBarrierCoord() });
	addBarrier({ 10,20 });
	addBarrier({ 45,30 });
	addBarrier({ 40,5 });
	addBarrier({ 9,29 });
	
	mTanks.push_back(std::shared_ptr<Tank>( new Tank(*this, '#', 1, { randomCoord() }, {-1, 0})));
	mTanks.push_back(std::shared_ptr<Tank>(new Tank(*this, '$', 1, { randomCoord() }, { 0, 1 })));
	mTanks.push_back(std::shared_ptr<Tank>(new Tank(*this, '@', 1, { randomCoord() }, { 1, 0 })));
	auto tank = std::shared_ptr<MyTank>(new MyTank(*this, 0, 'o', 3, startPos));
	tank->setDirection({ 0, -1 });
	tank->getScore();
	mTanks.push_back(tank);
	
	startCircle();
}

GameController::~GameController()
{
}

void GameController::startCircle()
{
	while (true)
	{
		
		randomBarrierCoord();
		UpdateDisplay::cleanDisplay(mField.fieldSize, ' ');

		for (auto &bullet : mBullets)
		{
			bullet.update();
			
		}
		
		for (auto &barrier : mBarriers)
		{
			barrier.draw();
			
				
				
		}
		
		calculateBulletsBarrierCollision();
		calculateBulletsFieldCollision();
		randomBodyElement = rand() % 3;
		calculateBulletsCollision();
		calculateTanksCollisions();

		for (auto &bullet : mBullets)
		{
			bullet.draw();
		}

		for (auto &tank : mTanks)
		{
			tank->update();
			tank->draw();
		}
		
		Display::drawScore(scoreLocation,0 );
		//Display::drawTime(timeLocation, );

		Sleep(250);
	}
}

void GameController::calculateBulletsCollision()
{
	int bulletIndex = -1;
	int tankIndex = -1;
	for (size_t bullet = 0; bullet < mBullets.size(); ++bullet)
	{
		for (size_t tank = 0; tank < mTanks.size(); ++tank)
		{
			if (isBulletTankCollision(mBullets[bullet], *mTanks[tank]))
			{
				bulletIndex = bullet;
				tankIndex = tank;
				break;
			}
		}

		if (bulletIndex != -1)
			break;
	}

	if (bulletIndex != -1)
	{
		mBullets.erase(mBullets.begin() + bulletIndex);

		if (tankIndex != -1)
		{
			mTanks.erase(mTanks.begin() + tankIndex);

			if (mTanks.size() < 5)
			{
				mTanks.push_back(std::shared_ptr<Tank>(new Tank(*this, tankBody[randomBodyElement], 1, { randomCoord() }, { -1, 0 })));
			}
		}
		
	}
}

void GameController::calculateTanksCollisions()
{

}

void GameController::calculateBulletsFieldCollision()
{
	int bulletIndex = -1;

	for (size_t bullet = 0; bullet < mBullets.size(); ++bullet)
	{
			if (isBulletFieldCollision(mBullets[bullet]))
			{
				bulletIndex = bullet;
				break;
			}		
	}
	if (bulletIndex != -1)
	{
		mBullets.erase(mBullets.begin() + bulletIndex);
	}
}

void GameController::calculateBulletsBarrierCollision()
{
	int bulletIndex = -1;
	int barrierIndex = -1;
	for (size_t bullet = 0; bullet < mBullets.size(); ++bullet)
	{
		for (size_t barrier = 0; barrier < mBarriers.size(); ++barrier)
		{
			if (isBulletBarrierCollision(mBullets[bullet], mBarriers[barrier]))
			{
				bulletIndex = bullet;
				barrierIndex = barrier;
				break;
			}
		}
		if (bulletIndex != -1)
			break;
	}
	if (bulletIndex != -1)
	{
		mBullets.erase(mBullets.begin() + bulletIndex);
	}
}

void GameController::calculateTankBarrierCollision()
{
	int tankIndex = -1;
	int barrierIndex = -1;
	for (size_t tank = 0; tank < mTanks.size(); ++tank)
	{
		for (size_t barrier = 0; barrier < mBarriers.size(); ++barrier)
		{
			if (isTankBarrierCollision(*mTanks[tank], mBarriers[barrier]))
			{
				tankIndex = tank;
				barrierIndex = barrier;
				break;
			}
		}
		if (tankIndex != -1)
			break;
	}
	if (tankIndex != -1)
	{
		
	}
}

//void GameController::calculateTankMyTankCollision()
//{
//	int tankIndex = -1;
//	auto tank = std::shared_ptr<MyTank>(new MyTank(*this, 0, 'o', 3, startPos));
//
//	for (size_t enemyTank = 0; enemyTank < mTanks.size(); ++enemyTank)
//	{
//		if (isFire(*mTanks[enemyTank],tank->getCoord()))
//		{
//			tankIndex = enemyTank;
//			break;
//		}
//	}
//	if (tankIndex != -1)
//	{
//		mBullets.erase(mBullets.begin() + tankIndex);
//	}
//}

bool GameController::isTankBarrierCollision(const Tank & tank, const Barriers & barrier)
{
	auto tankLocalCoord = tank.getCoord();
	auto barrierCoord = barrier.coord;

	for (auto &local_coord : Tank::localCoords)
	{
		std::pair<short, short> localCoord = { local_coord.first + tankLocalCoord.first, local_coord.second + tankLocalCoord.second };
		if (barrierCoord.first == localCoord.first && barrierCoord.second == localCoord.second)
			return true;
	}
	return false;
}

bool GameController::isBulletTankCollision(const Bullet & bullet, const Tank & tank)
{
	auto tankLocalCoord = tank.getCoord();
	auto bulletCoord = bullet.getPosition();

	for (auto &local_coord : Tank::localCoords)
	{
		std::pair<short, short> localCoord = { local_coord.first + tankLocalCoord.first, local_coord.second + tankLocalCoord.second };
		if (bulletCoord.first == localCoord.first && bulletCoord.second == localCoord.second)
			return true;
	}
	return false;
}

bool GameController::isBulletBarrierCollision(const Bullet & bullet, const Barriers & barrier)
{
	auto barrierLocalCoord = barrier.coord;
	auto bulletCoord = bullet.getPosition();

	for (auto &local_coord : Barriers::localCoords)
	{
		std::pair<short, short> localCoord = { local_coord.first + barrierLocalCoord.first, local_coord.second + barrierLocalCoord.second };

		if (bulletCoord.first == localCoord.first && bulletCoord.second == localCoord.second)
			return true;
	}

	return false;
}

bool GameController::isBulletFieldCollision(const Bullet & bullet)
{
	
	auto bulletCoord = bullet.getPosition();
	for (size_t bullet = 0; bullet < mBullets.size(); ++bullet)
	{
		if (bulletCoord.second > 49 || bulletCoord.second < 1 || bulletCoord.first > 49 || bulletCoord.first < 1)
		{
			return true;
		}
	}
	return false;
	

}

bool GameController::isFire(const Tank& enemyTank, const MyTank& myTank)
{
	auto enemyTankLocalCoord = enemyTank.getCoord();
	auto myTankLocalCoord = myTank.getCoord();

	for (auto &local_coord : Tank::localCoords)
	{
		std::pair<short, short> localCoord = { local_coord.first + enemyTankLocalCoord.first, local_coord.second + enemyTankLocalCoord.second };

		if (myTankLocalCoord.first == localCoord.first || myTankLocalCoord.second == localCoord.second)
			return true;
	}

	return false;
}

void GameController::onFire(const std::pair<short, short>& startCoord, const std::pair<short, short>& direction)
{
	mBullets.push_back({ startCoord, direction });
}

void GameController::addBarrier(const std::pair<short, short>& startCoord)
{
	mBarriers.push_back({ startCoord });
}

std::pair<short, short> GameController::randomBarrierCoord()
{
	std::pair<short, short>randomBarrierCoord;
	
		srand(time(0));
		randomBarrierCoord.first = rand() % 9 + 2;
		srand(1);
		randomBarrierCoord.second = rand() % 15 + 5;
		return randomBarrierCoord;	
	
}

std::pair<short, short> randomCoord()
{
	std::pair<short, short>randomTankCoord;

	randomTankCoord.first = rand() % 47 + 2;
	srand(time(0));
	randomTankCoord.second = rand() % 40 +2;
	return randomTankCoord;
	
}
