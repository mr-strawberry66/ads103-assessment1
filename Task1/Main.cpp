#include <iostream>
#include <string>
#include <stdexcept>
#include "Mage.hpp"
#include "Paladin.hpp"
#include "Game.hpp"

/**
 * @brief Begin a fight between a mage and a paladin.
 *
 * @return int The exit code.
 */
int main()
{
    try
    {
        Paladin paladin = Paladin("Alvin Abram", 60, 8, 5, 0, 10);
        Mage mage = Mage("Delancy Gresham", 50, 5, 2, 57, 15);

        Game::gameLoop(paladin, mage);

        if (paladin.isAlive())
            std::cout << "Paladin " << paladin.getName() << " wins!" << std::endl;

        else
            std::cout << "Mage " << mage.getName() << " wins!" << std::endl;
    }

    catch (const std::invalid_argument err)
    {
        std::cout << "Error! " << err.what() << std::endl;
        return 1;
    }

    return 0;
}
