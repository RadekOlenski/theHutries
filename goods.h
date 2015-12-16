#ifndef GOODS_H
#define GOODS_H


class Goods
{
    public:
        Goods();
        Goods(int wood, int food, int gold, int stone);
        int getWood() {return wood;};
        int getGold() {return gold;};
        int getFood() {return food;};
        int getStone() {return stone;};
        void setProduct(int choice, int howMany = 0);
        bool isEmpty();
        Goods operator +( const Goods & goods );
    private:
        unsigned int wood;
        unsigned int stone;
        unsigned int food;
        unsigned int gold;

};

#endif // GOODS_H
