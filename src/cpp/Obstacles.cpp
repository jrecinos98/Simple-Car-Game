#include "Obstacles.h"

namespace Obstacle{

Enemy::Enemy(std::string filepath, int seed){
    enemy_texture= new sf::Texture();
    enemy_texture->loadFromFile(filepath);
    enemy_texture->setSmooth(true);
    originY= -1*windowHeigth;
    x_position= random_x(seed);
    y_position= originY;
    this->seed=seed;
    iterations=0;
    next_x=0;
    next_y=0;

}
Enemy::~Enemy(){
    delete enemy_sprite;
    delete enemy_texture;
}
int Enemy::random_x( int seed){
    int range= (windowWidth)+1;
    srand((unsigned)time(0)+seed);
    int random_integer= rand()%(range-100);
    return random_integer;
}
void Enemy::displace(int y_change){
    y_position+=y_change;
    if (y_position>= windowWidth-200){
        y_position= originY;
        x_position= random_x(seed);
        iterations++;
    }
    enemy_sprite->setPosition(x_position,y_position);

    }
void Enemy::reset(){
    y_position=originY;
    x_position=random_x(seed);
    enemy_sprite->setPosition(x_position,y_position);
    iterations=0;
}

void Enemy::draw_sprite(sf::RenderWindow* window){
    if(animationClock.elapsed_time("seconds")-start_time>=.065){
        animation();
        start_time=animationClock.elapsed_time("seconds");}
     window->draw(*enemy_sprite);
}




CactusMan::CactusMan(int seed): Enemy("Enemies/Cactus_man/cactusMan_sheet.png",seed){
    textureSize= enemy_texture->getSize();
    textureSize .x/=1;
    textureSize.y /=10;
    enemy_sprite= new sf::RectangleShape(sf::Vector2f(110.0f,140.0f));
    enemy_sprite->setTexture(enemy_texture);
    enemy_sprite->setTextureRect(sf::IntRect(textureSize.x*0,textureSize.y*0,textureSize.x,textureSize.y));
    sprite_dimensions=enemy_sprite->getGlobalBounds();
    enemy_sprite->setPosition(x_position,y_position);//x_position,y_position);
}
CactusMan::~CactusMan(){}
void CactusMan::damage(){
}
void CactusMan::animation(){
    enemy_sprite->setTextureRect(sf::IntRect(textureSize.x*0,textureSize.y*next_y,textureSize.x,textureSize.y));
    if(next_y==9){
        next_y=0;}
    else
        next_y++;
}







Pygmy::Pygmy( int seed): Enemy("Enemies/pygmy_sheet.png",seed){
    textureSize= enemy_texture->getSize();
    textureSize.x/=3.85;
    textureSize.y /=1;
    enemy_sprite= new sf::RectangleShape(sf::Vector2f(90.0f,120.0f));
    enemy_sprite->setTexture(enemy_texture);
    enemy_sprite->setTextureRect(sf::IntRect(textureSize.x*0,textureSize.y*0,textureSize.x,textureSize.y));
    sprite_dimensions=enemy_sprite->getGlobalBounds();
    enemy_sprite->setPosition(x_position,y_position);//x_position,y_position);
}
Pygmy::~Pygmy(){}
void Pygmy::damage(){}
void Pygmy::animation(){
    enemy_sprite->setTextureRect(sf::IntRect(textureSize.x*next_x,textureSize.y*0,textureSize.x,textureSize.y));
    if(next_x>=3){
        next_x=0;}
    else
        next_x++;

}





Cactus:: Cactus(int seed):Enemy("Enemies/Cactus.png",seed){
    enemy_sprite= new sf::RectangleShape(sf::Vector2f(110.0f,145.0f));
    sprite_dimensions=enemy_sprite->getGlobalBounds();
    enemy_sprite->setPosition(x_position,y_position);//x_position,y_position);
    enemy_sprite->setTexture(enemy_texture);
    }







Peabody::Peabody(int seed): Enemy("Enemies/Peabody_sheet.png",seed){
    textureSize= enemy_texture->getSize();
    textureSize.x/=12;
    textureSize.y /=4;
    enemy_sprite= new sf::RectangleShape(sf::Vector2f(115.0f,140.0f));
    enemy_sprite->setTexture(enemy_texture);
    enemy_sprite->setTextureRect(sf::IntRect(textureSize.x*0,textureSize.y*0,textureSize.x,textureSize.y));
    sprite_dimensions=enemy_sprite->getGlobalBounds();
    enemy_sprite->setPosition(x_position,y_position);//x_position,y_position);

}
void Peabody::animation(){
    enemy_sprite->setTextureRect(sf::IntRect(textureSize.x*next_x,textureSize.y*next_y,textureSize.x,textureSize.y));
    if(next_x==11){
        next_x=0;
        next_y++;}
    else
        next_x++;
    if (next_y>2){
        next_y=0;}

}



Rock::Rock( int seed): Enemy("Enemies/rock2.png",seed){
    enemy_sprite= new sf::RectangleShape(sf::Vector2f(120.0f,100.0f));
    enemy_sprite->setTexture(enemy_texture);
    sprite_dimensions=enemy_sprite->getGlobalBounds();
    enemy_sprite->setPosition(x_position,y_position);//x_position,y_position);
}



void load_enemies(std::vector<Obstacle::Enemy*> &Enemies){
    Obstacle::Enemy *enemy;
    switch (Enemies.size()){
        case 0:
            enemy= new Obstacle::CactusMan(10);
            Enemies.push_back(enemy);
            break;
        case 1:
            enemy= new Obstacle::Peabody(4);
            Enemies.push_back(enemy);
            break;
        case 3:
            enemy=new Obstacle::Rock(2);
            Enemies.push_back(enemy);
            break;
        case 2:
            enemy= new Obstacle::Cactus(30);
            Enemies.push_back(enemy);
            break;
       /*
        case 4:
            enemy= new Obstacle::Pygmy(50);
            Enemies.push_back(enemy);
            break;}}
*/}}





}
