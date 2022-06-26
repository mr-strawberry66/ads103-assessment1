#ifndef CHARACTER
#define CHARACTER

#include <string>

/** Class to represent a character in the game.
 *
 * This class should be inherited from to create
 * subclasses, for example, a mage, or warrior.
 *
 * Properties:
 *   std::string name:
 *     The name of the character.
 *
 *   int hitPoints:
 *     The number of hitpoints the character has.
 *
 *   int strength:
 *     The base amount of damage a character can do
 *     in hitpoints.
 *
 *   int defence:
 *     How much damage a character can mitigate
 *     in hitpoints.
 *
 * Methods are documented in the implementation file.
 */
class Character
{
private:
    std::string name;
    int hitPoints;
    int strength;
    int defence;

public:
    Character();
    Character(std::string name, int hitPoints, int strength, int defence);

    std::string getName();
    void setName(std::string name);

    int getHitPoints();
    void setHitPoints(int hitPoints);

    int getStrength();
    void setStrength(int strength);

    int getDefence();
    void setDefence(int defence);

    int doAction();
    void takeDamage(int damage);
    bool isAlive();
};

#endif
