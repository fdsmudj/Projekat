#ifndef MAPA_HPP_INCLUDED
#define MAPA_HPP_INCLUDED

class Mapa
{
protected:
    string name;
    int rarity;
public:
    Mapa(string name1, int rarity1)
    {
        name=name1;
        rarity=rarity1;
    }
};

#endif // MAPA_HPP_INCLUDED
