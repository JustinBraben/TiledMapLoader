#ifndef TILESET_HPP
#define TILESET_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

class TileSet
{
protected:
	int m_id;
	std::string m_name;
	int m_tileWidth;
	int m_tileHeight;
	int m_tileCount;
	int m_columns;
	std::string m_tilerendersize = "grid";
	std::filesystem::path m_source;
public:
	TileSet();
	~TileSet();
};

#endif // !TILESET_HPP