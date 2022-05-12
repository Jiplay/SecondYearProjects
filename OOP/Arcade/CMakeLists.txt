cmake_minimum_required( VERSION 3.9 )
project( Arcade )

SET(CMAKE_C_COMPILER /usr/bin/x86_64-linux-gnu-g++-4.9)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wfloat-equal -Wshadow \
-Weffc++ -Wstrict-overflow=5 -Wcast-align -Wconversion -ftrapv \
-Wuninitialized -Wnon-virtual-dtor -fPIC \
-D_GLIBCXX_USE_CXX11_ABI=0")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_library( _arcade_sfml SHARED
    lib/ILibs.hpp
    lib/ALibs.hpp
    lib/SFML/SFML.cpp
    lib/SFML/SFML.hpp
)

add_library( _arcade_sdl2 SHARED
    lib/ILibs.hpp
    lib/ALibs.hpp
    lib/SLD2/SDL2.cpp
    lib/SLD2/SDL2.hpp
)

add_library( _arcade_ncurses SHARED
    lib/ILibs.hpp
    lib/ALibs.hpp
    lib/NCURSES/ncurses.cpp
    lib/NCURSES/ncurses.hpp
)

add_executable( arcade
    main.cpp
    src/core/main_core.cpp
    src/core/core.hpp
    src/exceptions/error.cpp
    src/exceptions/error.hpp
)

set_target_properties( _arcade_sfml PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs" )
set_target_properties( _arcade_sdl2 PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs" )
set_target_properties( _arcade_ncurses PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs")


target_link_libraries(_arcade_ncurses  -lcurses)
target_link_libraries(_arcade_sfml sfml-graphics sfml-window sfml-system)
target_link_libraries(_arcade_sdl2 SDL2 SDL2_image SDL2_ttf)
target_link_libraries(arcade dl)