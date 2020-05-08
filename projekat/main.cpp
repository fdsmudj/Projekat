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
#include "store.hpp"

double Store::investment=0;

    ostream& operator<<(ostream& izlaz, const Stocks& s){

    izlaz<<"Stocks - ispis"<<endl;
    izlaz<<"TIP: "<<s.s<<endl;
    izlaz<<"RETKOST: "<<s.rarity<<endl;
    izlaz<<"OKULAR: "<<s.hcog<<endl;
    izlaz<<"METAK: "<<s.light<<endl<<endl;

return izlaz;
    }
    ostream& operator<<(ostream& izlaz, const Mapa& m){

    izlaz<<"Mapa - ispis"<<endl;
    izlaz<<"IME MAPE: "<<m.name<<endl;
    izlaz<<"RETKOST: "<<m.rarity<<endl<<endl;

return izlaz;
}
ostream& operator<<(ostream& izlaz, const Weapons& w){

    izlaz<<"Weapons - ispis"<<endl;
    izlaz<<"METAK: "<<w.c<<endl;
    izlaz<<"RETKOST: "<<w.reload<<endl;
    izlaz<<"BROJ METAKA: "<<w.numOfBullets<<endl;
    izlaz<<"VREME MENJANJA ŠARŽERA: "<<w.reloadTime<<endl;
    izlaz<<"POGODAK U GLAVU: "<<w.headshot<<endl;

return izlaz;
}

int main()
{
    Store s(3, "Skin", true, 10);
    Value v(100, true);
    s.Kupovina(v);
    cout<<Store::investment<<endl;

    //Predlog funkcionalnosti: Moj rad tezi ka tome da kroz svih dvanaest klasa najbolje simulira radnju i desavanje igrice koju sam izabrao, ali bez animacija

    return 0;
}
