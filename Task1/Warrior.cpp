#include <string>
#include <stdexcept>
#include "Warrior.hpp"

/** @brief Default constructor a new Warrior::Warrior object. */
Warrior::Warrior()
{
    this->setName("Birest Shadowbattle");
    this->setHitPoints(100);
    this->setStrength(10);
    this->setDefence(8);
    this->setRagePoints(0);
}

/**
 * @brief Construct a new Warrior:: Warrior object.
 *
 * @param name The name of the warrior.
 * @param hitPoints How much health the warrior has.
 * @param strength How much base damage the warrior can do.
 * @param defence How much damage the warrior can mitigate per turn.
 * @param ragePoints How much rage the warrior has stored.
 */
Warrior::Warrior(std::string name, int hitPoints,
                 int strength, int defence, int ragePoints)
{
    this->setName(name);
    this->setHitPoints(hitPoints);
    this->setStrength(strength);
    this->setDefence(defence);
    this->setRagePoints(ragePoints);
}

/**
 * @brief Get the rage points of the warrior.
 *
 * @return The rage points of the warrior.
 */
int Warrior::getRagePoints()
{
    return this->ragePoints;
}

/**
 * @brief Set how many rage points the warrior has.
 *
 * @param ragePoints The number of rage points the warrior has.
 * @throw std::invalid_argument if ragePoints is less than 0.
 */
void Warrior::setRagePoints(int ragePoints)
{
    if (ragePoints < 0)
        throw std::invalid_argument(
            "Warrior's rage points must be greater than 0");

    this->ragePoints = ragePoints;
}

/**
 * @brief Return the amount of damage dealt by the Warrior.
 *
 * @return int How much damage the warrior can do.
 */
int Warrior::doAction()
{
    if (this->getRagePoints() > 15)
    {
        this->setRagePoints(this->getRagePoints() - 15);
        return (this->getStrength() * 3);
    }

    this->setRagePoints(this->getRagePoints() + 5);
    return this->getStrength();
}
