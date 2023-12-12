#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>
#include <pugixml.hpp>

//using fs = std::filesystem::;

class Application
{
protected:
	sf::RenderWindow m_window;
	bool m_running = true;
	void init(const std::filesystem::path& filePath);
	void initWindow();
	void update();
	
	void sUserInput();
	void sRender();

public:
	Application();
	Application(const std::filesystem::path& filePath);
	~Application();

	void quit();
	void run();

	bool isRunning();
};

#endif // !APPLICATION_HPP