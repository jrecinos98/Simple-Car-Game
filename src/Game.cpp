#include <string>
#include <cassert>
#include <iostream>
#include "Game.h"



namespace car_game{

    void game_loop(){
        //Window
        sf::RenderWindow* window= new sf::RenderWindow();
        //Clocks
        game_clock::Clock* gameClock= new game_clock:: Clock();
        game_clock::Clock* updateClock= new game_clock::Clock();
        //Sprite objects
        sprites::Car* car=new sprites::Car("LightBlueCar.png");//generates car object;
        sprites::Background* background= new sprites::Background("res/Background.png");//generates background object

        std::vector<Obstacle::Enemy*> Enemies;
        Obstacle::load_enemies(Enemies); //generates enemy objects and stores them in a vector.

        display_update::initiate_window(window);//Creates the initial window.

        std::string fps="60";
        int frames=0;
        float starttime = updateClock->elapsed_time("seconds");

        bool game_paused= false;
        bool end_game=false;
        while(window->isOpen()){
            sf::Event event;

            while(window->pollEvent(event)) // wait event;
                {
               game_event::event_handle(event,window,car,game_paused, end_game);//Handles all key events and sprite movement.
               }

            if (gameClock->elapsed_time("microseconds")>=frame && !game_paused && !end_game){
                if (gameClock->elapsed_time("seconds") - starttime > 0.50 && frames > 10)///Only updates fps every .5 seconds. This way it is uses less resources.
                   {
                        std::ostringstream ss;
                        ss<<std::setprecision(3)<<get_fps(frames,starttime,gameClock);
                        std::string temp(ss.str());
                        fps=temp;
                    }
                 if (updateClock->elapsed_time("seconds")>= 25){
                    Obstacle::load_enemies(Enemies);
                    updateClock->reset();
                    }
                display_update::window_update(window,background,car,Enemies,fps);//updates window at ~60fps.
                frames++;
                //updateClock->reset(); //It uses significantly more cpu power.
            }
            if ((car->outOfBounds() || crash(Enemies,car)) && !end_game){ // !end_game ensures that the message wont be displayed more than once and glitch.
                car_game::game_over(end_game,window,car,Enemies);
                gameClock->reset();
                updateClock->reset();
                }

            }

    }



///Improve car physics (smoothness and acceleration). Add some music to add appeal. Health bar for car.
    void game_over(bool &end_game, sf::RenderWindow *window, sprites::Car *car, std::vector<Obstacle::Enemy*> &Enemies){
         display_update::draw_message("YOU CRASHED","Vintage.ttf", 50,sf::Color::Red,window);
         window->display();
         end_game=true;
         car->reset();
         Enemies[0]->reset();
         for (unsigned int i=1; i<Enemies.size(); i++){
               Enemies[i]->reset();
               Enemies.pop_back();
        }

    }
    float get_fps(int &frames, float &starttime, game_clock::Clock *updateClock){
        float fps = (double) frames / (updateClock->elapsed_time("seconds") - starttime);
        starttime = updateClock->elapsed_time("seconds");
        frames = 0;
        return fps;



    }
    bool crash(std::vector<Obstacle::Enemy*> &Enemies, sprites::Car *car){
        for (unsigned int i=0; i<Enemies.size(); i++){
                if (car->collision(Enemies[i])){
                    return true;
                }
    }
    return false;

    }


}
