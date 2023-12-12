#include "util.hpp"

void writeFileContentsToConsole(const std::filesystem::path& filePath)
{
	if (!std::filesystem::exists(filePath))
	{
		// Error
	}

	// Open the file using an input file stream
	std::ifstream inputFile(filePath);

	if (!inputFile.is_open())
	{
		// error
	}

	// Read and print each line from the file
	std::string line;
	while (std::getline(inputFile, line)) {
		std::cout << line << "\n";
	}

	// Close the file stream
	inputFile.close();
}

void writeXmlToConsole(const std::filesystem::path& filePath)
{
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

void writeTileSetsToConsole(const std::filesystem::path& filePath)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filePath.c_str());
	if (!result)
	{
		// error
	}

	for (const auto& child : doc.children())
	{
		std::cout << child.name() << "\n";

		for (const auto& attr : child.attributes())
		{
			std::cout << "  [Attribute:" << attr.name() << " = " << attr.value() << "]" << "\n";
		}

		std::cout << "\n";

		for (const auto& nestChild1 : child.children())
		{
			std::cout << "  " << nestChild1.name() << "\n";

			for (const auto& attr : nestChild1.attributes())
			{
				std::cout << "  [Attribute:" << attr.name() << " = " << attr.value() << "]" << "\n";
			}

			for (const auto& nestChild2 : nestChild1.children())
			{
				std::cout << "  " << nestChild2.name() << "\n";

				for (const auto& attr : nestChild2.attributes())
				{
					std::cout << "    [Attribute:" << attr.name() << " = " << attr.value() << "]" << "\n";
				}
			}

			std::cout << "\n";
		}
	}
}
