#ifndef PALADIN
#define PALADIN

#include <string>
#include "Warrior.hpp"

/**
 * @brief Class to represent the character type Paladin.
 *
 * @param name The name to give your paladin.
 * @param hitPoints How much health your paladin should have.
 * @param strength How much base damage your paladin can do.
 * @param defence The amount of damage your paladin can mitigate per turn.
 * @param ragePoints How much rage your paladin starts with.
 * @param healAmount How much health the heal spell does.
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
