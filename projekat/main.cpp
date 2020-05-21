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
    ostream& operator<<(ostream& izlaz, const Character& c){

    izlaz<<c.playerName<<" sa moci "<<c.ability<<endl;

return izlaz;
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
int main()
{
   /* Mapa* pom;
    pom=&g;
    pom->ispisMape();
    prosli rok
    */
    int x, y, z, xx, brojac1=0, brojac2=0, brojac3=0;
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
    Heal h1(true, 20, 1, "Bangalore", "Rolling Thunder", true, 60, 0, true);
    Heal h2(true, 30, 1, "Bangalore", "Rolling Thunder", true, 60, 0, true);
    Heal h3(true, 10, 1, "Bangalore", "Rolling Thunder", true, 60, 0, true);
    Stocks s1(stock, 3, true, true);
    Stocks s2(mag, 1, false, true);
    Stocks s3(stabilizer, 2, true, false);
    cout<<"Dobro dosli u Apex Legends!\n";

do
{
    do{
    cout<<"Da li zelite pogledati sta je danas u asortimanu u prodavnici?\nAko zelite, pritisnite taster 0\nAko zelite uci u mec pritisnite taster 1, a ako zelite izaci iz igrice pritisnite taster 8: "<<endl;
    cin>>x;
    if(x!=0 && x!=1 && x!=8)
        cout<<"Morate pritisnuti jedan od tastera 0 ili 1 ili 8!"<<endl;
    }while(x!=0 && x!=1 && x!=8);
    if(x==0){
    funkcijaZaSkinove(Radnja);
    cout<<endl<<endl;
        cout<<"Ako zelite prvi skin, pritisnite taster 1"<<endl;
        cout<<"Ako zelite drugi skin, pritisnite taster 2"<<endl;
        cout<<"Ako zelite treci skin, pritisnite taster 3"<<endl;
        cout<<"Ako ne zelite nista kupiti, pritisnite taster 0"<<endl;
        do
    {
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
    brojac1=0;
    brojac2=0;
    brojac3=0;
    if(x==1)
    {
        cout<<"Da li zelite odigrati normal, ili ranked"<<endl;
        cout<<"Ako zelite normal, pritisnite taster 0, ako zelite ranked, pritisnite taster 1"<<endl;
        do
        {
            cin>>z;
            if(z!=0 && z!=1)
                cout<<"Molim vas unesite broj 0 ili 1!"<<endl;
        }while(z!=0 && z!=1);
        if(z==0)
        {
            cout<<"..................\n.                 .\n.                 .\n.                 .\n.   Ucitava se    .\n.                 .\n.                 .\n.                 .\n..................\n"<<endl;
            cout<<"Izaberite kojeg lika zelite igrati ovaj mec: "<<endl;
            cin>>xx;
                switch(xx)
                {
                case 1:
                    cout<<"Izabrali ste lika "<<c1<<endl;
                    break;
                case 2:
                    cout<<"Izabrali ste lika "<<c2<<endl;
                    break;
                case 3:
                    cout<<"Izabrali ste lika "<<c3<<endl;
                    break;
                case 4:
                    cout<<"Izabrali ste lika "<<c4<<endl;
                    break;
                case 5:
                    cout<<"Izabrali ste lika "<<c5<<endl;
                    break;
                }
            cout<<"Trenutno je zivo "<<g1.getBrojIgraca()<<" igraca"<<endl;
            cout<<"Trcite napred\nNE SKACITE ODATLE\nSami ste sebi skinuli pola zivota tim ubitacnim skokom!\nUsli ste u zgradu\nSta cete pokupiti?????\n"<<endl;
            if(xx==1)
            c1.setHealth(60);
            if(xx==2)
            c2.setHealth(60);
            if(xx==3)
            c3.setHealth(60);
            if(xx==4)
            c4.setHealth(60);
            if(xx==5)
            c5.setHealth(60);
            cout<<"Ispred vas se nalazi vise stvari za izlecivanje vasih rana od skoka\n";
            cout<<"zavoj, prva pomoc, energetsko pice"<<endl;
            cout<<"Taster 1 za zavoje, 2 za prvu pomoc i 3 za energetsko pice (0 ako ne zelite nista, mada vam treba)"<<endl;
            int yy;
            do
            {
                cin>>yy;
                if(yy>3)
                    cout<<"Unesite ponudjeni broj"<<endl;
            }while(yy!=0 && yy!=1 && yy!=2 && yy!=3);
            if(yy==0)
                cout<<"Niste uzeli nista za izlecivanje!"<<endl;
                switch(yy)
                {
            case 1:
                cout<<"Uzeli ste zavoje!\nZavijate se!\n";
                h1.metodaH();
                cout<<"Vas broj zivota je trenutno "<<c1.getHealth()<<endl;;
                break;
            case 2:
                cout<<"Imate prvu pomoc!\nHajde da se izlecimo!"<<endl;
                h2.metodaH();
                cout<<"Vas broj zivota je trenutno "<<c2.getHealth();
                break;
            case 3:
                cout<<"Uzeli ste energetsko pice. Naiskap!"<<endl;
                h3.metodaH();
                cout<<"Vas broj zivota je trenutno "<<c3.getHealth()<<endl;
                break;
                }

        }
        if(z==1)
        {
            cout<<"Usli ste u ranked mec\nOvde su samo ozbiljni igraci\nNeki ljudi od ovoga i zive"<<endl;
            cout<<"Slobodno hodajte malo napred"<<endl;
            cout<<"Nasli ste stvari koje ce vam biti potrebne za pusku!\n";     //Napravicu i puske sa onih 20 metoda, opusteno profesorka

        }
    }
    cout<<"Ako pritisnete sada taster 8, izlazite iz igrice, ako ne zelite pritisnite bilo koji taster"<<endl;
    cin>>x;
    if(x==8)
    {
        cout<<"Sigurno zelite izaci iz igrice?  (Potvrdite ponovnim pritiskom na taster 8)"<<endl;
    cin>>x;

    }
}while(x!=8);
    return 0;
}
