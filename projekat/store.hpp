#ifndef STORE_HPP_INCLUDED
#define STORE_HPP_INCLUDED

class Store
{
protected:
    int rarityOfSkin;
    string nameOfSkin;
    bool active;
    int valueOfSkin;
public:
    Store(int rarityOfSkin1, string nameOfSkin1, bool active1, int valueOfSkin1)
    {
        rarityOfSkin=rarityOfSkin1;
        nameOfSkin=nameOfSkin1;
        active=active1;
        valueOfSkin=valueOfSkin1;
    }
friend ostream& operator<<(ostream& izlaz, const Store& s);
};

#endif // STORE_HPP_INCLUDED
