#include "Game/Character.h"
#include "iostream"
#include "utility"
#include "chrono"
#include "thread"
#include "Utils/Math.h"

int main()
{
    #ifdef SKIP_GAME
        std::cout << "Game is not available" << std::endl;
        return 0;
    #endif
    Character hero1{"Goida1"};
    Character hero2{"Goida2"};
    Character* attacker = &hero1;
    Character* defender = &hero2;
    if (randInt(0, 1) == 1) std::swap(attacker, defender);

    while (true)
    {
        attacker->attack(*defender);
        if (defender->dead())
        {
            std::cout << std::endl << " GAME OVER " << std::endl << attacker->name() << " - win! " << defender->name() << " - loser! ";
            break;
        }
        std::swap(attacker, defender);
        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cin.get();
    return 0;
}