#pragma once
#include "weapon/Shooter.h"
#include <SFML/System.hpp>

namespace ly
{
	class BulletShooter : public Shooter
	{
	public:
		BulletShooter(Actor* actor, float coolDownTime = 1.f);
		virtual bool IsOnCooldown() const override;
	private:
		virtual void ShootImpl();
		sf::Clock mCooldownClock;
		float mCooldonwnTime;
	};
}