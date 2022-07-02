#include "Paladin.hpp"

/** @brief Default constructor for a new Paladin::Paladin object. */
Paladin::Paladin()
{
    this->setName("Arno'gech Strongsword");
    this->setHitPoints(70);
    this->setStrength(8);
    this->setDefence(8);
    this->setRagePoints(0);
    this->setHealAmount(10);
}

/**
 * @brief Construct a new Paladin::Paladin object.
 *
 * @param name The name to give your paladin.
 * @param hitPoints How much health your paladin should have.
 * @param strength How much damage your paladin can do.
 * @param defence The amount of damage your paladin can mitigate per turn.
 * @param ragePoints How much rage your paladin starts with.
 * @param healAmount How much health the heal spell grants.
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

/**
 * @brief Get how much health the paladin can heal for.
 *
 * @return int The amount of health the paladin can heal for.
 */
int Paladin::getHealAmount()
{
    return this->healAmount;
}

/**
 * @brief Set how much health the paladin can heal for.
 *
 * @param healAmount The amount of health the paladin can heal for.
 * @throws std::invalid_argument if the heal amount is negative or greater than 10.
 */
void Paladin::setHealAmount(int healAmount)
{
    if (healAmount < 0)
        throw std::invalid_argument(
            "Heal Amount must be at least 0.");

    if (healAmount > 10)
        throw std::invalid_argument(
            "Heal amount must not be greater than 10.");

    this->healAmount = healAmount;
}

/**
 * @brief Attack another character.
 *
 * If the paladin's health is less than 20hp
 * and the paladin has more than 15 rage, the
 * paladin will heal. This will not deal any
 * damage to the target.
 *
 * If the paladin has more than 20hp and more
 * than 15 rage, the paladin will deal a heavy
 * attack.
 *
 * Otherwise the paladin will generate 5 rage
 * and deal a light attack.
 *
 * @return int The amount of damage the paladin did.
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
