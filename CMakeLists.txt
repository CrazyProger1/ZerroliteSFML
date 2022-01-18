cmake_minimum_required(VERSION 3.20)
project(ZerroliteSFML)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

#add_executable(ZerroliteSFML main.cpp zerrolite_old/srcs/GameCore.cpp zerrolite_old/include/GameCore.h zerrolite_old/srcs/Scene.cpp zerrolite_old/include/Scene.h zerrolite_old/srcs/Entity.cpp zerrolite_old/include/Entity.h zerrolite_old/srcs/GUI/Button.cpp zerrolite_old/include/GUI/Button.h zerrolite_old/include/types.h zerrolite_old/srcs/GUI/Text.cpp zerrolite_old/include/GUI/Text.h main.h scenes.h)
#add_executable(ZerroliteSFML tempMain.cpp)
add_executable(${PROJECT_NAME} main.cpp zerrolite/zerrolite.h zerrolite/srcs/Core/GameCore.cpp zerrolite/include/Core/GameCore.h zerrolite/srcs/Core/Scene.cpp zerrolite/include/Core/Scene.h zerrolite/include/types.h scenes.h zerrolite/srcs/Core/Entity.cpp zerrolite/include/Core/Entity.h zerrolite/include/Core/Scene.h zerrolite/srcs/GUI/Button.cpp zerrolite/include/GUI/Button.h zerrolite/srcs/GUI/Text.cpp zerrolite/include/GUI/Text.h zerrolite/srcs/Containers/Grid.cpp zerrolite/include/Containers/Grid.h zerrolite/srcs/Styles/ButtonStyle.cpp zerrolite/include/Styles/ButtonStyle.h zerrolite/srcs/Styles/TextStyle.cpp zerrolite/include/Styles/TextStyle.h zerrolite/srcs/GUI/Image.cpp zerrolite/include/GUI/Image.h zerrolite/srcs/GUI/CheckBox.cpp zerrolite/include/GUI/CheckBox.h zerrolite/srcs/Styles/CheckBoxStyle.cpp zerrolite/include/Styles/CheckBoxStyle.h zerrolite/srcs/Containers/Container.cpp zerrolite/include/Containers/Container.h scenes.h zerrolite/srcs/Core/Actor.cpp zerrolite/include/Core/Actor.h zerrolite/srcs/Core/Player.cpp zerrolite/include/Core/Player.h zerrolite/srcs/Core/NPC.cpp zerrolite/include/Core/NPC.h)
target_link_libraries(${PROJECT_NAME} sfml-graphics)
target_link_libraries(${PROJECT_NAME} stdc++fs)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)