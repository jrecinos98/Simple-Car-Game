#ifndef UPDATE_H
#define UPDATE_H
#include <string>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Sprites.h"
#include "Obstacles.h"
#include "Game.h"



namespace display_update{
    //Possible to create a window class that has these methods. could also implement a clock class
    void initiate_window(sf::RenderWindow* window);
    void draw_message(std::string words, std::string font_type, int Size, sf::Color color, sf::RenderWindow* window,int width= windowWidth,int height=windowHeigth);
    void window_update(sf::RenderWindow* window, sprites::Background* background, sprites::Car* car, std::vector<Obstacle::Enemy*> &enemy, std::string fps);

}


#endif // UPDATE_H
