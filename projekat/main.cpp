#include <iostream>
#include <fstream>
using namespace std;
#include "character.hpp"
#include "charm.hpp"
#include "equipment.hpp"
#include "gamemode.hpp"
#include "hopup.hpp"
#include "legendary.hpp"
#include "loot.hpp"
#include "stocks.hpp"
#include "mapa.hpp"
#include "value.hpp"
#include "weapons.hpp"
int main()
{
    Equipment e(backpack, 2, Guardian_angel, 0);
    e.metodaCitajE();

    //Predlog funkcionalnosti: Moj rad tezi ka tome da kroz svih dvanaest klasa najbolje simulira radnju i desavanje igrice koju sam izabrao, ali bez animacija

    return 0;
}
