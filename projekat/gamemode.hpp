#ifndef GAMEMODE_HPP_INCLUDED
#define GAMEMODE_HPP_INCLUDED
#include "mapa.hpp"
class Gamemode
{
protected:
    int numOfPlayers;
    Mapa mapName;
public:
    Gamemode(int numOfPlayers1, string name1, int rarity1):mapName(string name1, int rarity1)
    {

    }
};

#endif // GAMEMODE_HPP_INCLUDED
