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
    bool active;
public:
    Character(string playerName1, string ability1, bool cooldown1, int health1, int armour1, bool active1)
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


    virtual void ispisCoveka()
    {
        cout<<"Zdravo, ja sam tvoj karakter ";
    }
friend ostream& operator<<(ostream& izlaz, const Character& c);
};

#endif // CHARACTER_HPP_INCLUDED
