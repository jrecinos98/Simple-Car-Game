cmake_minimum_required(VERSION 3.9)
project(carGame)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable(carGame
        cmake_modules/FindSFML.cmake
        "src/res/Car Images/blueCar.png"
        "src/res/Car Images/car model.png"
        "src/res/Car Images/darkCyan.png"
        "src/res/Car Images/darkPurple.png"
        "src/res/Car Images/GreyCar.png"
        "src/res/Car Images/LightBlueCar.png"
        "src/res/Car Images/LightBrown.png"
        "src/res/Car Images/magentaCar.png"
        "src/res/Car Images/redCar.png"
        "src/res/Car Images/whiteCar.png"
        "src/res/Car Images/yellowCar.png"
        "src/res/Enemies/Cactus_man/cactus man.png"
        "src/res/Enemies/Cactus_man/cactus man2.png"
        "src/res/Enemies/Cactus_man/cactus man3.png"
        "src/res/Enemies/Cactus_man/cactus man4.png"
        "src/res/Enemies/Cactus_man/cactus man5.png"
        "src/res/Enemies/Cactus_man/cactus man6.png"
        "src/res/Enemies/Cactus_man/cactus man7.png"
        "src/res/Enemies/Cactus_man/cactus man8.png"
        "src/res/Enemies/Cactus_man/cactus man9.png"
        "src/res/Enemies/Cactus_man/cactus man_10.png"
        src/res/Enemies/Cactus_man/cactusMan_sheet.png
        "src/res/Enemies/Pygmy/pygmy1(copy).png"
        src/res/Enemies/Pygmy/pygmy1.png
        src/res/Enemies/Pygmy/pygmy2.png
        src/res/Enemies/Pygmy/pygmy3.png
        src/res/Enemies/Pygmy/pygmy4.png
        src/res/Enemies/Pygmy/pygmy5.png
        src/res/Enemies/Pygmy/pygmy6.png
        src/res/Enemies/Pygmy/pygmy7.png
        src/res/Enemies/Pygmy/pygmy8.png
        src/res/Enemies/Pygmy/pygmy9.png
        src/res/Enemies/Pygmy/pygmy_1.png
        src/res/Enemies/Pygmy/pygmy_2.png
        src/res/Enemies/Pygmy/pygmy_3.png
        src/res/Enemies/Pygmy/pygmy_4.png
        src/res/Enemies/Cactus.png
        src/res/Enemies/DQVIDS_-_Armoured_wartoise.png
        src/res/Enemies/Galapagos_Turtle_SU.png
        src/res/Enemies/Kturtle_top_view.svg.png
        src/res/Enemies/Peabody_sheet.png
        src/res/Enemies/pygmy_sheet.png
        src/res/Enemies/rock2.png
        src/res/Enemies/turtle_sprite_sheet_by_audrianaandrews-dadqknb.png
        src/res/Fonts/CracklingFire.ttf
        src/res/Fonts/fps.otf
        src/res/Fonts/ka1.ttf
        src/res/Fonts/Nervous.ttf
        src/res/Fonts/SummerFire.ttf
        src/res/Fonts/transparent.ttf
        src/res/Fonts/Vintage.ttf
        src/res/Background.png
        src/Animation.cpp
        src/Animation.h
        src/Clock.cpp
        src/Clock.h
        src/Collision.cpp
        src/Collision.h
        src/Event.cpp
        src/Event.h
        src/Game.cpp
        src/Game.h
        src/Global.h
        src/main.cpp
        src/Obstacles.cpp
        src/Obstacles.h
        src/Sprites.cpp
        src/Sprites.h
        src/update.cpp
        src/Update.h
        README.md)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(carGame ${SFML_LIBRARIES})
endif()
