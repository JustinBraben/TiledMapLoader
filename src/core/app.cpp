#include "app.hpp"

void Application::init(const std::filesystem::path& filePath)
{
    initWindow();

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filePath.c_str());
	if (!result)
	{
		// error
	}

    for (pugi::xml_node node = doc.first_child(); node; node = node.next_sibling()) {
        std::cout << "Node: " << node.name() << "\n";

        // Print attributes
        for (pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute()) {
            std::cout << "  [Attribute: " << attr.name() << " = " << attr.value() << "]" << "\n";
        }

        std::cout << "\n";

        for (pugi::xml_node child = node.first_child(); child; child = child.next_sibling()) {
            std::cout << "  Child: " << child.name() << "\n";

            // Print attributes of child node
            for (pugi::xml_attribute attr = child.first_attribute(); attr; attr = attr.next_attribute()) {
                std::cout << "    [Attribute: " << attr.name() << " = " << attr.value() << "]" << "\n";
            }

            // Print text of child node if any
            if (!child.text().empty()) {
                std::cout << "    [Text: " << child.text().get() << "]" << "\n";
            }

            std::cout << "\n";
        }

        std::cout << "\n";
    }
}

void Application::initWindow()
{
    m_window.create(sf::VideoMode(1920u, 1080u), "CMake SFML Project");
    m_window.setFramerateLimit(144);
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

Application::Application(const std::filesystem::path& filePath)
{
	init(filePath);
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