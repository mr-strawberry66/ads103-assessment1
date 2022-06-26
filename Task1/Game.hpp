#ifndef GAME
#define GAME

#include <iostream>
#include <string>
#include "Character.hpp"
#include "Paladin.hpp"
#include "Mage.hpp"

/* Namespace to keep game related functions out of the global namespace. */
namespace Game
{
    /* Return how many hitpoints a Character has remaining.
     *
     * Args:
     *   Character character:
     *     A Character or subclass of Character
     *     to pull the information from.
     *
     * Returns std::string:
     *   A formatted string including the
     *   Character's name and remaining hitpoints
     *   or, if the character has less than 0
     *   hitpoints, a message informing the death
     *   of the Character.
     */
    std::string hitPointsStatus(Character character)
    {
        if (character.getHitPoints() < 0)
        {
            return character.getName() + " has died!\n";
        }

        return character.getName() + " has " + std::to_string(character.getHitPoints()) + " hit points remaining!\n";
    }

    /* Return how much damage a Character has done.
     *
     * Args:
     *   Character character:
     *     A Character or subclass of Character
     *     to pull the information from.
     *
     *   int damage:
     *     The amount of damage the Character dealt.
     *
     * Returns std::string:
     *   A formatted string including the Character's
     *   name, and how much damage they dealt.
     */
    std::string damageDealtStatus(Character character, const int damage)
    {
        return character.getName() + " deals " + std::to_string(damage) + " hit points!\n";
    }

    /* Return how much healing a Paladin has done.
     *
     * Args:
     *   Paladin paladin:
     *     The Paladin object to pull information
     *     from.
     *
     * Returns std::string:
     *   A formatted string with the Paladin's name
     *   and how much healing they have done this turn.
     */
    std::string healingDoneStatus(Paladin paladin)
    {
        return paladin.getName() + " heals for " + std::to_string(paladin.getHealAmount()) + " hit points!\n";
    }

    /* Run the fight between the Paladin and Mage.
     *
     * Args:
     *   Paladin& paladin:
     *     A Paladin object to battle against the mage.
     *
     *   Mage& mage:
     *     A Mage object to battle against the paladin.
     */
    void gameLoop(Paladin &paladin, Mage &mage)
    {
        while (paladin.isAlive() && mage.isAlive())
        {
            int paladinDamage = paladin.doAction();
            int mageDamage = mage.doAction();

            mage.takeDamage(paladinDamage);
            if (paladinDamage == 0)
                std::cout << Game::healingDoneStatus(paladin);
            else
                std::cout << Game::damageDealtStatus(paladin, paladinDamage);

            paladin.takeDamage(mageDamage);
            std::cout << Game::damageDealtStatus(mage, mageDamage) << "\n";

            std::cout << Game::hitPointsStatus(paladin);
            std::cout << Game::hitPointsStatus(mage) << "\n\n";
        }
    }
}

#endif
