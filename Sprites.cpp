#include "Sprites.h"
#include <string>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>


namespace sprites{



Car::Car(std::string model){
    car_sprite=new sf::RectangleShape(sf::Vector2f(124.0f,201.0f));
    car_texture= new sf::Texture();
    if (!car_texture->loadFromFile("Car Images/"+ model)){
        assert(!car_texture->loadFromFile(model));}
    car_texture->setSmooth(true);
    car_sprite->setTexture(car_texture);
    sprite_dimensions=car_sprite->getGlobalBounds();// Tells the dimensions of the image.
    startLocation();
    x_position=originX;
    y_position=originY;
    }
void Car::startLocation(){
    originX=((windowWidth/2))-Width()/2;//subtracted Width instead of +
    originY=((windowHeigth/2))+Height()/2;//removed -1*
    car_sprite->setPosition(originX,originY);

}
Car::~Car(){
    delete car_sprite;
    delete car_texture;
}
void Car::reset(){

    car_sprite->setPosition(originX,originY);
    sf::Vector2f position = car_sprite->getPosition();// contains position.x and position.y
    x_position=position.x;
    y_position=position.y;}

const int Car:: get_x(){return x_position;}
const int Car:: get_y(){return y_position;}

void Car::set_position(int x_change){
    x_position+=x_change;
    //std::cout<<"("<<x_position<<","<<y_position<<")"<<std::endl;
    car_sprite->setPosition(x_position,y_position);
}
void Car::draw_sprite(sf::RenderWindow* window){
    window->draw(*car_sprite);}

bool Car::outOfBounds(){

  if (x_position <=0 || x_position>= windowWidth-Width())

        return true;
    else
        return false;
    }
bool Car::collision(Obstacle::Enemy* enemy){//When possible update to pixel perfect collision
    if (car_sprite->getGlobalBounds().intersects(enemy->enemy_sprite->getGlobalBounds())){
        //std::cout<<"COLLISION"<<std::endl;
        return true;
    }
    else
        return false;
}







Background::Background(std::string level){
    background_sprite= new sf::Sprite();
    background_texture= new sf::Texture();
    if (!background_texture->loadFromFile(level)){
        assert (!background_texture->loadFromFile(level));
    }
    background_texture->setSmooth(true);
    background_sprite->setTexture(*background_texture);
}
Background::~Background(){
    delete background_sprite;
    delete background_texture;
}
void Background:: draw_sprite(sf::RenderWindow* window){
    window->draw(*background_sprite);
}




}

