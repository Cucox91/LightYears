#include "weapon/Bullet.h"

namespace ly
{
	Bullet::Bullet(World* world, Actor* owner, const std::string texturePath, float speed, float damage)
		:Actor{ world,texturePath },
		mOnwer{ owner },
		mSpeed{ speed },
		mDamage{ damage }
	{
	}

	void Bullet::SetSpeed(float newSpeed)
	{
		mSpeed = newSpeed;
	}
	void Bullet::SetDamage(float newDamage)
	{
		mDamage = newDamage;
	}
}