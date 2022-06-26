#ifndef PALADIN
#define PALADIN

#include <string>
#include "Warrior.hpp"

/** Class to represent a character with the class of Paladin.
 *
 * Properties:
 *   std::string name:
 *     The name of the Paladin.
 *
 *   int hitPoints:
 *     The number of hitpoints the Paladin has.
 *
 *   int strength:
 *     The base amount of damage a Paladin can do
 *     in hitpoints.
 *
 *   int defence:
 *     How much damage a Paladin can mitigate
 *     in hitpoints.
 *
 *   int ragePoints:
 *     How much rage the Paladin has stored.
 *     This is used to increase the amount
 *     of damage dealt, or to heal the Paladin.
 *
 *   int healAmount:
 *     How much the Paladin can heal for.
 *
 * Methods are documented in the implementation file.
 */
class Paladin : public Warrior
{
private:
    std::string name;
    int hitPoints;
    int strength;
    int defence;
    int ragePoints;
    int healAmount;

public:
    Paladin();
    Paladin(std::string name, int hitPoints, int strength,
            int defence, int ragePoints, int healAmount);

    int getHealAmount();
    void setHealAmount(int healAmount);

    int doAction();
};

#endif
