#ifndef LEGENDARY_HPP_INCLUDED
#define LEGENDARY_HPP_INCLUDED
#include "weapons.hpp"

enum gun{kraber=1, mastiff, devotion};
class Legendary :public Weapons
{
protected:
    gun g;
    gun bullets;
public:
    Legendary(gun g1, gun bullets1, clas c1, int damage1, bool reload1, int numOfBullets1, double reloadTime1):Weapons(c1,damage1, reload1, numOfBullets1, reloadTime1)
    {
        g=g1;
        bullets=bullets1;
    }
    void ispisPolja()
    {
        Weapons::ispisPolja();
        cout<<", "<<g<<", "<<bullets;
    }
};

#endif // LEGENDARY_HPP_INCLUDED
