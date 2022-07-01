#ifndef CHARACTER
#define CHARACTER

#include <string>

/**
 * @brief Class representing a character in the game.
 *
 * @param name The name of the character.
 * @param hitPoints The amount of health the character has.
 * @param strength The amount of base damage the character can do.
 * @param defence The amount of damage a character can mitigate per turn.
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
