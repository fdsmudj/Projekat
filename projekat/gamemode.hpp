#ifndef GAMEMODE_HPP_INCLUDED
#define GAMEMODE_HPP_INCLUDED
#include "mapa.hpp"
#include <vector>
#include "character.hpp"
class Gamemode:public Mapa
{
protected:
    int numOfPlayers;
    vector<Mapa*>mape;
public:
    Gamemode(int numOfPlayers1, string name1, int rarity1):Mapa(name1, rarity1)
    {
    numOfPlayers=numOfPlayers1;
    }
    void ispisMape()
    {
        Mapa::ispisMape();
        cout<<" a igraca ima "<<numOfPlayers<<endl;
    }
    void dodajMapu(Mapa &m)
    {
        mape.push_back(&m);
    }
    void ispisMapa()
    {
        cout<<"Dobrodosli u Apex Legends"<<endl<<endl;
        cout<<"Imena mapa su : "<<endl<<endl;
        for(auto it=mape.begin(); it!=mape.end(); it++)
        {
            (*it)->ispisMape();
            cout<<endl;
        }
    }
    int brojMapa()
    {
        cout<<"Ukupan broj svih mapa je ";
        return mape.size();
    }
    void brisanje()
    {
        cout<<"Brise se poslednja mapa";
        mape.erase (mape.begin()+2);
    }
    void pretraga()
    {
        long long unsigned x;
        cout<<"Unesite broj mape koju zelite da bude ispisana: ";
        do
        {
            cin>>x;
            if(x>mape.size() || x<0)
                cout<<"Broj mora biti manji od "<<mape.size()<<" i veci od 0!"<<endl;
        }while(x>mape.size() || x<0);
        cout<<"Statistike mape koju ste izabrali je: "<<endl<<*mape.at(x);
    }
    void pretragaPoRetkosti(Mapa &m)
    {
        int x;
        cout<<"Unesite velicinu retkosti i ispisace se svaka mapa koja je te retkosti (ako postoji): ";
        cin>>x;
        if(m.getRarity()==x)
        {
            cout<<*mape.at(x);
        }
        else
            cout<<"Ne postoji retkost "<<x<<" ."<<endl;
    }
};

#endif // GAMEMODE_HPP_INCLUDED
