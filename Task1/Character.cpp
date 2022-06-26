#include <string>
#include <stdexcept>
#include "Character.hpp"

/** Default constructor for a Character object.
 *
 * Sets the name, hit points, strength and defence to default values.
 */
Character::Character()
{
    this->setName("Redel Dualbinder");
    this->setHitPoints(80);
    this->setStrength(5);
    this->setDefence(5);
}

/** Constructor for a Character object.
 *
 * Args:
 *   std::string name:
 *     The name you want to give your character.
 *
 *   int hitPoints:
 *     How much health to give your character (max value of 100).
 *
 *   int strength:
 *     How strong your character should be (max value of 10).
 *
 *   int defence:
 *     How well you wish your character to be able to defend
 *     against attacks (max value of 10).
 */
Character::Character(std::string name, int hitPoints, int strength, int defence)
{
    this->setName(name);
    this->setHitPoints(hitPoints);
    this->setStrength(strength);
    this->setDefence(defence);
}

/** Return the name of the character. */
std::string Character::getName()
{
    return this->name;
}

/** Set the name of the Character.
 *
 * Args:
 *   std::string name:
 *     The name you want to give your character.
 *
 * Throws: std::invalid_argument:
 *   If name is an empty string.
 */
void Character::setName(std::string name)
{
    if (name.empty())
        throw std::invalid_argument("Character name must not be empty.");
    this->name = name;
}

/** Return the hit points of the character. */
int Character::getHitPoints()
{
    return this->hitPoints;
}

/** Set the Character's current hit points.
 *
 * Args:
 *   int hitPoints:
 *	  The amount of health to give your Character.
 *     Must be less than 100. If negative, indicates
 *     that the Character is dead.
 *
 * Throws std::invalid_argument:
 *   If provided hit points are too high.
 */
void Character::setHitPoints(int hitPoints = 100)
{
    if (hitPoints > 100)
        throw std::invalid_argument(
            "Character hit points must not be greater than 100.");

    this->hitPoints = hitPoints;
}

/** Return the strength of the character. */
int Character::getStrength()
{
    return this->strength;
}

/** Set the Character's strength.
 *
 * Args:
 *   int strength:
 *     The amount of strength to give your Character.
 *     Must be less than 10.
 *
 * Throws std::invalid_argument:
 *   If provided strength is too high or low.
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

/** Return the defence of the character. */
int Character::getDefence()
{
    return this->defence;
}

/** Set the defence of the character.
 *
 * Args:
 *   int defence:
 *     The amount of defence to give your Character.
 *     Must be less than 10.
 *
 * Throws std::invalid_argument:
 *   If provided defence is too high or low.
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

/** Return the damage dealt by the Character this turn. */
int Character::doAction()
{
    return this->strength;
}

/** Take damage from an attack.
 *
 * Updates the Character's hit points by
 * subtracting the amount of damage taken by
 * the Character's defence, then subtracts the
 * reduced damage from the Character's hit points.
 *
 * Args:
 *   int damage:
 *     The amount of damage to take.
 */
void Character::takeDamage(int damage)
{
    int totalDamage = damage - this->getDefence();

    if (totalDamage < 0)
        totalDamage = 0;

    int hitPoints = (this->getHitPoints() - totalDamage);

    this->setHitPoints(hitPoints);
}

/** Return whether the character is alive. */
bool Character::isAlive()
{
    return (this->hitPoints > 0);
}
