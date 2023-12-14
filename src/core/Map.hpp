class Map {
public:
	Map(const char* map);
	~Map();

	int getHeight() { return height; }
	bool isInfinite() { return infinite; }
	std::vector<Layer> getLayers() { return layers; }
	int getNextLayerId() { return nextlayerid; }
	int getNextObjectId() { return nextobjectid; }
	std::string getOrientation() { return orientation; }
	std::string getRenderOrder() { return renderorder; }
	std::string getTiledVersion() { return tiledversion; }
	int getTileHeight() { return tileheight; }
	std::vector<TileSetMap> getTileSetMap() { return tilesets; }
	int getTileWidth() { return tilewidth; }
	std::string getType() { return type; }
	float getVersion() { return version; }
	int getWidth() { return width; }

private:
	int height;
	bool infinite;
	std::vector<Layer> layers;
	int nextlayerid;
	int nextobjectid;
	std::string orientation;
	std::string renderorder;
	std::string tiledversion;
	int tileheight;
	std::vector<TileSetMap> tilesets;
	int tilewidth;
	std::string type;
	float version;
	int width;
};