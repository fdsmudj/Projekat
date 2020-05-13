#include <iostream>
#include <fstream>
using namespace std;
#include "character.hpp"
#include "charm.hpp"
#include "equipment.hpp"
#include "gamemode.hpp"
#include "hopup.hpp"
#include "loot.hpp"
#include "legendary.hpp"
#include "stocks.hpp"
#include "mapa.hpp"
#include "value.hpp"
#include "weapons.hpp"
#include "store.hpp"


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
    ostream& operator<<(ostream& izlaz, const Equipment& e){

    izlaz<<"Oprema - ispis"<<endl;
    izlaz<<"NAZIV OPREME: "<<e.e<<endl;
    izlaz<<"RETKOST: "<<e.rarity<<endl;
    izlaz<<"SPECIJALNA SPOSOBNOST: "<<e.specAbility<<endl;
    izlaz<<"KOLICINA: "<<e.amount<<endl<<endl;

return izlaz;
    }
int main()
{
    Stocks st(stock, 2, false, true);
    cout<<st<<endl;
    Mapa m("Kings canyon", 2);
    cout<<m<<endl;
    Equipment e(helmet, 3, Guardian_angel, 10);
    cout<<e<<endl;
    Store s(3, "Skin", true, 10);
    Value v(100, true);
    Weapons w(heavy, 10, true, 20, 4.50);
    Legendary l(kraber, kraber, heavy, 15, true, 50, 10);
    w.ispisPolja();
    cout<<endl<<endl;
    l.ispisPolja();


    //Predlog funkcionalnosti: Moj rad tezi ka tome da kroz svih dvanaest klasa najbolje simulira radnju i desavanje igrice koju sam izabrao, ali bez animacija

    return 0;
}
