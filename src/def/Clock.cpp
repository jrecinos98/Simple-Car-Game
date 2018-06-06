#include "../includes/Clock.h"
#include <cassert>

namespace game_clock{


   float Clock::elapsed_time(std::string unit){
       elapsedTime= clock.getElapsedTime();
       if (unit== "seconds"){
            return elapsedTime.asSeconds();
       }
       if (unit== "microseconds"){
            return elapsedTime.asMicroseconds();
       }
       if (unit == "milliseconds"){
            return elapsedTime.asMilliseconds();
       }

   }

   float Clock::reset(std::string unit){
       if (unit=="none")
        clock.restart();
       if (unit=="seconds")
        return clock.restart().asSeconds();
       if (unit== "microseconds")
        return clock.restart().asMicroseconds();
       else
        return clock.restart().asMilliseconds();
   }

}
