#pragma once
#include <SFML/Graphics.hpp>
#include <framework/Core.h>

namespace ly
{
	class AssetManager
	{
	public:
		static AssetManager& Get();
		shared<sf::Texture> LoadTexture(const std::string& path);
		void CleanCycle();
		void SetAssetRootDirectory(const std::string& directory);
	// A singleton. This will be only one instance of this class.
	protected:
		AssetManager();
	private:
		static unique<AssetManager> assetManager;	// Only one copy because is static.
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
		std::string mRootDirectory;
	};
}