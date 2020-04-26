#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

class Character
{
protected:
    string playerName;
    string ability;
    bool cooldown;
public:
    Charcater(string name, string ability1, bool cd)
    {
        playerName=name;
        ability=ability1;
        cooldown=cd;
    }

};

#endif // CHARACTER_HPP_INCLUDED
