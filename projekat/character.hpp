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
    bool active;
public:
    Character(plN playerName1, string ability1, bool cooldown1, int health1, int armour1, bool active1)
    {
        playerName=playerName1;
        ability=ability1;
        cooldown=cooldown1;
        health=health1;
        armour=armour1;
        active=active1;
    }
    void setHealth(int health1){health=health1;}
    void setArmour(int armor){armour=armor;}
    int getHealth(){return health;}
    int getArmour(){return armour;}
    string getAbility(){return ability;}

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
    virtual void ispisCoveka()
    {
        cout<<"Zdravo, ja sam tvoj karakter ";
    }

};

#endif // CHARACTER_HPP_INCLUDED
