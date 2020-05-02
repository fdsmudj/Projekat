#ifndef WEAPONS_HPP_INCLUDED
#define WEAPONS_HPP_INCLUDED
enum clas {heavy=1, light=2, energy=3, shells=4};
class Weapons
{
protected:
    clas c;
    int damage;
    bool reload;
    int numOfBullets;
    double reloadTime;
    bool headshot;
public:
    Weapons(clas c1, int damage1, bool reload1, int numOfBullets1, double reloadTime1, bool headshot1)
    {
        c=c1;
        damage=damage1;
        reload=reload1;
        numOfBullets=numOfBullets1;
        reloadTime=reloadTime1;
        headshot=headshot1;
    }
};

#endif // WEAPONS_HPP_INCLUDED
