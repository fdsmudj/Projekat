#ifndef LOOT_HPP_INCLUDED
#define LOOT_HPP_INCLUDED
#include "heal.hpp"
#include "equipment.hpp"
#include "stocks.hpp"
class Loot
{
protected:
    Heal H;
    Equipment E;
    Stocks S;
public:
    Loot(bool kind1, int power1, int number1, plN playerName1, string ability1, bool cooldown1, int health1, int armour1, tyype e1, int rarity1, typee specAbility1, int amount1, type s1, int rarity2, bool hcog1, bool light1)
    :H(kind1, power1, number1, playerName1, ability1, cooldown1, health1, armour1),E(e1, rarity1, specAbility1, amount1),S( s1,rarity2, hcog1, light1)
    {

    }
};

#endif // LOOT_HPP_INCLUDED
