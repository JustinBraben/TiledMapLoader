#ifndef UTIL_HPP
#define UTIL_HPP

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include <pugixml.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void writeFileContentsToConsole(const std::filesystem::path& filePath);
void writeXmlToConsole(const std::filesystem::path& filePath);
void writeTileSetsToConsole(const std::filesystem::path& filePath);
void writeJsonToConsole(const std::filesystem::path& filePath);
json getJsonContents(std::string& filePath);

#endif // !UTIL_HPP