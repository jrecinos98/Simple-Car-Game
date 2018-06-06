#ifndef EVENT_H
#define EVENT_H
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Sprites.h"
#include "Update.h"

namespace game_event{
    void event_handle(sf::Event& event, sf::RenderWindow* window, sprites::Car* sprite, bool& game_paused, bool &game_over);

}
#endif // EVENT_H
