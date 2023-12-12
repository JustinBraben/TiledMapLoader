#ifndef UTIL_HPP
#define UTIL_HPP

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include <pugixml.hpp>

void writeFileContentsToConsole(const std::filesystem::path& filePath);
void writeXmlToConsole(const std::filesystem::path& filePath);
void writeTileSetsToConsole(const std::filesystem::path& filePath);

#endif // !UTIL_HPP