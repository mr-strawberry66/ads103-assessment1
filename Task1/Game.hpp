#ifndef GAME
#define GAME

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Paladin.hpp"
#include "Mage.hpp"

/** @brief Namespace to contain functions relating to the game. */
namespace Game
{
    std::string hitPointsStatus(Character character);

    std::string damageDealtStatus(Character character, const int damage);

    std::string healingDoneStatus(Paladin paladin);

    void gameLoop(Paladin &paladin, Mage &mage);
}

#endif
