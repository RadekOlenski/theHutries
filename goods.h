#ifndef GOODS_H
#define GOODS_H


class Goods
{
public:
    Goods();
    Goods(unsigned int wood, unsigned int stone, unsigned int food, unsigned int gold);
    unsigned int getWood() {return wood;};
    unsigned int getGold() {return gold;};
    unsigned int getFood() {return food;};
    unsigned int getStone() {return stone;};
    void setProduct(unsigned int choice, int howMany = 0);
    bool isEmpty();
    Goods & operator +( Goods & goods );
    Goods & operator -( Goods & goods );
    bool operator >=( int number );
    unsigned int whichProduct();
private:
    unsigned int wood;
    unsigned int stone;
    unsigned int food;
    unsigned int gold;

};

#endif // GOODS_H
