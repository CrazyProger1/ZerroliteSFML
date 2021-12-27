cmake_minimum_required(VERSION 3.20)
project(ZerroliteSFML)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(ZerroliteSFML main.cpp zerrolite/srcs/GameCore.cpp zerrolite/include/GameCore.h zerrolite/srcs/Scene.cpp zerrolite/include/Scene.h)


target_link_libraries(${PROJECT_NAME} sfml-graphics)
target_link_libraries(${PROJECT_NAME} stdc++fs)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)