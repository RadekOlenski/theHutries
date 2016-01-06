#include <sstream>
#include "gui.h"
#include "gamebalance.h"

GUI::GUI(int mapWidth, int mapHeight, sf::RenderWindow* hutrieApplication, int width) :
        guiFrame(sf::Vector2f(width, mapHeight)),
        timeLeft(20, mapHeight + 2, 20, "15:00", sf::Color::White),
        errorInfo(970, mapHeight + 2, 20, "Error:", sf::Color::White),
        buildButton(mapWidth + 60, 100, hutrieApplication, "sprites/buttons/hammer.png"),
        hutrieButton(mapWidth + 140, 100, hutrieApplication, "sprites/buttons/hutrie.png"),
        guiBar(0, mapHeight, hutrieApplication, "sprites/buttons/leather2.png", mapWidth + width, 30),
        gold(208, mapHeight, hutrieApplication, "sprites/goods/gold.png", 30, 30),
        wood(208 + 192, mapHeight, hutrieApplication, "sprites/goods/wood.png", 30, 30),
        stone(208 + 384, mapHeight, hutrieApplication, "sprites/goods/stone.png", 30, 30),
        food(208 + 576, mapHeight, hutrieApplication, "sprites/goods/food.png", 30, 30),
        tgold(280, mapHeight + 2, 20, "0", sf::Color::White),
        twood(280 + 192, mapHeight + 2, 20, "0", sf::Color::White),
        tstone(280 + 384, mapHeight + 2, 20, "0", sf::Color::White),
        tfood(280 + 576, mapHeight + 2, 20, "0", sf::Color::White),

        sawmill(mapWidth + 30, 170, hutrieApplication, "sprites/buildings/sawmill.png", 90, 90),
        tSawmill(mapWidth + 40, 260, 20, "Sawmill"),
        woodSawmill(mapWidth + 35, 290, hutrieApplication, "sprites/goods/wood.png", 25, 25),
        twoodSawmill(mapWidth + 60, 290, 20, "3"),
        stoneSawmill(mapWidth + 80, 290, hutrieApplication, "sprites/goods/stone.png", 25, 25),
        tstoneSawmill(mapWidth + 105, 290, 20, "3"),

        stonecutter(mapWidth + 30 + 120, 170, hutrieApplication, "sprites/buildings/stonecutterHut.png", 90, 90),
        tStonecutter(mapWidth + 155, 260, 20, "Stonecutter"),
        woodStonecutter(mapWidth + 35 + 120, 290, hutrieApplication, "sprites/goods/wood.png", 25, 25),
        twoodStonecutter(mapWidth + 60 + 120, 290, 20, "3"),
        stoneStonecutter(mapWidth + 80 + 120, 290, hutrieApplication, "sprites/goods/stone.png", 25, 25),
        tstoneStonecutter(mapWidth + 105 + 120, 290, 20, "3"),

        farm(mapWidth + 30, 330, hutrieApplication, "sprites/buildings/farmGUI.png", 90, 90),
        tFarm(mapWidth + 40, 420, 20, "Farm"),
        woodFarm(mapWidth + 35, 290 + 160, hutrieApplication, "sprites/goods/wood.png", 25, 25),
        twoodFarm(mapWidth + 60, 290 + 160, 20, "3"),
        stoneFarm(mapWidth + 80, 290 + 160,  hutrieApplication, "sprites/goods/stone.png", 25, 25),
        tstoneFarm(mapWidth + 105, 290 + 160, 20, "3"),

        goldmine(mapWidth + 150, 330, hutrieApplication, "sprites/buildings/goldmine/goldmineGUI.png", 90, 90),
        tGoldmine(mapWidth + 155, 420, 20, "Goldmine"),
        woodGoldmine(mapWidth + 35 + 120, 290 + 160, hutrieApplication, "sprites/goods/wood.png", 25, 25),
        twoodGoldmine(mapWidth + 60 + 120, 290 + 160, 20, "3"),
        stoneGoldmine(mapWidth + 80 + 120, 290 + 160, hutrieApplication, "sprites/goods/stone.png", 25, 25),
        tstoneGoldmine(mapWidth + 105 + 120, 290 + 160, 20, "3"),

        barracks(mapWidth + 30, 480, hutrieApplication, "sprites/buildings/barracks.png", 90, 90),
        tBarracks(mapWidth + 40, 565, 20, "Barracks"),
        woodBarracks(mapWidth + 35, 290 + 305, hutrieApplication, "sprites/goods/wood.png", 25, 25),
        twoodBarracks(mapWidth + 60, 290 + 305, 20, "3"),
        stoneBarracks(mapWidth + 80, 290 + 305, hutrieApplication, "sprites/goods/stone.png", 25, 25),
        tstoneBarracks(mapWidth + 105, 290 + 305, 20, "3"),

        residence(mapWidth + 150, 480, hutrieApplication, "sprites/buildings/residence.png", 90, 90),
        tResidence(mapWidth + 160, 565, 20, "Residence"),
        woodResidence(mapWidth + 35 + 120, 290 + 305, hutrieApplication, "sprites/goods/wood.png", 25, 25),
        twoodResidence(mapWidth + 60 + 120, 290 + 305, 20, "3"),
        stoneResidence(mapWidth + 80 + 120, 290 + 305, hutrieApplication, "sprites/goods/stone.png", 25, 25),
        tstoneResidence(mapWidth + 105 + 120, 290 + 305, 20, "3"),

        allHutries(mapWidth + 30, 170, hutrieApplication, "sprites/all.png", 96, 96),
        tHutries(mapWidth + 150, 200, 30, "26"),
        allCarriers(mapWidth + 30, 260, hutrieApplication, "sprites/carrier/right.png", 96, 96),
        tCarriers(mapWidth + 150, 290, 30, "12"),
        allWorkers(mapWidth + 30, 350, hutrieApplication, "sprites/worker/right.png", 96, 96),
        tWorkers(mapWidth + 150, 380, 30, "5"),
        allWarriors(mapWidth + 30, 440, hutrieApplication, "sprites/warrior/right.png", 96, 96),
        tWarriors(mapWidth + 150, 470, 30, "2"),
        allArchers(mapWidth + 30, 530, hutrieApplication, "sprites/archer/right.png", 96, 96),
        tArchers(mapWidth + 150, 560, 30, "2")
{

    this->width = width;
    height = mapHeight;
    this->hutrieApplication = hutrieApplication;

    guiFrame.setPosition(mapWidth, 0);
    texture.loadFromFile("sprites/background/pergamino.jpg");
    guiFrame.setTexture(&texture);

    buildButton.setActive(true);
    hutrieButton.setActive(true);

    setBuildingsCosts();
}

