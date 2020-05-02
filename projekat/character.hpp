#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

class Character
{
protected:
    string playerName;
    string ability;
    bool cooldown;
    int health;
    int armour;
public:
    Character(string playerName1, string ability1, bool cooldown1, int health1, int armour1)
    {
        playerName=playerName1;
        ability=ability1;
        cooldown=cooldown1;
        health=health1;
        armour=armour1;
    }
    void setHealth(int health1) {health=health1;}
    void setArmour(int armor) {armour=armor;}
    int getHealth(){return health;}
    int getArmour(){return armour;}

};

#endif // CHARACTER_HPP_INCLUDED
