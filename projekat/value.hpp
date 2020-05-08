#ifndef VALUE_HPP_INCLUDED
#define VALUE_HPP_INCLUDED
class Value
{
protected:
    double amount;
    bool threshold;
public:
    Value(double amount1, bool threshold1)
    {
        amount=amount1;
        threshold=threshold1;
    }
    double getAmount(){return amount;}
    bool getThreshold(){return threshold;}
    void setAmount(double a){amount=a;}


};

#endif // VALUE_HPP_INCLUDED
