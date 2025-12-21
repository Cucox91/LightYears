#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"

namespace ly
{
	Application::Application(unsigned int windowWidht, unsigned int windowHeight, const std::string& title, sf::Uint32 style) :
		mWindow{ sf::VideoMode(windowWidht,windowHeight), title, style },
		mTargetFrameRate{ 60.f },
		mTickClock{},
		currentWorld{ nullptr }
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

			float frameDeltaTime = mTickClock.restart().asSeconds(); // This will return the amount of time ellapsed.
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;					// This will always keep the accumulated time below the target delta time. Because if is above it will take out the target and keep the difference.
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
		if (currentWorld)
		{
			currentWorld->BeginPlayInternal();
			currentWorld->TickInternal(deltaTime);
		}
	}

	// To Render we clear our window. We create the shape we want to draw. We draw it using the Render Fucntion and then we display it on the RenderInternal Function.
	void Application::RenderInternal()
	{
		mWindow.clear();

		Render();

		mWindow.display();
	}

	void Application::Render()										// This is a template function (Programming, not language specific). Because of this our function is virtual.
	{
		if (currentWorld)
		{
			currentWorld->Render(mWindow);
		}
	}

	void Application::Tick(float deltaTime) {

	}
}
