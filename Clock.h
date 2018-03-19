#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <cassert>
#include <SFML/Graphics.hpp>

namespace game_clock{
class Clock{

    public:
        //Clock();
        float reset(std::string unit="none");
        float elapsed_time(std::string unit);

    private:
        sf::Clock clock;
        sf::Time elapsedTime;
};

}
#endif // CLOCK_H
