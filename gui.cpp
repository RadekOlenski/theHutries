#include <sstream>
#include "gui.h"

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
        tfood(280 + 384, mapHeight + 2, 20, "0", sf::Color::White),
        tstone(280 + 576, mapHeight + 2, 20, "0", sf::Color::White),
        sawmill(mapWidth + 30, 170, hutrieApplication, "sprites/buildings/sawmill.png", 90, 90),
        tSawmill(mapWidth + 40, 255, 20, "Sawmill"),
        stonecutter(mapWidth + 150, 170, hutrieApplication, "sprites/buildings/stone.png", 90, 90),
        tStonecutter(mapWidth + 155, 255, 20, "Stonecutter"),
        goldmine(mapWidth + 30, 420, hutrieApplication, "sprites/buildings/goldmine/goldmineGUI.png", 90, 90),
        tGoldmine(mapWidth + 40, 505, 20, "Goldmine"),
        farm(mapWidth + 150, 420, hutrieApplication, "sprites/buildings/goldmine/goldmineGUI.png", 90, 90),
        tFarm(mapWidth + 155, 505, 20, "Farm"),
        barracks(mapWidth + 30, 300, hutrieApplication, "sprites/buildings/barracks.png", 90, 90),
        tBarracks(mapWidth + 40, 385, 20, "Barracks"),
        residence(mapWidth + 150, 300, hutrieApplication, "sprites/buildings/residence.png", 90, 90),
        tResidence(mapWidth + 160, 385, 20, "Residence"),
        allHutries(mapWidth + 30, 170, hutrieApplication, "sprites/all.png", 96, 96),
        tHutries(mapWidth + 150, 200, 30, "26"),
        allCarriers(mapWidth + 30, 270, hutrieApplication, "sprites/carrier/right.png", 96, 96),
        tCarriers(mapWidth + 150, 300, 30, "12"),
        allWorkers(mapWidth + 30, 370, hutrieApplication, "sprites/worker/right.png", 96, 96),
        tWorkers(mapWidth + 150, 400, 30, "5"),
        allSoldiers(mapWidth + 30, 470, hutrieApplication, "sprites/warrior/right.png", 96, 96),
        tSoldiers(mapWidth + 150, 500, 30, "2")
{

    this->width = width;
    height = mapHeight;
    this->hutrieApplication = hutrieApplication;

    guiFrame.setPosition(mapWidth, 0);
    texture.loadFromFile("sprites/background/pergamino.jpg");
    guiFrame.setTexture(&texture);

    buildButton.setActive(true);
    hutrieButton.setActive(true);
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
    hutrieApplication->draw(barracks.button);
    hutrieApplication->draw(tBarracks.text);
    hutrieApplication->draw(stonecutter.button);
    hutrieApplication->draw(tStonecutter.text);
    hutrieApplication->draw(residence.button);
    hutrieApplication->draw(tResidence.text);
    hutrieApplication->draw(goldmine.button);
    hutrieApplication->draw(tGoldmine.text);
    hutrieApplication->draw(farm.button);
    hutrieApplication->draw(tFarm.text);

}

void GUI::displayGUIHutries(int hutrieSize, int carrierSize, int workerSize, int soldierSize)
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
    desc3 << soldierSize;
    tSoldiers.text.setString(desc3.str());


    hutrieApplication->draw(allHutries.button);
    hutrieApplication->draw(allCarriers.button);
    hutrieApplication->draw(allWorkers.button);
    hutrieApplication->draw(allSoldiers.button);
    hutrieApplication->draw(tHutries.text);
    hutrieApplication->draw(tWorkers.text);
    hutrieApplication->draw(tCarriers.text);
    hutrieApplication->draw(tSoldiers.text);

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

