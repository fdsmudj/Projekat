#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED
enum tyype {backpack, helmet, shield, knockdownshield};
class Equipment
{
protected:
    tyype e;
    int rarity;
    int specAbility;
    int amount;
public:
    Equipment(tyype e1, int rarity1, int specAbility1, int amount1=0)
    {
        e=e1;
        rarity=rarity1;
        specAbility=specAbility1;
        amount=amount1;
    }
    void metodaE()
    {
        if(e==backpack)
            amount=(rarity*2)+4;
        else
            amount=rarity*25;

    }

};

#endif // EQUIPMENT_HPP_INCLUDED
