#pragma once

#include <SFML/Graphics.hpp>
#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
	class World;								//What this class above class says is that World is the owner of Actor. And we need to pass it as constructor argument below.
	class Actor: public Object
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();
		
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		void SetTexture(const std::string& texturePath);
		void Render(sf::RenderWindow& window);
	private:
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;						// The sprite can be a visual and it can be too what they call a Transformable.
		sf::Texture mTexture;
	};
}