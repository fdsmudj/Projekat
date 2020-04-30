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

    Heal(bool kind1, int power1=10, int number1, stirng pN, stirng ab, bool cd, int health, int armour):c(pN, ab, cd, health, armour)
    {
        kind=kind1;
        power=power1;
        number=number1;
    }
    void metodaH()
    {
        if(kind==true)
        {
            if(c.setHealth<100)
            {
                int x;
                x=c.setHealth();
                c.setHealth(x+power);
            }
            if(c.setHealth>100)
            {
                c.setHealth(100);
                cout<<"Maksimalan broj zivota"<<endl;
            }
        }
        if(kind==false)
        {
            if(c.setArmour<100)
            {
                int y;
                y=c.setArmour();
                c.setArmour(y+power);
            }
            if(c.setArmour>100)
            {
                c.setArmour(100);
                cout<<"Maksimalan broj oklopa"<<endl;
            }
        }
    }
};

#endif // HEAL_HPP_INCLUDED
