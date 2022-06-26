#ifndef MAGE
#define MAGE

#include <string>
#include "Character.hpp"

/** Class to represent a character with the class of Mage.
 *
 * Properties:
 *   std::string name:
 *     The name of the mage.
 *
 *   int hitPoints:
 *     The number of hitpoints the mage has.
 *
 *   int strength:
 *     The base amount of damage a mage can do
 *     in hitpoints.
 *
 *   int defence:
 *     How much damage a mage can mitigate
 *     in hitpoints.
 *
 *   int manaPoints:
 *     How much mana the mage has. This is depleted
 *     with each spell cast, and replenished by using
 *     a base attack instead of a spell.
 *
 *   int fireballDamage:
 *     The amount of damage a fireball spell does.
 *     This costs 10 manaPoints to cast.
 *
 * Methods are documented in the implementation file.
 */
class Mage : public Character
{
private:
    std::string name;
    int hitPoints;
    int strength;
    int defence;
    int manaPoints;
    int fireballDamage;

public:
    Mage();
    Mage(std::string name, int hitPoints, int strength,
         int defence, int manaPoints, int fireballDamage);

    int getManaPoints();
    void setManaPoints(int manaPoints);

    int getFireballDamage();
    void setFireballDamage(int fireballDamage);

    int doAction();
};

#endif
