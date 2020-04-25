#ifndef LEGENDARY_HPP_INCLUDED
#define LEGENDARY_HPP_INCLUDED
#include "weapons.hpp"
enum gun {kraber, mastiff, devotion};
class Legendary: public Weapons
{
protected:
    gun g;
    gun bullets;
public:
    Legendary(gun g1, gun bullets1, clas c1, int damage1, bool reload1, int numOfBullets1, double reloadTime1, bool headshot1): Weapons(c1, damage1, reload1, numOfBullets1, reloadTime1, headshot1)
    {
        g=g1;
        bullets=bullets1;
    }
};

#endif // LEGENDARY_HPP_INCLUDED
