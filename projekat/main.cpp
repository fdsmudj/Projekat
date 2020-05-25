#include <iostream>
#include <fstream>
#include <stdlib.h>
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
#include <windows.h>


    ostream& operator<<(ostream& izlaz, const Stocks& s){

    izlaz<<"Stocks - ispis"<<endl;
    izlaz<<"TIP: "<<s.s<<endl;
    izlaz<<"RETKOST: "<<s.rarity<<endl;
    izlaz<<"OKULAR: "<<s.hcog<<endl;
    izlaz<<"AKTIVNOST: "<<s.active<<endl;
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
    ostream& operator<<(ostream& izlaz, const Character& c){
    izlaz<<"IME: "<<c.playerName<<endl;
    izlaz<<"MOC: "<<c.ability<<endl;
    izlaz<<"COOLDOWN: "<<c.cooldown<<endl;
    izlaz<<"BROJ ZIVOTA: "<<c.health<<endl;
    izlaz<<"BROJ OKLOPA: "<<c.armour<<endl;
    izlaz<<"AKTIVNOST: "<<c.active<<endl<<endl;


return izlaz;
    }
    ostream& operator<<(ostream& izlaz, const Store& s)
    {
        izlaz<<"RETKOST: "<< s.rarityOfSkin<<endl;
        izlaz<<"IME: "<< s.nameOfSkin<<endl;
        izlaz<<"AKTIVNOST: "<< s.active<<endl;
        izlaz<<"VREDNOST: "<< s.valueOfSkin<<endl<<endl;
    }
    vector<string> splitSen(string str, char c=',')
{
    string w = "";
    vector<string> v;
    for (auto rem : str)
    {
        if (rem==c)
        {
            v.push_back(w);
            w="";
        }
        else
        {
            w=w+rem;
        }
    }
    v.push_back(w);

    return v;
}
vector<string> split2(string NazivFajla)
{
    vector<string> v,line ;
    string linija;
    ifstream fajl (NazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            line=(splitSen(linija));
            v.insert(v.end(), line.begin(), line.end());
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";
    return v;

}
bool to_bool(string const& s) {
    if(s=="true")
        return true;
    else
        return false;

}
vector<Store> citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla);
    vector<Store> skinovi;
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            vector<string> rez;
            rez = splitSen(linija);
            Store s(stoi(rez[0]), rez[1], to_bool(rez[2]) , stoi(rez[3]));
            skinovi.push_back(s);
        }
        fajl.close();
        return skinovi;

    }

    else
        cout << "Neuspesno otvoren fajl";

}
void IspisFajlaStore(vector <string> Radnja)
{
    for(auto i=Radnja.begin(); i!=Radnja.end(); i++)
    {
        cout<<*i<<" ";
    }
}
void funkcijaZaSkinove(vector <string> Radnja)
{
    cout<<"Sta zelite kupiti?\nDanas u prodavnici imamo: "<<endl;
    for(int i=1; i<Radnja.size(); i+=4)
    {
        cout<<Radnja[i]<<" koji kosta "<<Radnja[i+2]<<" Apex novcica "<<endl;
    }
}

