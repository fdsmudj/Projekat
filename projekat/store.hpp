#ifndef STORE_HPP_INCLUDED
#define STORE_HPP_INCLUDED

class Store
{
protected:
    int rarityOfSkin;
    string nameOfSkin;
    bool active;
    double valueOfSkin;
public:
    static double investment;
    Store(int rarityOfSkin1, string nameOfSkin1, bool active1, double valueOfSkin1)
    {
        rarityOfSkin=rarityOfSkin1;
        nameOfSkin=nameOfSkin1;
        active=active1;
        valueOfSkin=valueOfSkin1;
    }

    void Kupovina(Value &v)
    {
        if(v.getAmount()>valueOfSkin && v.getThreshold()==true)
        investment=investment+valueOfSkin;
        v.setAmount(v.getAmount()-valueOfSkin);

    }

};

#endif // STORE_HPP_INCLUDED
