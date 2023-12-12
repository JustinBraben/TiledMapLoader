#include "core/app.hpp"

int main()
{
    const std::filesystem::path assets = "../../../../assets";
    const std::filesystem::path tmxLevelFile = "../../../../data/tiledMapFiles/level1.tmx";
    Application app(tmxLevelFile, assets);
    app.run();
}