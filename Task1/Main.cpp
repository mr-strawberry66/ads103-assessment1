#include <iostream>
#include <string>
#include "Mage.hpp"
#include "Paladin.hpp"
#include "Game.hpp"

/** Entry point.
 *
 * Pit a Mage against a Palaidn and see who the victor is.
 */
int main()
{
    Paladin paladin = Paladin("Alvin Abram", 60, 8, 5, 0, 10);
    Mage mage = Mage("Delancy Gresham", 50, 5, 2, 57, 15);

    Game::gameLoop(paladin, mage);

    if (paladin.isAlive())
        std::cout << "Paladin " << paladin.getName() << " wins!" << std::endl;

    else
        std::cout << "Mage " << mage.getName() << " wins!" << std::endl;
}
