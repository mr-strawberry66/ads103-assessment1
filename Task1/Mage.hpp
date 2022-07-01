#ifndef MAGE
#define MAGE

#include <string>
#include "Character.hpp"

/**
 * @brief Class to represent the character type Mage.
 *
 * @param name The name to give your mage.
 * @param hitPoints How much health your mage should have.
 * @param strength How much base damage your mage can do.
 * @param defence The amount of damage your mage can mitigate per turn.
 * @param manaPoints How much mana your mage starts with.
 * @param fireballDamage How much damage the fireball spell does.
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
