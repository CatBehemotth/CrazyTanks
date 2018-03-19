#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <ctime>
#include "tank.h"
#include "field.h"
#include "Bullet.h"
#include "Barriers.h"
#include <memory>
#include "MyTank.h"

class TankListener
{
public:
	virtual void onFire(const std::pair<short, short>& startCoord, const std::pair<short, short>& direction) = 0;
};

class GameController : public TankListener
{
public:
	GameController();
	~GameController();

	void Finish()const;
	const int getFullTime();
	const long getTime();

	void startCircle();

	void calculateBulletsCollision();

	void calculateTanksCollisions();
	void calculateBulletsFieldCollision();
	void calculateBulletsBarrierCollision();
	void calculateTankMyTankCollision();
	void calculateTankBarrierCollision();
	void addBarrier(const std::pair<short, short>& startCoord);
	std::pair<short, short> randomBarrierCoord();

	bool isTankBarrierCollision(const Tank& tank, const Barriers & barrier);
	bool isBulletTankCollision(const Bullet& bullet, const Tank& tank);
	bool isBulletBarrierCollision(const Bullet& bullet, const Barriers & barrier);
	bool isBulletFieldCollision(const Bullet& bullet);
	//bool isTankTankCollision(const Tank& enemyTank, const Tank & myTank);
	bool isFire(const Tank& enemyTank, const MyTank& myTank);
	virtual void onFire(const std::pair<short, short>& startCoord, const std::pair<short, short>& direction) override;

private:
	std::vector<std::shared_ptr<Tank>> mTanks;
	std::vector<Bullet> mBullets;
	std::vector<Barriers> mBarriers;
	Field mField;

};
std::pair<short, short> randomCoord();

#endif // !GAMECONTROLLER_H_
