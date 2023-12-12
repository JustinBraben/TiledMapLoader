#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "../utils/util.hpp"

#include <SFML/Graphics.hpp>
#include <entt/entity/registry.hpp>

using xml_node = pugi::xml_node;
using xml_document = pugi::xml_document;
using xml_parse_result = pugi::xml_parse_result;

class Application
{
protected:
	sf::RenderWindow m_window;
	bool m_running = true;
	std::map<std::string, sf::Texture> m_textureMap;
	entt::registry m_reg;

	void init(const std::filesystem::path& tmxFilePath, const std::filesystem::path& assetsFolderPath);
	void initWindow();
	void resetEntities();
	void loadTexturesRecursive(const std::filesystem::path& folderPath);
	void loadEntitiesFromTmx(const std::filesystem::path& filePath);
	void update();
	
	void sUserInput();
	void sRender();

public:
	Application();
	Application(const std::filesystem::path& tmxFilePath, const std::filesystem::path& assetsFolderPath);
	~Application();

	void quit();
	void run();

	bool isRunning();
};

#endif // !APPLICATION_HPP