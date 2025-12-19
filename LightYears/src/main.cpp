#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"

int main()
{
	// We create a pointer here because we want the application to run on the HEAP Memory.
	// Below there are the two examples of the old and new way to use the pointers.

	// Old Way:
	// ly::Application* app = new ly::Application();

	// New way:
	//std::unique_ptr<ly::Application> app{ new ly::Application() };

	// More new way:
	std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();

	// Running the App.
	app->Run();
}