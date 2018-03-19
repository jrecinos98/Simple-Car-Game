#ifndef SPRITES_H
#define SPRITES_H
#include <string>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Global.h"
#include "Obstacles.h"



namespace sprites
{

    class Car
    {
        public:
            Car(std::string model);
            ~Car();
            void set_position(int x_change);
            bool outOfBounds();
            void startLocation();
            void reset();  //resets sprite to original location
            const int get_x();
            const int get_y();
            void draw_sprite(sf::RenderWindow* window);
            sf::FloatRect boundingBox()const {return sprite_dimensions;}
            const int Width(){return sprite_dimensions.width;}
            const int Height(){return sprite_dimensions.height;}
            bool collision(Obstacle::Enemy* enemy);

        private:
            sf::RectangleShape* car_sprite;///pointer to the car_sprite in the heap.
            sf::Texture* car_texture;// pointer to the car_texture in the heap
            sf::FloatRect sprite_dimensions;
            int originX;
            int originY;
            int x_position;
            int y_position;
    };


    class Background
    {
        public:
            Background(std::string level);
            ~Background ();
            void draw_sprite(sf::RenderWindow* window);
        private:
            sf::Sprite* background_sprite;
            sf::Texture* background_texture;
    };

}
#endif // GAME_H


