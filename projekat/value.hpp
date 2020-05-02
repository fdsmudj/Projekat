#ifndef VALUE_HPP_INCLUDED
#define VALUE_HPP_INCLUDED
enum value {apexCoin=100, craftingMetals=10, ironCrown=1};
class Value
{
protected:
    value v;
    bool threshold;
public:
    Value(value v1, bool threshold1)
    {
        v=v1;
        threshold=threshold1;
    }

};

#endif // VALUE_HPP_INCLUDED
