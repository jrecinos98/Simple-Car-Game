#include <iostream>
#include "../includes/Event.h"

namespace game_event{

void event_handle(sf::Event& event, sf::RenderWindow* window, sprites::Car* sprite, bool& game_paused, bool &game_over){
        switch (event.type){
                    case sf::Event::Closed:
                        window->close();
                        break;

                    case sf::Event::MouseButtonPressed:
                        if(sf::Mouse::isButtonPressed(sf::Mouse:: Left)){
                            sf::Vector2i position= sf::Mouse::getPosition(*window);
                          //std::cout<<"("<<position.x<<","<<position.y<<")"<<std::endl;
                            break;
                       }
                    case::sf::Event::Resized:
                       // std::cout<<"New window Width: "<<event.size.width<<" New Window Height: "<<event.size.height<<std::endl;
                        break;
                    case::sf::Event::TextEntered:
                        if (event.text.unicode<128)
                           // printf("%c\n",event.text.unicode);//%c = character.
                            break;
                    case sf::Event::KeyPressed:
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && game_paused){
                                game_paused= false;
                                break;
                            }
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && game_over){
                                game_over=false;
                                break;}

                        if (!game_paused && !game_over){

                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                                display_update::draw_message("GAME PAUSED", "ka1.ttf",50,sf::Color(119,136,144), window);
                                window->display();
                                game_paused=true;
                                break;
                            }
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                                window->close();
                                break;}
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                                int x_change=SPEED*-1;
                                sprite->set_position(x_change);
                                }
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                                int x_change=SPEED;
                                sprite->set_position(x_change);
                                break;
                            }
                        }
                    case sf::Event::KeyReleased:
                        if(event.key.code == sf::Keyboard::A){
                            //std::cout<<"YES"<<std::endl;
                        }

                }
    }
}
