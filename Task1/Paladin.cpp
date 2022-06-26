#include <string>
#include <stdexcept>
#include "Paladin.hpp"

/** Default constructor for a Paladin object.
 *
 * Sets the name, hit points, strength,
 * defence, rage points, and heal amount
 * to the default values.
 */
Paladin::Paladin()
{
    this->setName("Arno'gech Strongsword");
    this->setHitPoints(70);
    this->setStrength(8);
    this->setDefence(8);
    this->setRagePoints(0);
    this->setHealAmount(10);
}

/** Constructor for a Paladin object.
 *
 * Args:
 *   std::string name:
 *     The name you want to give your paladin.
 *
 *   int hitPoints:
 *     How much health to give your paladin (max value of 100).
 *
 *   int strength:
 *     How strong your paladin should be (max value of 10).
 *
 *   int defence:
 *     How well you wish your paladin to be able to
 *     defend against attacks (max value of 10).
 *
 *  int ragePoints:
 *    How much rage points the paladin should start with (min value of 0).
 *
 *   int healAmount:
 *     How much health to give the paladin when healing (min value of 0, max of 10).
 */
Paladin::Paladin(std::string name, int hitPoints, int strength,
                 int defence, int ragePoints, int healAmount)
{
    this->setName(name);
    this->setHitPoints(hitPoints);
    this->setStrength(strength);
    this->setDefence(defence);
    this->setRagePoints(ragePoints);
    this->setHealAmount(healAmount);
}

/** Return how much the paladin can heal for. */
int Paladin::getHealAmount()
{
    return this->healAmount;
}

/** Set how much the paladin can heal for.
 *
 * Args:
 *   int healAmount:
 *     How much health to give the paladin when healing (min value of 0, max of 10).
 *
 * Throws std::invalid_argument:
 *   If healAmount is less than 0 or greater
 *   than 10.
 */
void Paladin::setHealAmount(int healAmount)
{
    if (healAmount < 0)
        throw std::invalid_argument(
            "Heal Amount must be greater than 0.");

    if (healAmount > 10)
        throw std::invalid_argument(
            "Heal amount must not be greater than 10.");

    this->healAmount = healAmount;
}

/** Return the amount of damage a paladin can do this turn.
 *
 * If the paladin has 20 or less hitpoints
 * and has more than 15 rage points, it will
 * heal themselves.
 *
 * If they have more than 20 health, and 15
 * rage points, it will do a heavy attack.
 *
 * Otherwise, it will do a basic attack.
 */
int Paladin::doAction()
{
    if (this->getHitPoints() <= 20 && this->getRagePoints() > 15)
    {
        this->setHitPoints(this->getHealAmount() + this->getHitPoints());
        this->setRagePoints(this->getRagePoints() - 15);
        return 0;
    }

    if (this->getRagePoints() > 15)
    {
        this->setRagePoints(this->getRagePoints() - 15);
        return this->getStrength() * 2;
    }

    this->setRagePoints(this->getRagePoints() + 5);
    return this->getStrength();
}
