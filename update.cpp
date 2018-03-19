
#include "Update.h"
#include <string>
#include <cassert>
#include <iostream>

namespace display_update{

    void initiate_window(sf::RenderWindow* window){
        window->create(sf::VideoMode(windowWidth,windowHeigth),"Race Game Remastered Edition.", sf::Style::Default);
        sf::Vector2i position(590,240);
        window->setPosition(position);
        window->setVerticalSyncEnabled(true);
        window->setFramerateLimit(60);
    }
    void  draw_message(std::string words, std::string font_type, int Size, sf::Color color, sf::RenderWindow* window,int width, int height){
        sf::Font font;
        font.loadFromFile("Fonts/"+font_type);
        sf::Text message;
        message.setFont(font);
        message.setString(words);
        message.setCharacterSize(Size);
        message.setColor(color);
        sf::FloatRect message_position= message.getGlobalBounds();//Not position but message_size
        message.setOrigin(-1*(width/2)+message_position.width/2, -1*(height/2));
        window->draw(message);
        //window->display();

    }
    void window_update(sf::RenderWindow* window, sprites::Background* background, sprites::Car* car, std::vector<Obstacle::Enemy*> &enemy,std::string fps){
        int temp=0;
        window->clear(sf::Color::White);
        background->draw_sprite(window);
        car->draw_sprite(window);
        for (unsigned int i=0; i<enemy.size(); i++){
            enemy[i]->displace(5);
            enemy[i]->draw_sprite(window);
            temp+=enemy[i]->get_score();
        }
        std::ostringstream ss;
        ss<<temp;
        std::string score_count(ss.str());
        draw_message("FPS:"+fps,"fps.otf",18,sf::Color::White,window,70,0);
        draw_message("Score: "+score_count,"fps.otf",20,sf::Color::White,window,windowWidth,0);
        window->display();
        }

}

