# Minimum required version of CMake for the Project.
cmake_minimum_required(VERSION 3.6)

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

# This will allow use to fetch external content. In this case from SFML.
# https://github.com/SFML/SFML
include(FetchContent)
set(SFML_LIB_NAME SFM)

FetchContent_Declare(
	${SFML_LIB_NAME}
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.6.2
	GIT_SHALLOW FALSE
)

# This will Copy the Content of the Git Repository to our local computer.
FetchContent_MakeAvailable(${SFML_LIB_NAME})
# After this step we need to link the libraries. This is being done in the sub directory.

# Creating a Variable for the Project Name:
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

# Here we connect to a sub directory with the same name for CMake that will be at the same src folder level.
add_subdirectory(LightYears)
# After this Step we create an executable file. This is done in the subdirectory.
