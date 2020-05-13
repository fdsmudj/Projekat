#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED
enum plN {Bangalore=1, Octane, Pathfinder, Revenant, Lifeline};
class Character
{
protected:
    plN playerName;
    string ability;
    bool cooldown;
    int health;
    int armour;
public:
    Character(plN playerName1, string ability1, bool cooldown1, int health1, int armour1)
    {
        playerName=playerName1;
        ability=ability1;
        cooldown=cooldown1;
        health=health1;
        armour=armour1;
    }
    void setHealth(int health1)
    {
        health=health1;
    }
    void setArmour(int armor)
    {
        armour=armor;
    }
    int getHealth()
    {
        return health;
    }
    int getArmour()
    {
        return armour;
    }
    void metodaCh1()
    {
        if(playerName==1)
        {
            ability="Rolling Thunder";
        }
        if(playerName==2)
        {
            ability="Launch Pad";
        }
        if(playerName==3)
        {
            ability="Zipline";
        }
        if(playerName==4)
        {
            ability="Care Package";
        }
        if(playerName==5)
        {
            ability="Death Totem";
        }
    }

};

#endif // CHARACTER_HPP_INCLUDED
