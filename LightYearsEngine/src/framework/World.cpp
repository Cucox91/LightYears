#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"



namespace ly
{
	ly::World::World(Application* app)
		:mOwningApp{ app },
		mBeginPlay{ false },
		mActors{},
		mPendingActors{}
	{

	}

	void World::BeginPlayInternal()
	{
		if (!mBeginPlay)
		{
			mBeginPlay = true;
			BeginPlay();
		}
	}

	void World::TickInternal(float deltaTime)
	{
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}
		mPendingActors.clear();

		// We iterate over the actors, if they are marked for deletion then we remove them from the list.
		// Otherwise we tick it.
		// We are usng iterators here because it helps with the dynamic deletion. Remember in C# what happens when we remove an item in the middle of the iteration. Here is the same. It breaks.
		// The code below is kind of a While loop. It will not break if the Collection Changes.
		for (auto iter = mActors.begin(); iter != mActors.end();)
		{
			if (iter->get()->IspendingDestroy())
			{
				iter = mActors.erase(iter);			// This will remove the current iterator and will return the next one.
			}
			else
			{
				iter->get()->TickInternal(deltaTime);
				++iter;
			}
		}

		/*for (shared<Actor> actor : mActors)
		{
			actor->Tick(deltaTime);
		}*/

		Tick(deltaTime);
	}

	World::~World()
	{
	}

	void World::Render(sf::RenderWindow& window)
	{
		for (auto& actor : mActors)
		{
			actor->Render(window);
		}
	}

	void World::BeginPlay()
	{
		LOG("began play");
	}

	void World::Tick(float deltaTime)
	{
		LOG("Tick at frame rate %f", 1.f / deltaTime);
	}
}
