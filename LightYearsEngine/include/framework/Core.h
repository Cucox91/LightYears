#pragma once

#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>

namespace ly
{

	// This will be like an alias for the unique pointer. 
	template<typename T>
	using unique = std::unique_ptr<T>;

	template<typename T>
	using shared = std::shared_ptr<T>;

	template<typename T>
	using weak = std::weak_ptr<T>;

	template<typename T>
	using List = std::vector<T>;

	// Ordered Map.(Hash Table, kind of) The Pr Parameter is a Predicate that will take the key and organize it from lesser to greatter. O(n) To find the item.
	template<typename keyType, typename valueType, typename Pr = std::less<keyType>>
	using Map = std::map<keyType, valueType, Pr>;

	// Unordered Map. (Dictionary) O(1) to find the items.
	template<typename keyType, typename valueType, typename Hasher = std::hash<keyType>>
	using Dictionary = std::unordered_map<keyType, valueType, Hasher>;




	// Below is a macro for handling the logging system.
	// What it does is simple. Everywhere we add LOG() it will be kind of replace by printf by the compiler.
	// The ...  is called variatic arguments.
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}