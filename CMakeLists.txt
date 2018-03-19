cmake_minimum_required(VERSION 3.9)
project(carGame)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable(carGame
        "Car Images/blueCar.png"
        "Car Images/car model.png"
        "Car Images/darkCyan.png"
        "Car Images/darkPurple.png"
        "Car Images/GreyCar.png"
        "Car Images/LightBlueCar.png"
        "Car Images/LightBrown.png"
        "Car Images/magentaCar.png"
        "Car Images/redCar.png"
        "Car Images/whiteCar.png"
        "Car Images/yellowCar.png"
        "Enemies/Cactus_man/cactus man.png"
        "Enemies/Cactus_man/cactus man2.png"
        "Enemies/Cactus_man/cactus man3.png"
        "Enemies/Cactus_man/cactus man4.png"
        "Enemies/Cactus_man/cactus man5.png"
        "Enemies/Cactus_man/cactus man6.png"
        "Enemies/Cactus_man/cactus man7.png"
        "Enemies/Cactus_man/cactus man8.png"
        "Enemies/Cactus_man/cactus man9.png"
        "Enemies/Cactus_man/cactus man_10.png"
        Enemies/Cactus_man/cactusMan_sheet.png
        "Enemies/Pygmy/pygmy1(copy).png"
        Enemies/Pygmy/pygmy1.png
        Enemies/Pygmy/pygmy2.png
        Enemies/Pygmy/pygmy3.png
        Enemies/Pygmy/pygmy4.png
        Enemies/Pygmy/pygmy5.png
        Enemies/Pygmy/pygmy6.png
        Enemies/Pygmy/pygmy7.png
        Enemies/Pygmy/pygmy8.png
        Enemies/Pygmy/pygmy9.png
        Enemies/Pygmy/pygmy_1.png
        Enemies/Pygmy/pygmy_2.png
        Enemies/Pygmy/pygmy_3.png
        Enemies/Pygmy/pygmy_4.png
        Enemies/Cactus.png
        Enemies/DQVIDS_-_Armoured_wartoise.png
        Enemies/Galapagos_Turtle_SU.png
        Enemies/Kturtle_top_view.svg.png
        Enemies/Peabody_sheet.png
        Enemies/pygmy_sheet.png
        Enemies/rock2.png
        Enemies/turtle_sprite_sheet_by_audrianaandrews-dadqknb.png
        Fonts/CracklingFire.ttf
        Fonts/fps.otf
        Fonts/ka1.ttf
        Fonts/Nervous.ttf
        Fonts/SummerFire.ttf
        Fonts/transparent.ttf
        Fonts/Vintage.ttf
        Animation.cpp
        Animation.h
        Background.png
        Clock.cpp
        Clock.h
        Collision.cpp
        Collision.h
        Event.cpp
        Event.h
        Game.cpp
        Game.h
        Global.h
        main.cpp
        Obstacles.cpp
        Obstacles.h
        Sprites.cpp
        Sprites.h
        update.cpp
        Update.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(carGame ${SFML_LIBRARIES})
endif()
