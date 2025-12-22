#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "config.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{ 600,980,"Light Years", sf::Style::Titlebar | sf::Style::Close }		// The | thing here is called BitMask. Remember Bit Manipulation using or. And remember the Example you used at work the other day.
	{
		weak<World> newWorld = LoadWorld<World>();
		//newWorld.lock()->SpawnActor<Actor>();					//When we have a weak pointer always remember that we need to lock it. (I assume this is kind of a borrow checker or something.)
		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		std::string path = GetResourceDir();
		actorToDestroy.lock()->SetTexture(path + "/SpaceShooterRedux/PNG/playerShip1_blue.png");
		actorToDestroy.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
		actorToDestroy.lock()->SetActorRotation(90.f);
		counter = 0;
	}
	void GameApplication::Tick(float deltaTime)
	{
		//// This test example will destro an actor after two seconds.
		//counter += deltaTime;
		//if (counter > 2.f)
		//{
		//	if (!actorToDestroy.expired()) // This mean that the poiner was removed.
		//	{
		//		actorToDestroy.lock()->Destroy();
		//	}
		//}
	}
}


/*	Notes:
*	Application holds one World and World holds a lot of actors.
*/