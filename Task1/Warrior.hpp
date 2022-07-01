#ifndef WARRIOR
#define WARRIOR

#include <string>
#include "Character.hpp"

/**
 * @brief Class to represent a character type Warrior.
 *
 * @param name The name of the warrior.
 * @param hitPoints How much health the warrior has.
 * @param strength How much base damage the warrior can do.
 * @param defence How much damage the warrior can mitigate per turn.
 * @param ragePoints How much rage the warrior has stored.
 */
class Warrior : public Character
{
private:
    std::string name;
    int hitPoints;
    int strength;
    int defence;
    int ragePoints;

public:
    Warrior();
    Warrior(std::string name, int hitPoints, int strength,
            int defence, int ragePoints);

    int getRagePoints();
    void setRagePoints(int ragePoints);

    int doAction();
};

#endif
