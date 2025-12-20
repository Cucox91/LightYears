#pragma once
#include <framework/Application.h>
#include <framework/World.h>

namespace ly
{
	class GameApplication : public Application
	{
	public:
		GameApplication::GameApplication()
		{
			LoadWorld<World>();
		}
	};
}