void dodavanjeStocka(string nazivFajla, Stocks &s, char mode='w')
{
    ofstream fajl;
    if (mode=='a')
        fajl.open (nazivFajla, ios_base::app);
    else
        fajl.open (nazivFajla);
    fajl <<s<< endl;
    fajl.close();
}
void dodavanjeHelta(string nazivFajla, Character& c, char mode='w')
{
    ofstream fajl;
    if (mode=='a')
        fajl.open (nazivFajla, ios_base::app);
    else
        fajl.open (nazivFajla);
    fajl <<c<< endl;
    fajl.close();
}
int unosX()
{
    int x;
    do{
    cout<<"Da li zelite pogledati sta je danas u asortimanu u prodavnici?\nAko zelite, pritisnite taster 0\nAko zelite uci u mec pritisnite taster 1, a ako zelite izaci iz igrice pritisnite taster 8: "<<endl;
    cin>>x;
    if(x!=0 && x!=1 && x!=8)
        cout<<"Morate pritisnuti jedan od tastera 0 ili 1 ili 8!"<<endl;
    }while(x!=0 && x!=1 && x!=8);
    return x;
}
void ispis1(Value &v)
{
        cout<<"Para imate "<<v.getAmount()<<endl;
        cout<<"Ako zelite prvi skin, pritisnite taster 1"<<endl;
        cout<<"Ako zelite drugi skin, pritisnite taster 2"<<endl;
        cout<<"Ako zelite treci skin, pritisnite taster 3"<<endl;
        cout<<"Ako ne zelite nista kupiti, pritisnite taster 0"<<endl;
}
void unosY(Value &v, vector<string> Radnja)
{
    int y;
    int brojac1=0, brojac2=0, brojac3=0;
    do
    {
        ispis1(v);
        cin>>y;
        switch(y)
        {
    case 1:
        if(brojac1==0)
        {
        if(v.Provera(stoi(Radnja[3])))
        {
            cout<<"Imate dovoljno Apex novcica da kupite ovaj skin!"<<endl;
            v.setAmount(v.getAmount()-stoi(Radnja[3]));
            brojac1++;
            cout<<"Skin kupljen!"<<endl<<endl<<endl;
        }
        else
            cout<<"Nazalost nemate dovoljno novca za skin"<<endl;
        break;
        }
        cout<<"Vi vec imate taj skin!"<<endl;
        break;
    case 2:
        if(brojac2==0)
        {
        if(v.Provera(stoi(Radnja[7])))
        {
            cout<<"Imate dovoljno Apex novcica da kupite ovaj skin!"<<endl;
            v.setAmount(v.getAmount()-stoi(Radnja[7]));
            brojac2++;
            cout<<"Skin kupljen!"<<endl;
        }
        else
            cout<<"Nazalost nemate dovoljno novca za skin"<<endl;
        break;
        }
        cout<<"Vi vec imate taj skin!"<<endl;
        break;
    case 3:
        if(brojac3==0)
        {
        if(v.Provera(stoi(Radnja[11])))
        {
            cout<<"Imate dovoljno Apex novcica da kupite ovaj skin!"<<endl;
            v.setAmount(v.getAmount()-stoi(Radnja[11]));
            brojac3++;
            cout<<"Skin kupljen!"<<endl;
        }
        else
            cout<<"Nazalost nemate dovoljno novca za skin"<<endl;
        break;
        }
        cout<<"Vi vec imate taj skin!"<<endl;
        break;
        }
    }while(y!=0);
}
int unosZ()
{
    int z;
    do
        {
            cin>>z;
            if(z!=0 && z!=1)
                cout<<"Molim vas unesite broj 0 ili 1!"<<endl;
        }while(z!=0 && z!=1);
        return z;
}
int izlaz()
{
    int x;
    cout<<"Ako pritisnete sada taster 8, izlazite iz igrice, ako ne zelite pritisnite bilo koji taster"<<endl;
    cin>>x;
    if(x==8)
    {
        cout<<"Sigurno zelite izaci iz igrice?  (Potvrdite ponovnim pritiskom na taster 8)"<<endl;
    cin>>x;

    }
    return x;
}
void ispisR()
{
    cout<<"Usli ste u ranked mec\nOvde su samo ozbiljni igraci\nNeki ljudi od ovoga i zive"<<endl;
    cout<<"Slobodno hodajte malo napred"<<endl;
    cout<<"Nasli ste stvari koje ce vam biti potrebne za pusku!\n";     //Napravicu i puske sa onih 20 metoda, opusteno profesorka
    cout<<"Ispred vas su tri stvari!\nImate mesta u rancu samo za jednu stvar!\n"<<endl;
    cout<<"Na podu je magazin, produzetak puske i optik"<<endl;        //Napravicu ovde vise svega da ima samo sam ovako manje uradio zbog roka
    cout<<"Taster 1 za magazin, 2 za produzetak puske i 3 za otpik! (ako ne zelite nista, taster 0"<<endl;
}
void ispisN(vector<Character> &niz,int lik, Gamemode &g1)
{
    cout<<"Izabrali ste "<<niz.at(lik-1);
    cout<<"Trenutno je zivo "<<g1.getBrojIgraca()<<" igraca"<<endl;
    cout<<"Trcite napred\nNE SKACITE ODATLE\nSami ste sebi skinuli pola zivota tim ubitacnim skokom!\nUsli ste u zgradu\nSta cete pokupiti?????\n"<<endl;
    niz.at(lik-1).setHealth(60);
    dodavanjeHelta("Rezultat funkcionalnosti.txt", niz.at(lik-1));
    cout<<"Ispred vas se nalazi vise stvari za izlecivanje vasih rana od skoka\n";
    cout<<"zavoj, prva pomoc, energetsko pice"<<endl;
    cout<<"Taster 1 za zavoje, 2 za prvu pomoc i 3 za energetsko pice (0 ako ne zelite nista, mada vam treba)"<<endl;
}
void pricekajte()
{
    cout<<"..................\n.                 .\n.                 .\n.                 .\n.   Ucitava se    .\n.                 .\n.                 .\n.                 .\n..................\n"<<endl;
            cout<<"Pricekajte"<<endl;
            Sleep(5000);
}
void ispisLikova(vector<Character> niz)
{
    cout<<"Ponudjeni likovi su: "<<endl;
        for(auto it=niz.begin(); it!=niz.end(); it++)
        {
            cout<<*it<<endl;
        }
}
int unosHil()
{
    int hil;
        do
        {
            cin>>hil;
            if(hil>3)
                cout<<"Unesite ponudjeni broj"<<endl;
        }while(hil!=0 && hil!=1 && hil!=2 && hil!=3);
        return hil;
}
void switchHil(vector<Character> niz, vector<Heal> niz2, int hil, int lik)
{
    switch(hil)
            {
        case 1:
            cout<<"Uzeli ste zavoje!\nZavijate se!\n";
            niz2.at(0).metodaH(niz.at(lik-1));
            cout<<"Vas broj zivota je trenutno "<<niz.at(0).getHealth()<<endl;
            break;
        case 2:
            cout<<"Imate prvu pomoc!\nHajde da se izlecimo!"<<endl;
            niz2.at(1).metodaH(niz.at(lik-1));
            cout<<"Vas broj zivota je trenutno "<<niz.at(1).getHealth();
            break;
        case 3:
            cout<<"Uzeli ste energetsko pice. Naiskap!"<<endl;
            niz2.at(2).metodaH(niz.at(lik-1));
            cout<<"Vas broj zivota je trenutno "<<niz.at(2).getHealth()<<endl;
            break;
            }
}
int unosMega()
{
    int meg;
    do
    {
        cout<<"Unesite sta cete pokupiti"<<endl;
        cin>>meg;
        if(meg!=0 && meg!=1 && meg!=2 && meg!=3)
            cout<<"Unesite broj koji je ponudjen!"<<endl;
    }while(meg!=0 && meg!=1 && meg!=2 && meg!=3);
    return meg;
}
int main()
{

    int x, y, z, lik, brojac1=0, brojac2=0, brojac3=0;
    vector<string> Radnja=split2("Store.txt");
    Mapa m("Kings canyon", 2);
    Value v(6000, true);
    Gamemode g1(60, "Kings canyon", 3);
    Gamemode g2(30, "Worlds end", 2);
    Character c1("Bangalore", "Rolling Thunder", false, 100, 0, false);
    Character c2("Revenant", "Death Totem", false, 100, 0, false);
    Character c3("Pathfinder", "Zipline", false, 100, 0, false);
    Character c4("Octane", "Jumpad", false, 100, 0, false);
    Character c5("Lifeline", "Care Package", false, 100, 0, false);
    Heal h1(true, 20, 1, "Bangalore", "Rolling Thunder", true, 100, 0, true);
    Heal h2(true, 30, 1, "Bangalore", "Rolling Thunder", true, 100, 0, true);
    Heal h3(true, 10, 1, "Bangalore", "Rolling Thunder", true, 100, 0, true);
    Stocks s1(stock, 3, true, false, false);
    Stocks s2(mag, 1, false, false, false);
    Stocks s3(stabilizer, 2, true, false, false);
    vector <Character> niz;
    vector <Heal> niz2;
    vector <Stocks> niz3;
    vector<Store> nizS=citajTxt("Store.txt");
    niz.push_back(c1);
    niz.push_back(c2);
    niz.push_back(c3);
    niz.push_back(c4);
    niz.push_back(c5);
    niz2.push_back(h1);
    niz2.push_back(h2);
    niz2.push_back(h3);
    niz3.push_back(s1);
    niz3.push_back(s2);
    niz3.push_back(s3);
    cout<<"Dobro dosli u Apex Legends!\n";
do
{
    x=unosX();
    if(x==0){
    funkcijaZaSkinove(Radnja);
    cout<<endl<<endl;
    unosY(v, Radnja);
    }
    brojac1=0;brojac2=0;brojac3=0;
    if(x==1)
    {
        cout<<"Da li zelite odigrati normal, ili ranked"<<endl;
        cout<<"Ako zelite normal, pritisnite taster 0, ako zelite ranked, pritisnite taster 1"<<endl;
        z=unosZ();
        if(z==0)
        {
            pricekajte();
            ispisLikova(niz);
            cout<<"Izaberite kojeg lika zelite igrati ovaj mec: "<<endl;
            cin>>lik;

            ispisN(niz, lik, g1);
            int hil;
            hil=unosHil();
            if(hil==0)
                cout<<"Niste uzeli nista za izlecivanje!"<<endl;
                switchHil(niz, niz2, hil, lik);
                niz2.at(hil-1).metodaH(niz.at(lik-1));
                cout<<"\n\nInternet vam je pukao, pa ste izbaceni nazad u lobby\n"<<endl;

        }
        if(z==1)
        {
            int meg;
            ispisR();
            meg=unosMega();
            switch(meg)
            {
            case 1:
                cout<<"Uzeli ste magazin!"<<endl;
                niz3.at(meg-1).setActive(true);
                break;
            case 2:
                cout<<"Uzeli ste produzetak za pusku!"<<endl;
                niz3.at(meg-1).setActive(true);
                break;
            case 3:
                cout<<"Uzeli ste optik!"<<endl;
                niz3.at(meg-1).setActive(true);
                break;
            }
            dodavanjeStocka("Rezultat funkcionalnosti.txt", niz3.at(meg-1));
            cout<<"Kraj igre za sada" <<endl;
        }
    }
    x=izlaz();
}while(x!=8);
    return 0;
}
