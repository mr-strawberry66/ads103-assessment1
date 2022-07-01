#include "Game.hpp"

/**
 * @brief Return how many hit points a character has.
 *
 * @param character The character to get the hit points of.
 * @return std::string A formatted string containing the character's name and hit points.
 */
std::string Game::hitPointsStatus(Character character)
{
    if (character.getHitPoints() < 0)
    {
        return character.getName() + " has died!\n";
    }

    return character.getName() + " has " + std::to_string(character.getHitPoints()) + " hit points remaining!\n";
}

/**
 * @brief Return how much damage a character has done this turn.
 *
 * @param character The character to calculate the damage dealt from.
 * @param damage The amount of damage the character has done.
 * @return std::string A formatted string containing the character's name and damage dealt.
 */
std::string Game::damageDealtStatus(Character character, const int damage)
{
    return character.getName() + " deals " + std::to_string(damage) + " hit points!\n";
}

/**
 * @brief Return how much healing a character has done this turn.
 *
 * @param paladin The paladin to calculate the healing done from.
 * @return std::string A formatted string containing the paladin's name and healing done.
 */
std::string Game::healingDoneStatus(Paladin paladin)
{
    return paladin.getName() + " heals for " + std::to_string(paladin.getHealAmount()) + " hit points!\n";
}

/**
 * @brief Run a fight between a Paladin and a Mage.
 *
 * @param paladin A paladin to engage in the fight.
 * @param mage A mage to engage in the fight.
 */
void Game::gameLoop(Paladin &paladin, Mage &mage)
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
