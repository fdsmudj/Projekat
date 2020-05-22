#ifndef STOCKS_HPP_INCLUDED
#define STOCKS_HPP_INCLUDED
enum type {stock, mag, stabilizer, scope};

class Stocks
{
protected:
    type s;
    int rarity;
    bool hcog;
    bool light;
    bool active;
public:
    Stocks(type s1, int rarity1, bool hcog1, bool light1, bool active1)
    {
        s=s1;
        rarity=rarity1;
        hcog=hcog1;
        light=light1;
        active=active1;
    }
    friend ostream& operator<<(ostream& izlaz, const Stocks& s);
    int getRarity(){return rarity;}
    bool returnHcog(){return hcog;}
    bool returnLight(){return light;}
    bool getActive(){return active;}
    void setActive(bool a){active=a;}
};

#endif // STOCKS_HPP_INCLUDED
