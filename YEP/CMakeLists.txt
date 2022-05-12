cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR /src/)
set(ENC_DIR encapsulation/)

project(bomberman)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(bomberman
        src/main.cpp
        src/menu/menu.cpp
        src/game/gamecore.cpp
        src/game/gamebox.cpp
        src/game/gamebomba.cpp
        src/game/bombaInterraction.cpp
        src/game/borderWall.cpp
        src/game/destructibleWall.cpp
        src/game/player.cpp
        src/map/proceduralMap.cpp
        src/error/error.cpp
        Include/encapsulation/MyAudioE.cpp
        Include/encapsulation/MyCoreE.cpp
        Include/encapsulation/MyKeyE.cpp
        Include/encapsulation/MyModelsE.cpp
        Include/encapsulation/MyShapesE.cpp
        Include/encapsulation/MyTextureE.cpp
        Include/encapsulation/MyTextE.cpp
        )

target_link_libraries(bomberman PRIVATE raylib)
# target_compile_options(bomberman PRIVATE -Wall -Wextra)
target_include_directories(bomberman PRIVATE Include/)