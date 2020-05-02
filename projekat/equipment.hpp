#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED

void citaj(string Equipment)
{
    string line;
    ifstream file (Equipment);
    if (file.is_open())
    {
        while(getline(file,line))
        {
            cout<<line<<endl;
        }
        file.close();
    }

    else
        cout << "Fajl se ne moze otvoriti!"<<endl;
}
enum typee {Guardian_angel=1, Fast_charge,Fast_heal, Self_revive};
enum tyype {backpack=1, helmet, shield, knockdownshield};
class Equipment
{
protected:
    tyype e;
    int rarity;
    typee specAbility;
    int amount;
public:
    Equipment(tyype e1, int rarity1, typee specAbility1, int amount1)
    {
        e=e1;
        rarity=rarity1;
        specAbility=specAbility1;
        amount=amount1;
    }
    void metodaE()
    {
        if(e==1)
        {
            amount=(rarity*2)+4;
            cout<<"U rancu ima "<<amount<<" mesta "<<endl;
            if(rarity==4)
            {
            specAbility=Guardian_angel;
         cout<<"Oktljucana specijalna sposobnost: "<<" Guardian_angel "<<endl<<endl;
            }
        }
        if(e==2)
        {
            amount=rarity*25;
            cout<<"Kaciga je na "<<amount<<"% snage "<<endl;
            if(rarity==4)
            {
            specAbility=Fast_charge;
            cout<<"Oktljucana specijalna sposobnost: "<<" Fast_charge "<<endl<<endl;
            }
        }
        if(e==3)
        {
            amount=rarity*25;
            cout<<"Stit je na "<<amount<<"% snage"<<endl;
            if(rarity==4)
            {
            specAbility=Fast_heal;
            cout<<"Oktljucana specijalna sposobnost: "<<" Fast_heal "<<endl<<endl;
            }
        }
        if(e==4)
        {
            amount=rarity*50;
            cout<<"Snaga oborenog stita je "<<amount<<endl;
            if(rarity==4)
            {
            specAbility=Self_revive;
            cout<<"Oktljucana specijalna sposobnost: "<< "Self_revive"<<endl<<endl;
            }
        }
    }

};

#endif // EQUIPMENT_HPP_INCLUDED
