#pragma once
#include "framework/Actor.h"

namespace ly
{
	class Bullet : public Actor
	{
	public:
		Bullet(World* world, Actor* owner, const std::string texturePath, float speed = 300.f, float damage  = 10.f);
		void SetSpeed(float newSpeed);
		void SetDamage(float newDamage);

	private:
		Actor* mOnwer;
		float mSpeed;
		float mDamage;
	};
}