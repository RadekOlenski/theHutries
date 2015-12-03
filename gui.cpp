#include "gui.h"

GUI::GUI(int mapWidth,int mapHeight,sf::RenderWindow *hutrieApplication, int width) :  guiFrame    ( sf::Vector2f(width,mapHeight)),
                                                                                       barText     ( 10, mapHeight + 5, 20, "The Hutries", sf::Color::White),
                                                                                       buildButton ( mapWidth + 60 , 100      , hutrieApplication, "sprites/buttons/hammer.png"),
                                                                                       hutrieButton( mapWidth + 140, 100      , hutrieApplication, "sprites/buttons/hutrie.png"),
                                                                                       guiBar      ( 0             , mapHeight, hutrieApplication, "sprites/buttons/leather2.png"    , mapWidth + width, 30),
                                                                                       gold        ( 208           , mapHeight, hutrieApplication, "sprites/goods/gold.png"          , 30, 30),
                                                                                       wood        ( 208 + 192     , mapHeight, hutrieApplication, "sprites/goods/wood.png"          , 30, 30),
                                                                                       stone       ( 208 + 384     , mapHeight, hutrieApplication, "sprites/goods/stone.png"         , 30, 30),
                                                                                       food        ( 208 + 576     , mapHeight, hutrieApplication, "sprites/goods/food.png"          , 30, 30),
                                                                                       sawmill     ( mapWidth + 30 , 170      , hutrieApplication, "sprites/buildings/sawmill.png"   , 90, 90),
                                                                                       tSawmill    ( mapWidth + 40 , 255      , 20, "Sawmill"),
                                                                                       stonecutter ( mapWidth + 150, 170      , hutrieApplication, "sprites/buildings/stone.png"     , 90, 90),
                                                                                       tStonecutter( mapWidth + 155, 255      , 20, "Stonecutter"),
//                                                                                       callWorker  ( mapWidth + 40 , 400      , hutrieApplication, "sprites/buildings/stone.png"     , 90, 45),
                                                                                       barracks    ( mapWidth + 30 , 300      , hutrieApplication, "sprites/buildings/barracks.png"  , 90, 90),
                                                                                       tBarracks   ( mapWidth + 40 , 385      , 20, "Barracks"),
                                                                                       residence   ( mapWidth + 150, 300      , hutrieApplication, "sprites/buildings/residence.png" , 90, 90),
                                                                                       tResidence  ( mapWidth + 160, 385      , 20, "Residence")

{
    this->width = width;
    height = mapHeight;
    this->hutrieApplication = hutrieApplication;

    guiFrame.setPosition( mapWidth , 0);
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
    hutrieApplication->draw(barText.text);

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
}
