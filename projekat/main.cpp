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
#include <vector>


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
    Mapa m1("Kings canyon", 2);
    Mapa m2("Worlds end", 3);
    Mapa m3("Hot nigga by Bobby shmurda", 1);
    Equipment e(helmet, 3, Guardian_angel, 10);
    Store s(3, "Skin", true, 10);
    Value v(100, true);
    Weapons w(heavy, 10, true, 20, 4.50);
    Legendary l(kraber, kraber, heavy, 15, true, 50, 10);
    Gamemode g(60, "Kings canyon", 3);
    Character ct1(Bangalore, "Landing zone", true, 100, 0, true);
    cout<<st<<endl;
    cout<<m1<<endl;
    cout<<e<<endl;
    w.ispisPolja();
    cout<<endl<<endl;
    l.ispisPolja();
    cout<<endl<<endl;
    g.ispisMape();
    cout<<endl<<endl;
    g.dodajMapu(m1);
    g.dodajMapu(m2);
    g.dodajMapu(m3);
    g.ispisMapa();
    cout<<endl<<endl;
    cout<<g.brojMapa();
    cout<<endl<<endl;
    g.brisanje();
    cout<<endl<<endl;
    cout<<g.brojMapa();
    cout<<endl<<endl;
    g.ispisMapa();
    cout<<endl<<endl;
    g.pretraga();
    cout<<endl<<endl;
    g.pretragaPoRetkosti(m1);


    //Predlog funkcionalnosti: Moj rad tezi ka tome da kroz svih dvanaest klasa najbolje simulira radnju i desavanje igrice koju sam izabrao, ali bez animacija

    return 0;
}
