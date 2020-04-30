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
    Character(string name, string ability1, bool cd, int h, int a)
    {
        playerName=name;
        ability=ability1;
        cooldown=cd;
        health=h;
        armour=a;
    }
    void setHealth(int health1) {health=health1;}
    void setArmour(int armor) {armour=armor;}
    int getHealth(){return health;}
    int getArmour(){return armour;}

};

#endif // CHARACTER_HPP_INCLUDED
