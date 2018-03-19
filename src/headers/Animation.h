#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Global.h"
#include "Obstacles.h"

namespace enemy_animation{
class Animation{
public:
    Animation(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);

    void update(int row,float deltaTime);
private:

public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    float switchTime;


};

}
#endif // ANIMATION_H
