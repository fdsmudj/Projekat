#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED
void pisiTxt(string Equipment, string tekst, char mode='w')
{
    ofstream file;
    if (mode=='a'){
        file.open (Equipment, ios_base::app);
    }else
    {
        file.open (Equipment);
    }
    file << tekst << endl;
    file.close();
}
void citajTxt(string Equipment)
{
    string line;
    ifstream file (Equipment);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            cout << line << '\n';
        }
        file.close();
    }

    else
        cout << "Fajl se ne moze otvoriti!";

}
void Oprema()
{
    string fajl="Equipment.txt";
    char enter[100];
    cin.getline(enter,sizeof(enter));
}

enum tyype {backpack, helmet, shield, knockdownshield};
class Equipment
{
protected:
    tyype e;
    int rarity;
    string specAbility;
    int amount;
public:
    Equipment(tyype e1, int rarity1, string specAbility1, int amount1)
    {
        e=e1;
        rarity=rarity1;
        specAbility=specAbility1;
        amount=amount1;
    }
    void metodaE()
    {
        if(e==backpack)
            amount=(rarity*2)+4;
        else
            amount=rarity*25;

    }

};

#endif // EQUIPMENT_HPP_INCLUDED
