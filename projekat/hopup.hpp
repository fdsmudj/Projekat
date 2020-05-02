#ifndef HOPUP_H_INCLUDED
#define HOPUP_H_INCLUDED
enum hopup {doubleTap, turbocharger, selectfire, choke, hammerpoint};
class Hopup
{
protected:
    hopup h;
    bool rarity;
public:
    Hopup(hopup h1, bool rarity1)
    {
        h=h1;
        rarity=rarity1;
    }
};

#endif // HOPUP_H_INCLUDED
