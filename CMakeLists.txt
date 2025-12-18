# Minimum required version of CMake for the Project.
cmake_minimum_required(VERSION 3.27.7)

# Creating the Project with Naming Versioning and Launguage to use.
project(
	LightYears 
	VERSION 1.0.0 
	LANGUAGES C CXX
)

# Setting Project Constrains and Properties. Variables Creation.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Creating a Variable for the Project Name:
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

# Here we connect to a sub directory with the same name for CMake that will be at the same src folder level.
add_subdirectory(LightYears)