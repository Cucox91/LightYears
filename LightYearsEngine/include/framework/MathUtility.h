#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	sf::Vector2f RotationToVector(float rotation);

	float DegreesToRadians(float degrees);

	float RadiansToDegrees(float degrees);

	template<typename T>
	float GetVectorLenght(const sf::Vector2<T>& vector)
	{
		return std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
	}

	template<typename T>
	sf::Vector2<T>& ScaleVector(sf::Vector2<T>& vector, float amnt)
	{
		vector.x *= amnt;
		vector.y *= amnt;

		return vector;
	}

	template<typename T>
	sf::Vector2<T>& Normalize(sf::Vector2<T>& vector)
	{
		float vectorLenth = GetVectorLenght<T>(vector);
		if (vectorLenth == 0.f)
		{
			return sf::Vector2<T>{};
		}

		ScaleVector(vector, 1.0 / vectorLenth);

		return vector;
	}
}