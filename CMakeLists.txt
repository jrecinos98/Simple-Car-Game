cmake_minimum_required(VERSION 3.9)
project(carGame)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable(carGame
        cmake_modules/FindSFML.cmake
        "res/Car Images/blueCar.png"
        "res/Car Images/car model.png"
        "res/Car Images/darkCyan.png"
        "res/Car Images/darkPurple.png"
        "res/Car Images/GreyCar.png"
        "res/Car Images/LightBlueCar.png"
        "res/Car Images/LightBrown.png"
        "res/Car Images/magentaCar.png"
        "res/Car Images/redCar.png"
        "res/Car Images/whiteCar.png"
        "res/Car Images/yellowCar.png"
        "res/Enemies/Cactus_man/cactus man.png"
        "res/Enemies/Cactus_man/cactus man2.png"
        "res/Enemies/Cactus_man/cactus man3.png"
        "res/Enemies/Cactus_man/cactus man4.png"
        "res/Enemies/Cactus_man/cactus man5.png"
        "res/Enemies/Cactus_man/cactus man6.png"
        "res/Enemies/Cactus_man/cactus man7.png"
        "res/Enemies/Cactus_man/cactus man8.png"
        "res/Enemies/Cactus_man/cactus man9.png"
        "res/Enemies/Cactus_man/cactus man_10.png"
        res/Enemies/Cactus_man/cactusMan_sheet.png
        "res/Enemies/Pygmy/pygmy1(copy).png"
        res/Enemies/Pygmy/pygmy1.png
        res/Enemies/Pygmy/pygmy2.png
        res/Enemies/Pygmy/pygmy3.png
        res/Enemies/Pygmy/pygmy4.png
        res/Enemies/Pygmy/pygmy5.png
        res/Enemies/Pygmy/pygmy6.png
        res/Enemies/Pygmy/pygmy7.png
        res/Enemies/Pygmy/pygmy8.png
        res/Enemies/Pygmy/pygmy9.png
        res/Enemies/Pygmy/pygmy_1.png
        res/Enemies/Pygmy/pygmy_2.png
        res/Enemies/Pygmy/pygmy_3.png
        res/Enemies/Pygmy/pygmy_4.png
        res/Enemies/Cactus.png
        res/Enemies/DQVIDS_-_Armoured_wartoise.png
        res/Enemies/Galapagos_Turtle_SU.png
        res/Enemies/Kturtle_top_view.svg.png
        res/Enemies/Peabody_sheet.png
        res/Enemies/pygmy_sheet.png
        res/Enemies/rock2.png
        res/Enemies/turtle_sprite_sheet_by_audrianaandrews-dadqknb.png
        res/Fonts/CracklingFire.ttf
        res/Fonts/fps.otf
        res/Fonts/ka1.ttf
        res/Fonts/Nervous.ttf
        res/Fonts/SummerFire.ttf
        res/Fonts/transparent.ttf
        res/Fonts/Vintage.ttf
        res/Background.png
        src/def/Animation.cpp
        src/includes/Animation.h
        src/def/Clock.cpp
        src/includes/Clock.h
        src/def/Collision.cpp
        src/includes/Collision.h
        src/def/Event.cpp
        src/includes/Event.h
        src/def/Game.cpp
        src/includes/Game.h
        src/includes/Global.h
        src/def/main.cpp
        src/def/Obstacles.cpp
        src/includes/Obstacles.h
        src/def/Sprites.cpp
        src/includes/Sprites.h
        src/def/update.cpp
        src/includes/Update.h
        README.md)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(carGame ${SFML_LIBRARIES})
endif()
