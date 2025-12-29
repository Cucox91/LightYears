#include "weapon/BulletShooter.h"
#include "framework/Core.h"

namespace ly
{
	BulletShooter::BulletShooter(Actor* owner, float cooldonwnTime)
		: Shooter{owner},
		mCooldownClock{},
		mCooldonwnTime{cooldonwnTime}
	{

	}

	bool BulletShooter::IsOnCooldown() const
	{
		if (mCooldownClock.getElapsedTime().asSeconds() > mCooldonwnTime)
		{
			return false;
		}

		return true;
	}

	void BulletShooter::ShootImpl()
	{
		mCooldownClock.restart();
		LOG("Shooting");
	}
}