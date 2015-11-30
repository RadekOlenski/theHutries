#include "gui.h"

GUI::GUI(int mapWidth,int mapHeight,sf::RenderWindow *hutrieApplication, int width) :  guiFrame(sf::Vector2f(width,mapHeight)),
                                                                                       buildButton(mapWidth + 40, 400, hutrieApplication,"sprites/buttons/hammer.png") ,
                                                                                       hutrieButton(mapWidth + 120, 400, hutrieApplication,"sprites/buttons/hutrie.png"),
                                                                                       barText( 10, mapHeight + 5, 20, sf::Color::White),
                                                                                       guiBar(   0, mapHeight    , hutrieApplication, "sprites/buttons/leather2.png", mapWidth + width, 30),
                                                                                       gold  (  208       , mapHeight , hutrieApplication, "sprites/goods/gold.png" , 30, 30),
                                                                                       wood  (  208 + 192 , mapHeight , hutrieApplication, "sprites/goods/wood.png" , 30, 30),
                                                                                       stone (  208 + 384 , mapHeight , hutrieApplication, "sprites/goods/stone.png", 30, 30),
                                                                                       food  (  208 + 576 , mapHeight , hutrieApplication, "sprites/goods/food.png" , 30, 30)

{
    this->width = width;
    height = mapHeight;
    this->hutrieApplication = hutrieApplication;
    guiFrame.setPosition( mapWidth , 0);
    //guiFrame.setOrigin( -mapWidth , 0);
    //guiFrame.setFillColor(sf::Color::White);
    //guiFrame.setOutlineThickness(1);
    //guiFrame.setOutlineColor(sf::Color::Blue);
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
