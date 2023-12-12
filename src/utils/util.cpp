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
