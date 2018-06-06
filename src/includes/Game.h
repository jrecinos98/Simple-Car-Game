#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Update.h"
#include "Global.h"
#include "Event.h"
#include "Clock.h"
#include "Animation.h"


namespace car_game{

    void game_loop();
    void game_over(bool &game_paused, sf::RenderWindow* window, sprites::Car *car, std::vector<Obstacle::Enemy*> &Enemies);
    float get_fps(int &frames, float &starttime, game_clock::Clock *updateClock);
    bool crash(std::vector<Obstacle::Enemy*> &Enemies, sprites::Car *car);

}

#endif // GAME_H
