#pragma once

#include <string>


// What this function uses to differenciate between when we run on Debug vs Release Modes. Remember the location of the resources changes based on this.
// If we are in debug mode we don't want to copy the files every time we run the project. This is to optimize compilation/debugging.
std::string GetResourceDir()
{
#ifdef NDEBUG	//release build
	return "assets/";
#else
	return "C:/Users/razie/source/Games/LightYears/LightYearsGame/assets/";
#endif // NDEBUG 

}

// This file will not be included on the Compiled folder. Is only used by CMake.
