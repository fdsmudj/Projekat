#ifndef WEAPONS_HPP_INCLUDED
#define WEAPONS_HPP_INCLUDED
enum clas {heavy=1, light=2, energy=3, shells=4};
class Weapons
{
    clas c;
    int damage;
    bool reload;
    int numOfBullets;
    double reloadTime;
    bool headshot;
};

#endif // WEAPONS_HPP_INCLUDED
