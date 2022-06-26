#include <string>
#include <stdexcept>
#include "Mage.hpp"

/** Default constructor for a Mage object.
 *
 * Sets the name, hit points, strength,
 * defence, mana points, and fireball damage
 * to the default values.
 */
Mage::Mage()
{
    this->setName("Drarnamm Hollowbreath");
    this->setHitPoints(50);
    this->setStrength(5);
    this->setDefence(3);
    this->setManaPoints(50);
    this->setFireballDamage(25);
}

/** Constructor for a Mage object.
 *
 * Args:
 *   std::string name:
 *     The name you want to give your mage.
 *
 *   int hitPoints:
 *     How much health to give your mage (max value of 100).
 *
 *   int strength:
 *     How strong your mage should be (max value of 10).
 *
 *   int defence:
 *     How well you wish your mage to be able to
 *     defend against attacks (max value of 10).
 *
 *   int manaPoints:
 *     How much mana to give your mage (min value of 0).
 *
 *   int fireballDamage:
 *     How much damage to give your fireball
 *     (min value of 0, max of 30).
 */
Mage::Mage(std::string name, int hitPoints, int strength,
           int defence, int manaPoints, int fireballDamage)
{
    this->setName(name);
    this->setHitPoints(hitPoints);
    this->setStrength(strength);
    this->setDefence(defence);
    this->setManaPoints(manaPoints);
    this->setFireballDamage(fireballDamage);
}

/** Return the amount of mana points the mage has. */
int Mage::getManaPoints()
{
    return this->manaPoints;
}

/** Set the amount of mana points the mage has.
 *
 * Args:
 *   int manaPoints:
 *     How much mana the mage should start with.
 *
 * Throws std::invalid_argument:
 *   If manaPoints is less than 0.
 */
void Mage::setManaPoints(int manaPoints)
{
    if (manaPoints < 0)
        throw std::invalid_argument(
            "Mana Points must be greater than 0.");

    this->manaPoints = manaPoints;
}

/** Return the amount of damage the fireball does. */
int Mage::getFireballDamage()
{
    return this->fireballDamage;
}

/** Set the amount of damage the fireball does.
 *
 * Args:
 *   int fireballDamage:
 *     The amount of damage the fireball attack
 *     should deal in hitpoints.
 *
 * Throws std::invalid_argument:
 *   If fireballDamage is less than 0 or greater than 30.
 */
void Mage::setFireballDamage(int fireballDamage)
{
    if (fireballDamage < 0)
        throw std::invalid_argument(
            "Fireball Damage must be greater than 0.");

    if (fireballDamage > 30)
        throw std::invalid_argument(
            "Fireball Damage must not be greater than 30.");

    this->fireballDamage = fireballDamage;
}

/** Return the amount of damage the mage does this turn.
 *
 * If the mage has enough mana, they will use a fireball
 * attack. Otherwise, they will use a basic attack, and
 * regenerate 3 mana.
 */
int Mage::doAction()
{
    if (this->getManaPoints() > 10)
    {
        this->setManaPoints(this->getManaPoints() - 10);
        return this->fireballDamage;
    }
    this->setManaPoints(this->getManaPoints() + 3);
    return this->getStrength();
}
