#ifndef LOOT_HPP_INCLUDED
#define LOOT_HPP_INCLUDED
#include "loot.hpp"
#include "equipment.hpp"
#include "stocks.hpp"
class Loot
{
protected:
    Heal H;
    Equipment E;
    Stocks S;
public:
    Loot(bool kind1, int power1, tyype e1, int rarity1, int specAbility1, type s1, int rarity2, bool hcog1, bool light1):H(kind1, power1),E(e1, rarity1, specAbility1),S( s1,rarity2, hcog1, light1)
    {

    }
};

#endif // LOOT_HPP_INCLUDED
