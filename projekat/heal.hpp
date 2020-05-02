#ifndef HEAL_HPP_INCLUDED
#define HEAL_HPP_INCLUDED
#include "character.hpp"
class Heal
{
protected:
    bool kind;
    int power;
    int number;
    Character c;
public:

    Heal(bool kind1, int power1, int number1, string playerName1, string ability1, bool cooldown1, int health1, int armour1):c(playerName1, ability1, cooldown1, health1, armour1)
    {
        kind=kind1;
        power=power1;
        number=number1;
    }
    void metodaH()
    {
        if(kind==true)
        {
            if(c.getHealth()<100)
            {
                int x;
                x=c.getHealth();
                c.setHealth(x+power);
            }
            if(c.getHealth()>=100)
            {
                c.setHealth(100);
                cout<<"Maksimalan broj zivota"<<endl;
            }
        }
        if(kind==false)
        {
            if(c.getArmour()<100)
            {
                int y;
                y=c.getArmour();
                c.setArmour(y+power);
            }
            if(c.getArmour()>=100)
            {
                c.setArmour(100);
                cout<<"Maksimalan broj oklopa"<<endl;
            }
        }
    }
};

#endif // HEAL_HPP_INCLUDED
