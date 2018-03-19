#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "Global.h"
//#include "Sprites.h"
#include "Clock.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>

namespace Obstacle{///Delay the time the spawn. Otherwise they all come at the same time.
 class Enemy{
        public:
            Enemy(std::string filepath, int seed=0);//Sprite sheets are different. Different way to initialize sprite
            virtual ~Enemy();
            virtual void displace(int y_change);
            void reset(); //resets sprite to original location
            const int get_x(){return x_position;}
            const int get_y(){return y_position;}
            const int get_score(){return iterations;}

            void draw_sprite(sf::RenderWindow* window);//This one needs to be overwritten for animation

            virtual void damage()=0;
            virtual void animation()=0;

            sf::RectangleShape* enemy_sprite;//pointer to the sprite in the heap. Not happy of this.


        protected:
            int iterations;
            sf::Texture* enemy_texture;// pointer to the car_texture in the heap
            sf::FloatRect sprite_dimensions;
            int random_x(int seed);///somewhat random... Really, really crappy.
            int seed;
            int originY;
            double next_x;
            double next_y;
            int x_position;
            int y_position;
            game_clock::Clock animationClock;
            float start_time;
    };

class CactusMan: public Enemy{
    public:
        CactusMan(int seed);
        ~CactusMan();
        void damage();
        void animation();
    private:
        sf::Vector2u textureSize;

};

class Pygmy: public Enemy{
    public:
        Pygmy( int seed);
        ~Pygmy();
        void damage();
        void animation();
    private:

        sf::Vector2u textureSize;

};

class Cactus: public Enemy{
public:
    Cactus( int seed);
    ~Cactus(){}
    void damage(){}
    void animation(){}//Does nothing.
};

class Peabody: public Enemy{
public:
    Peabody( int seed);
    ~Peabody(){}
    void damage(){}
    void animation();

private:
    sf::Vector2u textureSize;
};

class Rock: public Enemy{
public:
    Rock( int seed);
    ~Rock(){}
    void damage(){}
    void animation(){}// does nothing
};

void  load_enemies(std::vector<Obstacle::Enemy*> &Enemies);

}
#endif // OBSTACLES_H