void GUI::displayGUI()
{
    hutrieApplication->draw(guiFrame);
    hutrieApplication->draw(buildButton.button);
    hutrieApplication->draw(hutrieButton.button);

    hutrieApplication->draw(guiBar.button);
    hutrieApplication->draw(wood.button);
    hutrieApplication->draw(gold.button);
    hutrieApplication->draw(stone.button);
    hutrieApplication->draw(food.button);
    hutrieApplication->draw(timeLeft.text);
    hutrieApplication->draw(tgold.text);
    hutrieApplication->draw(twood.text);
    hutrieApplication->draw(tfood.text);
    hutrieApplication->draw(tstone.text);
    hutrieApplication->draw(errorInfo.text);

}

void GUI::displayGUIBuildings()
{
    hutrieApplication->draw(sawmill.button);
    hutrieApplication->draw(tSawmill.text);
    hutrieApplication->draw(woodSawmill.button);
    hutrieApplication->draw(twoodSawmill.text);
    hutrieApplication->draw(stoneSawmill.button);
    hutrieApplication->draw(tstoneSawmill.text);
    hutrieApplication->draw(barracks.button);
    hutrieApplication->draw(tBarracks.text);
    hutrieApplication->draw(woodBarracks.button);
    hutrieApplication->draw(twoodBarracks.text);
    hutrieApplication->draw(stoneBarracks.button);
    hutrieApplication->draw(tstoneBarracks.text);
    hutrieApplication->draw(stonecutter.button);
    hutrieApplication->draw(tStonecutter.text);
    hutrieApplication->draw(woodStonecutter.button);
    hutrieApplication->draw(twoodStonecutter.text);
    hutrieApplication->draw(stoneStonecutter.button);
    hutrieApplication->draw(tstoneStonecutter.text);
    hutrieApplication->draw(residence.button);
    hutrieApplication->draw(tResidence.text);
    hutrieApplication->draw(woodResidence.button);
    hutrieApplication->draw(twoodResidence.text);
    hutrieApplication->draw(stoneResidence.button);
    hutrieApplication->draw(tstoneResidence.text);
    hutrieApplication->draw(goldmine.button);
    hutrieApplication->draw(tGoldmine.text);
    hutrieApplication->draw(woodGoldmine.button);
    hutrieApplication->draw(twoodGoldmine.text);
    hutrieApplication->draw(stoneGoldmine.button);
    hutrieApplication->draw(tstoneGoldmine.text);
    hutrieApplication->draw(farm.button);
    hutrieApplication->draw(tFarm.text);
    hutrieApplication->draw(woodFarm.button);
    hutrieApplication->draw(twoodFarm.text);
    hutrieApplication->draw(stoneFarm.button);
    hutrieApplication->draw(tstoneFarm.text);

}

