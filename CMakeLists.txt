cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Fetch and declare EnTT as an external dependency
FetchContent_Declare(EnTT
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG v3.12.2)  # Specify the desired tag or commit
FetchContent_MakeAvailable(EnTT)

FetchContent_Declare(pugixml
    GIT_REPOSITORY https://github.com/zeux/pugixml.git
    GIT_TAG v1.10)
FetchContent_MakeAvailable(pugixml)

FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
)  # Specify the desired tag or commit
FetchContent_MakeAvailable(json)

# This fetch content is used to deal with a single file header
FetchContent_Declare(tileson
    GIT_REPOSITORY https://github.com/SSBMTonberry/tileson.git
    GIT_TAG v1.4.0
)  # Specify the desired tag or commit
# Fetch the content at configure time
FetchContent_GetProperties(tileson)
if(NOT tileson_POPULATED)
  FetchContent_Populate(tileson)
endif()

# Add the include directory of the fetched content to your project
include_directories(${tileson_SOURCE_DIR})

add_executable(CMakeSFMLProject src/main.cpp "src/core/app.cpp" "src/utils/util.cpp" )
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics pugixml EnTT::EnTT nlohmann_json::nlohmann_json ${tileson_SOURCE_DIR})
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS CMakeSFMLProject)
