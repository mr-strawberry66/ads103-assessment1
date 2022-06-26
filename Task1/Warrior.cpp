#include <string>
#include <stdexcept>
#include "Warrior.hpp"

/** Default constructor for a Warrior object.
 *
 * Sets the name, hit points, strength,
 * defence, and rage points to the
 * default values.
 */
Warrior::Warrior()
{
    this->setName("Birest Shadowbattle");
    this->setHitPoints(100);
    this->setStrength(10);
    this->setDefence(8);
    this->setRagePoints(0);
}

/** Constructor for a Warrior object.
 *
 * Args:
 *   std::string name:
 *     The name you want to give your warrior.
 *
 *   int hitPoints:
 *     How much health to give your warrior
 *     (max value of 100).
 *
 *   int strength:
 *     The base amount of damage a warrior can do
 *     in hitpoints.
 *
 *   int defence:
 *     How much damage a warrior can mitigate
 *     in hitpoints.
 *
 *   int ragePoints:
 *     How many rage points the warrior starts
 *     with (min value of 0).
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

/** Return the current number of rage points the warrior has. */
int Warrior::getRagePoints()
{
    return this->ragePoints;
}

/** Set the number of rage points.
 *
 * Args:
 *   int ragePoints:
 *     The number of rage points to set the warrior to.
 *
 * Throws std::invalid_argument:
 *   If ragePoints is less than 0.
 */
void Warrior::setRagePoints(int ragePoints)
{
    if (ragePoints < 0)
        throw std::invalid_argument(
            "Warrior's rage points must be greater than 0");

    this->ragePoints = ragePoints;
}

/** Return the amount of damage the warrior does this turn.
 *
 * If the warrior has enough rage, it will do a heavy attack.
 * Otherwise, it will generate 5 rage, and do a basic attack.
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
