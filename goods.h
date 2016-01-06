#ifndef GOODS_H
#define GOODS_H


class Goods
{
public:
    Goods();
    Goods(unsigned int wood, unsigned int stone, unsigned int food = 0, unsigned int gold = 0);
     int getWood() {return wood;};
     int getGold() {return gold;};
     int getFood() {return food;};
     int getStone() {return stone;};
    void setProduct(unsigned int choice, int howMany = 0);
    bool isEmpty();
    Goods & operator +( Goods & goods );
    Goods & operator -( Goods & goods );
    bool operator >=( int number );
    unsigned int whichProduct();
private:
     int wood;
     int stone;
     int food;
     int gold;

};

#endif // GOODS_H
