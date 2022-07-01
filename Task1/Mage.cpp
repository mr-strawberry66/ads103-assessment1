#include <string>
#include <stdexcept>
#include "Mage.hpp"

/** @brief Default constructor for a new Mage::Mage object. */
Mage::Mage()
{
    this->setName("Drarnamm Hollowbreath");
    this->setHitPoints(50);
    this->setStrength(5);
    this->setDefence(3);
    this->setManaPoints(50);
    this->setFireballDamage(25);
}

/**
 * @brief Construct a new Mage::Mage object.
 *
 * @param name The name to give your mage.
 * @param hitPoints How much health your mage should have.
 * @param strength How much damage your mage can do.
 * @param defence The amount of damage your mage can mitigate per turn.
 * @param manaPoints How much mana your mage starts with.
 * @param fireballDamage How much damage the fireball spell does.
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

/**
 * @brief Return how much mana the mage currently has.
 *
 * @return int The mage's current mana.
 */
int Mage::getManaPoints()
{
    return this->manaPoints;
}

/**
 * @brief Set the mage's current mana.
 *
 * @param manaPoints The amount of mana the mage should have.
 * @throws std::invalid_argument if the mana is negative.
 */
void Mage::setManaPoints(int manaPoints)
{
    if (manaPoints < 0)
        throw std::invalid_argument(
            "Mana Points must be greater than 0.");

    this->manaPoints = manaPoints;
}

/**
 * @brief Get how much damage the fireball spell deals.
 *
 * @return int The amount of damage the fireball spell deals.
 */
int Mage::getFireballDamage()
{
    return this->fireballDamage;
}

/**
 * @brief Set how much damage the fireball spell deals.
 *
 * @param fireballDamage The amount of damage the fireball spell should do.
 * @throws std::invalid_argument if the damage is negative or greater than 30.
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

/**
 * @brief Attack another character.
 *
 * @return int How much damage the mage deals to the other character.
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
