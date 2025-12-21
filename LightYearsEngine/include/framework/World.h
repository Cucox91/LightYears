#pragma once
#include <framework/Core.h>
#include <framework/Actor.h>

#include <SFML/Graphics.hpp>

namespace ly
{
	class Actor;
	class Application;
	class World
	{
	public:
		World(Application* app);
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		void Render(sf::RenderWindow& window);

		virtual ~World();						// The virtual in front of the destructor is for inheritance to allow child classes to trigger the parent destructor.

		template<typename ActorType>
		weak<ActorType> SpawnActor();			// Spawn means to create.
	private:
		void BeginPlay();
		void Tick(float deltaTime);

		Application* mOwningApp;
		bool mBeginPlay;

		List<shared<Actor>> mActors;
		List<shared<Actor>> mPendingActors;		// The Pending Actors is because we don't want to add a new actor to the list of actors while we are looping through it.
	};

	template<typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}