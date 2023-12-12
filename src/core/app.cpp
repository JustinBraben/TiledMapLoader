#include "app.hpp"

void Application::init(const std::filesystem::path& tmxFilePath, const std::filesystem::path& assetsFolderPath)
{
    initWindow();

    loadTexturesRecursive(assetsFolderPath);

    writeXmlToConsole(tmxFilePath);

    loadEntitiesFromTmx(tmxFilePath);
}

void Application::initWindow()
{
    m_window.create(sf::VideoMode(1920u, 1080u), "CMake SFML Project");
    m_window.setFramerateLimit(144);
}

void Application::resetEntities()
{
    m_reg.clear();
}

void Application::loadTexturesRecursive(const std::filesystem::path& folderPath)
{
    for (auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        auto filePath = entry.path();

        if (std::filesystem::is_directory(filePath))
        {
            // Recursive call for subdirectories
            loadTexturesRecursive(filePath);
        }
        else
        {
            auto extension = filePath.extension().string();

            // Only do .png files (for now)
            if (extension == ".png")
            {
                auto stem = filePath.stem().string();

                sf::Texture texture;
                if (!texture.loadFromFile(filePath.string()))
                {
                    // Handle error..
                    std::cerr << "Error loading texture from file: " << filePath << "\n";
                }
                else
                {
                    m_textureMap[stem] = texture;
                }
            }
        }
    }
}

void Application::loadEntitiesFromTmx(const std::filesystem::path& filePath)
{
    
}

void Application::update()
{
    sUserInput();

    sRender();
}

void Application::sUserInput()
{
    sf::Event evnt;
    while (m_window.pollEvent(evnt)) {

        if (evnt.type == sf::Event::Closed) {
            quit();
        }

        if (evnt.type == sf::Event::KeyPressed) {

            if (evnt.key.code == sf::Keyboard::X) {
                std::cout << "screenshot saved to " << "test.png" << "\n";
                sf::Texture texture;
                texture.create(m_window.getSize().x, m_window.getSize().y);
                texture.update(m_window);

                if (texture.copyToImage().saveToFile("test.png")) {
                    std::cout << "screenshot saved to " << "test.png" << "\n";
                }
            }
        }

        if (evnt.type == sf::Event::KeyReleased)
        {
            
        }
    }
}

void Application::sRender()
{
    m_window.clear();

    m_window.display();
}

Application::Application()
{
}

Application::Application(const std::filesystem::path& tmxFilePath, const std::filesystem::path& assetsFolderPath)
{
	init(tmxFilePath, assetsFolderPath);
}

Application::~Application()
{
}

void Application::quit()
{
    m_running = false;
}

void Application::run()
{
    std::cout << "Application is now running\n";

    while (isRunning())
    {
        update();
    }

    m_window.close();

    std::cout << "Game is now done running, Press Enter to continue...\n";
}

bool Application::isRunning()
{
    return m_running && m_window.isOpen();
}