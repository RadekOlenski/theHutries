#ifndef GOODS_H
#define GOODS_H


class Goods
{
    public:
        Goods();
        int getWood() {return wood;};
        int getGold() {return gold;};
        int getFood() {return food;};
        int getStone() {return stone;};
        void addProduct(int choice, int howMany);
    private:
        unsigned int wood;
        unsigned int stone;
        unsigned int food;
        unsigned int gold;

};

#endif // GOODS_H
