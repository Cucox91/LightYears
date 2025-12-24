#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"

namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: mOwningWorld{ owningWorld },
		mHasBeganPlay{ false },
		mSprite{},
		mTexture{}
	{
		SetTexture(texturePath);
	}

	Actor::~Actor()
	{
		LOG("Actor Destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			mHasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor Begin Play");
	}

	void Actor::Tick(float deltaTime)
	{
		//LOG("Actor Tick");
	}

	void Actor::SetTexture(const std::string& texturePath)
	{
		AssetManager& assetManager = AssetManager::Get();
		mTexture = assetManager.LoadTexture(texturePath);
		if (!mTexture)
		{
			return;
		}

		mSprite.setTexture(*mTexture);

		int textureWidht = mTexture->getSize().x;
		int textureHeight = mTexture->getSize().y;
		mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{},sf::Vector2i{textureWidht,textureHeight} });		// This will define the texture rectangle. from the 0,0 to the widht and height of the texture.
		CenterPivot();
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (IspendingDestroy())
		{
			return;
		}

		window.draw(mSprite);
	}

	void Actor::SetActorLocation(const sf::Vector2f& newLocation)
	{
		mSprite.setPosition(newLocation);
	}

	void Actor::SetActorRotation(float newRotation)
	{
		mSprite.setRotation(newRotation);
	}

	void Actor::AddActorLocationOffset(const sf::Vector2f& offsetAmt)
	{
		SetActorLocation(GetActorLocation() + offsetAmt);
	}

	void Actor::AddActorRotationOffset(float offsetAmt)
	{
		SetActorRotation(GetActorRotation() + offsetAmt);
	}

	sf::Vector2f Actor::GetActorLocation() const
	{
		return mSprite.getPosition();
	}

	float Actor::GetActorRotation() const
	{
		return mSprite.getRotation();
	}

	sf::Vector2f Actor::GetActorForwardDirection() const
	{
		return RotationToVector(GetActorRotation());
	}

	sf::Vector2f Actor::GetActorRightDirection() const
	{
		return RotationToVector(GetActorRotation() + 90.f);
	}

	void Actor::CenterPivot()
	{
		sf::FloatRect bound = mSprite.getGlobalBounds();
		mSprite.setOrigin(bound.width / 2.f, bound.height / 2.f);
	}

	void Actor::TickInternal(float deltaTime)
	{
		if (!IspendingDestroy())
		{
			Tick(deltaTime);
		}
	}

	sf::Vector2u Actor::GetWindowSize() const
	{
		return mOwningWorld->GetWindowSize();
	}
}

/*	NOTE To clarify yourself about the constructor sintaxis on the .cpp file:
*	Doing this:
		Actor::Actor(World* owningWorld, const std::string& texturePath)
			: mOwningWorld{ owningWorld },
			mHasBeganPlay{ false },
			mSprite{},
			mTexture{}
		{

		}
*	Is the same as doing this:
		Actor::Actor(World* owningWorld, const std::string& texturePath)
		{
			mOwningWorld = owningWorld;
			mHasBeganPlay = false;
			mSprite = new Sprite(); //Pseudo Code for C# I don't remember if C++ was the same way. I think it is.
			mTexture = new Textue();
		}
*
*	What confuses you more is that they are using two different new notations for you here. One is the {} instead of assignment. And the second is the members instantiation lik if it were a inheritance in C#.
*
*/