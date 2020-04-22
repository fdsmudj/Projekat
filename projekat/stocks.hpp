#ifndef STOCKS_HPP_INCLUDED
#define STOCKS_HPP_INCLUDED
enum type {stock, mag, stabilizer, scope};

class Stocks
{
private:
    type s;
    int rarity;
    bool hcog;
    bool light;
};

#endif // STOCKS_HPP_INCLUDED
