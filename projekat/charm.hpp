#ifndef CHARM_HPP_INCLUDED
#define CHARM_HPP_INCLUDED

class Charm
{
protected:
    int rarity;
    bool activity;
public:
    Charm(int rarity1, bool activity1)
    {
        rarity=rarity1;
        activity=activity1;
    }
};

#endif // CHARM_HPP_INCLUDED
