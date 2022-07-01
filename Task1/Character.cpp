#include <string>
#include <stdexcept>
#include "Character.hpp"

/** @brief Default constructor for a new Character::Character object. */
Character::Character()
{
    this->setName("Redel Dualbinder");
    this->setHitPoints(80);
    this->setStrength(5);
    this->setDefence(5);
}

/**
 * @brief Construct a new Character::Character object
 *
 * @param name The name to give your character.
 * @param hitPoints How much health your character should have.
 * @param strength How much damage your character can do.
 * @param defence The amount of damage your character can mitigate per turn.
 */
Character::Character(std::string name, int hitPoints, int strength, int defence)
{
    this->setName(name);
    this->setHitPoints(hitPoints);
    this->setStrength(strength);
    this->setDefence(defence);
}

/**
 * @brief Get the character's name.
 *
 * @return std::string The character's name.
 */
std::string Character::getName()
{
    return this->name;
}

/**
 * @brief Set the name of a character.
 *
 * @param name The name to give your character.
 * @throws std::invalid_argument if the name is empty.
 */
void Character::setName(std::string name)
{
    if (name.empty())
        throw std::invalid_argument("Character name must not be empty.");
    this->name = name;
}

/**
 * @brief Get the character's current health.
 *
 * @return int The character's health in hit points.
 */
int Character::getHitPoints()
{
    return this->hitPoints;
}

/**
 * @brief Set the character's health.
 *
 * @param hitPoints The amount of health to give your character in hitPoints.
 */
void Character::setHitPoints(int hitPoints = 100)
{
    if (hitPoints > 100)
        throw std::invalid_argument(
            "Character hit points must not be greater than 100.");

    this->hitPoints = hitPoints;
}

/**
 * @brief Get the character's strength.
 *
 * @return int How much base damage the character can do.
 */
int Character::getStrength()
{
    return this->strength;
}

/**
 * @brief Set the character's strength.
 *
 * @param strength How much base damage the character can do.
 * @throws std::invalid_argument if the strength is less than 0 or greater than 10.
 */
void Character::setStrength(int strength)
{
    if (strength < 1)
        throw std::invalid_argument(
            "Character strength must be greater than 0.");

    if (strength > 10)
        throw std::invalid_argument(
            "Character strength must not be greater than 10.");

    this->strength = strength;
}

/**
 * @brief Get the character's defence.
 *
 * @return int How much damage the character can mitigate per turn in hit points.
 */
int Character::getDefence()
{
    return this->defence;
}

/**
 * @brief Set the character's defence.
 *
 * @param defence How much damage the character can mitigate per turn in hit points.
 * @throws std::invalid_argument if the defence is less than 0 or greater than 10.
 */
void Character::setDefence(int defence)
{
    if (defence < 1)
        throw std::invalid_argument(
            "Character defence must be greater than 0.");

    if (defence > 10)
        throw std::invalid_argument(
            "Character defence must not be greater than 10.");

    this->defence = defence;
}

/**
 * @brief Attack another character.
 *
 * @return int The amount of damage the character did.
 */
int Character::doAction()
{
    return this->strength;
}

/**
 * @brief Take damage from an enemy attack.
 *
 * @param damage The amount of damage to take in hitpoints.
 */
void Character::takeDamage(int damage)
{
    int totalDamage = damage - this->getDefence();

    if (totalDamage < 0)
        totalDamage = 0;

    int hitPoints = (this->getHitPoints() - totalDamage);

    this->setHitPoints(hitPoints);
}

/**
 * @brief See if the character is still a live.
 *
 * @return bool Whether the character's hit points are a positive integer.
 */
bool Character::isAlive()
{
    return (this->hitPoints > 0);
}
