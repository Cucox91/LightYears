#pragma once

namespace ly
{
	class Application;
	class World
	{
	public:
		World(Application* app);
		void BeginPlayInternal();
		void TickInternal(float deltaTime);

		virtual ~World(); // The virtual in front of the destructor is for inheritance to allow child classes to trigger the parent destructor.
	private:
		void BeginPlay();
		void Tick(float deltaTime);

		Application* mOwningApp;
		bool mBeginPlay;
	};
}