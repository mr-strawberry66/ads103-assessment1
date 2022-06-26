#ifndef WARRIOR
#define WARRIOR

#include <string>
#include "Character.hpp"

/** Class to represent a character with the calss of Warrior.
 *
 * Properties:
 *   std::string name:
 *     The name of the warrior.
 *
 *   int hitPoints:
 *     The number of hitpoints the warrior has.
 *
 *   int strength:
 *     The base amount of damage a warrior can do
 *    in hitpoints.
 *
 *   int defence:
 *     How much damage a warrior can mitigate
 *     in hitpoints.
 *
 *   int ragePoints:
 *     How much rage the warrior has stored.
 *
 * Methods are documented in the implementation file.
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
