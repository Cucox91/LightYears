#include <iostream>
#include "framework/Application.h"

namespace ly
{
	Application::Application() :
		mWindow{ sf::VideoMode(1024,1440), "Ligth Years" },
		mTargetFrameRate{ 60.f },
		mTickClock{}
	{

	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;								// We are going to use this to calculate the amout of time it passed beteen while loops.
		float targetDeltaTime = 1.f / mTargetFrameRate;				// One second divided by the target Frame Rate. 
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}

			// What all this code below does is to accumulate the rates until is above the desired frame rate.
			// At that moment it restart the accummulated time to below the delta and trigger a render (change).
			accumulatedTime += mTickClock.restart().asSeconds();	// This will return the amount of time ellapsed.
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;					// This will always keep the accumulated time below the target delta time. Because if is above it will take out the target and keep the difference.
				Tick(targetDeltaTime);
				Render();
			}
		}
	}

	void Application::Tick(float deltaTime)
	{
		std::cout << "ticking at framerate: " << 1.f / deltaTime << std::endl;
	}

	void Application::Render()
	{
		mWindow.clear();

		sf::RectangleShape rect{ sf::Vector2f{100,100} };
		rect.setFillColor(sf::Color::Green);
		mWindow.draw(rect);

		mWindow.display();
	}
}
