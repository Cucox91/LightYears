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
		void SetActorLocation(const sf::Vector2f& newLocation);
		void SetActorRotation(float newRotation);
		void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
		void AddActorRotationOffset(float offsetAmt);
		sf::Vector2f GetActorLocation() const;
		float GetActorRotation() const;
		sf::Vector2f GetActorForwardDirection() const;
		sf::Vector2f GetActorRightDirection() const;
		sf::Vector2u GetWindowSize() const;
		
	private:
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;						// The sprite can be a visual and it can be too what they call a Transformable.
		shared<sf::Texture> mTexture;
		void CenterPivot();

	};
}