void GUI::displayGUIHutries(int hutrieSize, int carrierSize, int workerSize, int warriorSize, int archerSize)
{
    std::ostringstream desc;
    desc << hutrieSize;
    tHutries.text.setString(desc.str());
    std::ostringstream desc1;
    desc1 << carrierSize;
    tCarriers.text.setString(desc1.str());
    std::ostringstream desc2;
    desc2 << workerSize;
    tWorkers.text.setString(desc2.str());
    std::ostringstream desc3;
    desc3 << warriorSize;
    tWarriors.text.setString(desc3.str());
    std::ostringstream desc4;
    desc4 << archerSize;
    tArchers.text.setString(desc4.str());


    hutrieApplication->draw(allHutries.button);
    hutrieApplication->draw(allCarriers.button);
    hutrieApplication->draw(allWorkers.button);
    hutrieApplication->draw(allWarriors.button);
    hutrieApplication->draw(allArchers.button);
    hutrieApplication->draw(tHutries.text);
    hutrieApplication->draw(tWorkers.text);
    hutrieApplication->draw(tCarriers.text);
    hutrieApplication->draw(tWarriors.text);
    hutrieApplication->draw(tArchers.text);

}

void GUI::setBuildingsCosts()
{
    std::ostringstream desc;
    desc << GameBalance::sawmillCost.getWood();
    twoodSawmill.text.setString(desc.str());
    std::ostringstream desc1;
    desc1 << GameBalance::sawmillCost.getStone();
    tstoneSawmill.text.setString(desc1.str());

    std::ostringstream desc2;
    desc2 << GameBalance::stonecutterhutCost.getWood();
    twoodStonecutter.text.setString(desc2.str());
    std::ostringstream desc3;
    desc3 << GameBalance::stonecutterhutCost.getStone();
    twoodStonecutter.text.setString(desc3.str());

    std::ostringstream desc4;
    desc4 << GameBalance::farmCost.getWood();
    twoodFarm.text.setString(desc4.str());
    std::ostringstream desc5;
    desc5 << GameBalance::farmCost.getStone();
    tstoneFarm.text.setString(desc5.str());

    std::ostringstream desc6;
    desc6 << GameBalance::goldmineCost.getWood();
    twoodGoldmine.text.setString(desc6.str());
    std::ostringstream desc7;
    desc7 << GameBalance::goldmineCost.getStone();
    tstoneGoldmine.text.setString(desc7.str());

    std::ostringstream desc8;
    desc8<< GameBalance::residenceCost.getWood();
    twoodResidence.text.setString(desc8.str());
    std::ostringstream desc9;
    desc9 << GameBalance::residenceCost.getStone();
    tstoneResidence.text.setString(desc9.str());

    std::ostringstream desc10;
    desc10 << GameBalance::barracksCost.getWood();
    twoodBarracks.text.setString(desc10.str());
    std::ostringstream desc11;
    desc11 << GameBalance::barracksCost.getStone();
    tstoneBarracks.text.setString(desc11.str());
}

void GUI::displayEndingText(bool win)
{
    if (win)
    {
        GUIText win(300, 100, 80, "You Win!!!", sf::Color::Black);
        hutrieApplication->draw(win.text);
    }
    else
    {
        GUIText lose(300, 100, 80, "You Lose!!!", sf::Color::Black);
        hutrieApplication->draw(lose.text);
    }

}

