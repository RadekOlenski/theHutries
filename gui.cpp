#include "gui.h"

GUI::GUI(int mapWidth,int mapHeight,sf::RenderWindow *hutrieApplication, int width) :  guiFrame(sf::Vector2f(width,mapHeight)),
                                                                                       buildButton(mapWidth + 60, 370, hutrieApplication,"sprites/buttons/hammer.png") ,
                                                                                       hutrieButton(mapWidth + 140, 370, hutrieApplication,"sprites/buttons/hutrie.png"),
                                                                                       barText( 10, mapHeight + 5, 20, sf::Color::White),
                                                                                       guiBar(   0, mapHeight    , hutrieApplication, "sprites/buttons/leather2.png", mapWidth + width, 30),
                                                                                       gold  (  208       , mapHeight , hutrieApplication, "sprites/goods/gold.png" , 30, 30),
                                                                                       wood  (  208 + 192 , mapHeight , hutrieApplication, "sprites/goods/wood.png" , 30, 30),
                                                                                       stone (  208 + 384 , mapHeight , hutrieApplication, "sprites/goods/stone.png", 30, 30),
                                                                                       food  (  208 + 576 , mapHeight , hutrieApplication, "sprites/goods/food.png" , 30, 30),
                                                                                       sawmill     (  mapWidth + 30, 440 , hutrieApplication, "sprites/buildings/sawmill.png"    , 90, 90),
                                                                                       stonecutter (  mapWidth + 150, 440 , hutrieApplication, "sprites/buildings/stone.png"     , 90, 90),
                                                                                       barracks    (  mapWidth + 30, 540 , hutrieApplication, "sprites/buildings/barracks.png"   , 90, 90),
                                                                                       residence   (  mapWidth + 150, 540 , hutrieApplication, "sprites/buildings/residence.png" , 90, 90)

{
    this->width = width;
    height = mapHeight;
    this->hutrieApplication = hutrieApplication;
    guiFrame.setPosition( mapWidth , 0);
    texture.loadFromFile("sprites/background/pergamino.jpg");
    guiFrame.setTexture(&texture);
    barText.text.setString("The Hutries: ");
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
    hutrieApplication->draw(barracks.button);
    hutrieApplication->draw(stonecutter.button);
    hutrieApplication->draw(residence.button);
}
