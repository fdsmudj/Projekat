#ifndef GAMEMODE_HPP_INCLUDED
#define GAMEMODE_HPP_INCLUDED
#include "mapa.hpp"
class Gamemode
{
protected:
    int numOfPlayers;
    Mapa mapa;
public:
    Gamemode(int numOfPlayers1, string name1, int rarity1):mapa(name1, rarity1)
    {
    numOfPlayers=numOfPlayers1;
    }

};

#endif // GAMEMODE_HPP_INCLUDED
