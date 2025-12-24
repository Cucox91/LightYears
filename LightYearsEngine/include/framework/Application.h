#pragma once //This line only includes a header once.
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Application
	{
	public:
		Application(unsigned int windowWidht, unsigned int windowHeight, const std::string& title, sf::Uint32 style);
		void Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld();

		sf::Vector2u GetWindowSize() const;
	private:
		void TickInternal(float deltaTime);
		void RenderInternal();

		virtual void Render();
		virtual void Tick(float deltaTime);

		float mTargetFrameRate;
		sf::RenderWindow mWindow;
		sf::Clock mTickClock;

		shared<World> currentWorld;
		sf::Clock mCleanCycleClock;
		float mCleanCycleInterval;
	};

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		shared<WorldType> newWorld{ new  WorldType{this} };
		currentWorld = newWorld;
		return newWorld;
	}
}


/*
	What we are doing here is kind of inheritance. world is the base class. And newWorld is the child class. Read the code with this in mind and you will get it better.
	In addition, it looks like we are passing the Application class instance to the newWorld class. Via WorldType constructor.

	Think of the .h and .cpp as in Interfaces and classes on C#. One declares the contract and the other implements it.
	But in addition the headers in C++ can handle more things. (Members fields, public and private, etc).
	Notice that at all times the templates goes on the .h files. and that is why it can be confusing to see code on the .h file. This is because is usually handling templates.


*/