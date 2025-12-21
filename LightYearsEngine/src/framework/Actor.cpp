#include "framework/Actor.h"
#include "framework/Core.h"

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
		LOG("Actor Tick");
	}

	void Actor::SetTexture(const std::string& texturePath)
	{
		mTexture.loadFromFile(texturePath);
		mSprite.setTexture(mTexture);

		int textureWidht = mTexture.getSize().x;
		int textureHeight = mTexture.getSize().y;
		mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{},sf::Vector2i{textureWidht,textureHeight} });		// This will define the texture rectangle. from the 0,0 to the widht and height of the texture.
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (IspendingDestroy())
		{
			return;
		}

		window.draw(mSprite);
	}

	void Actor::TickInternal(float deltaTime)
	{
		if (!IspendingDestroy())
		{
			Tick(deltaTime);
		}
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