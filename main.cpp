#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>

#include "hutrie.h"
#include "building.h"
#include "mapobject.h"
#include "unit.h"
#include "gui.h"
#include "guitext.h"


int main()
{
    srand(time(0));

/////////////////////////// DECLARATIONS //////////////////////////////////////////////////////

    std::vector <Hutrie*> hutries;
    std::vector <Building*> buildings;
    int choice = 0;
    sf::Clock clock;
    Unit* lastClickedUnit = NULL;
    const int applicationWidth = 1024;
    const int applicationHeight = 640;

/////////////////////////// CREATING GAME WINDOW AND GUI //////////////////////////////////////////////////////

    GUI gui(applicationWidth,applicationHeight);
    sf::RenderWindow hutrieApplication( sf::VideoMode( applicationWidth + gui.getWidth(),applicationHeight, 32 ), "The Hutries");//,sf::Style::Fullscreen );
    //sf::RenderWindow hutrieApplication( sf::VideoMode::getDesktopMode(), "The Hutries",sf::Style::Fullscreen );
    hutrieApplication.setFramerateLimit(60);

/////////////////////////// HOW MANY RECTANGLES IN X AND Y DIRECTION//////////////////////////////////////////////////////

    int horizontalUnitsCounter = applicationWidth/64;  //jak wszystko w klasach zamien liczbe na rozmiar kwadracika
    int verticalUnitsCounter = applicationHeight/64;  //jak wszystko w klasach zamien liczbe na rozmiar kwadracika

/////////////////////////// CREATING GRID  OF UNITS//////////////////////////////////////////////////////

    std::vector <Unit*> units;
    sf::Vector2f position(0, 0);
    for (int j = 0; j < verticalUnitsCounter; j++)
    {
        for (int i = 0; i < horizontalUnitsCounter ; i++)
        {
            units.push_back(new Unit (position));
            position.x += 64;
        }
        position.y += 64;
        position.x = 0;
    }

/////////////////////////// CREATING BACKGROUND //////////////////////////////////////////////////////

    sf::RectangleShape background (sf::Vector2f(1024,640));
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile( "sprites/background/background.jpg" );
    background.setTexture( &backgroundTexture );

/////////////////////////// CREATING CURSOR //////////////////////////////////////////////////////

    hutrieApplication.setMouseCursorVisible(false);
    sf::View fixed = hutrieApplication.getView();
    //fixed.zoom(2);
    sf::Texture cursorTexture;
    cursorTexture.loadFromFile("sprites/cursor.png");
    sf::Sprite cursor(cursorTexture);

/////////////////////////// TITLE TEXT //////////////////////////////////////////////////////

    GUIText GUIText;
    sf::Thread thread(&GUIText::display, &GUIText);
    thread.launch();

/////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    sf::Music music;
    if (!music.openFromFile("audio/celtic.wav"))
    return -1; // error
    music.setLoop(true);
    music.play();

/////////////////////////// MAIN GAME LOOP //////////////////////////////////////////////////////

    while( hutrieApplication.isOpen() )
    {
        sf::Event event;
        while( hutrieApplication.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                 hutrieApplication.close();

//////////////////////SWITCHING BETWEEN BUILDING AND HUTRIE MODE/////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
            {
             choice = 1;
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2 )
            {
             choice = 2;
            }

/////////////////////////////OTHER KEYBOARD FEATURES/////////////////////////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                 hutrieApplication.close();
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space )
            {
                std::vector <Unit*>::iterator it;                       //sprawdzenie czy informacje miedzy MapObject i Unit s¹ dobrze przekazywane
                for(it = units.begin(); it != units.end(); ++it)
                {
                    if( (*it)->isEmpty()) std::cout<< "empty" << std::endl;
                    else std::cout<< (*it)->getMapObject()->introduceYourSelf << std::endl;
                }
            }
        }

        cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))); //ustawia sprite kursora na pozycji myszki

//////////////////////////////////REAL-TIME MOUSE ACCESS/////////////////////////////////////////////////////////////////////////////////////////

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
              //sf::Vector2f distance = gui.guiFrame.getPosition() - static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication));
              //std::cout << distance.x << "," << distance.y << std::endl;
              //fixed.setCenter(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication)));
              //gui.guiFrame.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))+distance);
            }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& clock.getElapsedTime().asSeconds()>0.5)
        {
            if (sf::Mouse::getPosition(hutrieApplication).x < applicationWidth)         //jesli klikniecie w obrebie mapy
            {

//////////////////////////////////////////STOP EMPHASIZING LAST CLICKED UNIT///////////////////////////////////////////////////////////

             if (lastClickedUnit != NULL )
               {
                   lastClickedUnit->getMapObject()->emphasizeUnits(false);
                   lastClickedUnit->getMapObject()->setEmphasize(false);
               }

///////////////////////////////////////////////////CHOOSING RIGHT UNIT///////////////////////////////////////////////////////////

            std::vector <Unit*>::iterator it;
            int unitIndex = 0;
            for(it = units.begin(); it != units.end(); ++it)
            {
                if(  (*it)->field.getPosition().x                             <= sf::Mouse::getPosition(hutrieApplication).x &&
                    ((*it)->field.getPosition().x + (*it)->field.getSize().x) >= sf::Mouse::getPosition(hutrieApplication).x &&
                     (*it)->field.getPosition().y                             <= sf::Mouse::getPosition(hutrieApplication).y &&
                    ((*it)->field.getPosition().y + (*it)->field.getSize().y) >= sf::Mouse::getPosition(hutrieApplication).y)
                {
                    //std::cout << "Kwadrat: " << std::distance(units.begin(),it) << std::endl;
                    unitIndex = std::distance(units.begin(),it);
                    //sf::Mouse::setPosition( static_cast <sf::Vector2i> ((*it)->field.getPosition()), hutrieApplication );
                    break;
                }
            }
           //std::cout << "Kwadrat: " << std::distance(units.begin(),it) << std::endl;

//////////////////////////////////////////////////////////LEFT MOUSE MAP ACTIONS/////////////////////////////////////////////////////////////////////////

           if ( units.at( unitIndex )->isEmpty() )   //jesli unit jest wolny, bez zadnego mapobjectu
           {
               switch(choice) //klikniecie klawisz F1 lub F2
                {
                    case 1:     //poruszanie Hutrim
                    {
                        std::vector <Unit*> usedUnits;
                        usedUnits.push_back(units.at(unitIndex));
                        hutries.push_back(new Hutrie(&hutrieApplication, usedUnits ));
                        hutries.at(hutries.size()-1)->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
                        break;
                    }
                    case 2:   //postawienie budynku                                                                                                                                   //BUILDING zajmuje 4 pola na mapie!
                    {
                        int buildingField [] = {unitIndex,unitIndex + 1, unitIndex + horizontalUnitsCounter, unitIndex + horizontalUnitsCounter + 1 };           // wpisuje do tablicy indexy Unitow na ktorych bedzie wybudowany Building
                        if ( (buildingField[0] % horizontalUnitsCounter) != horizontalUnitsCounter - 1 && units.at(buildingField[1])->isEmpty() && units.at(buildingField[2])->isEmpty() && units.at(buildingField[3])->isEmpty())
                        {
                            std::vector <Unit*> usedUnits;
                            usedUnits.push_back(units.at(buildingField[0]));
                            usedUnits.push_back(units.at(buildingField[1]));
                            usedUnits.push_back(units.at(buildingField[2]));
                            usedUnits.push_back(units.at(buildingField[3]));
                            buildings.push_back(new Building(&hutrieApplication, usedUnits)); //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
                            buildings.at(buildings.size()-1)->placeOnMap();
                        }
                        break;
                    }
                };
           }
           else

////////////////////////////EMPHASIZE UNIT WITH MAPOBJECT///////////////////////////////////////////////////////////////////////////////////
           {
               units.at(unitIndex)->getMapObject()->emphasizeUnits();
               //units.at(unitIndex)->getMapObject()->showStatus();
               units.at(unitIndex)->getMapObject()->setEmphasize(true);
               lastClickedUnit = units.at(unitIndex);
           }
////////////////////////////RESTART CLOCK WHICH FORBIDS MULTICLICKING///////////////////////////////////////////////////////////////////////////////////
          }
           clock.restart();
        }

/////////////////////////DRAWING INTERFACE, GREEN GRID AND BACKGROUND///////////////////////////

        hutrieApplication.clear( sf::Color::Black );        //czyszczenie ekranu dla pierwszego wyswietlenia
        hutrieApplication.setView(fixed);
        hutrieApplication.draw(gui.guiFrame);
        hutrieApplication.draw( background );
        hutrieApplication.draw(GUIText.text);             //migoczacy tekst tytulowy
        std::vector <Unit*>::iterator it;                  //rysowanie zielonych kratek pOl
        for(it = units.begin(); it != units.end(); ++it)
        {
            hutrieApplication.draw((*it)->field);
        }

///////////////////////////DRAWING MAP OBJECTS//////////////////////////////////////////////////////

        for(it = units.begin(); it != units.end(); ++it)     //rysosowanie wszystkich mapobjectow na mapie - druga petla zeby ruszajacy sie Hutrie byli rysowani nad zielona kratka a nie pod
        {
            if ( !((*it)->isEmpty()) && (*it)->getMapObject()->isActive() )
            {
                hutrieApplication.draw((*it)->getMapObject()->sprite);
                if ((*it)->getMapObject()->isEmphasize()) hutrieApplication.draw((*it)->getMapObject()->description.text);
            }
        }

///////////////////////////ADD CURSOR SPRITE AND DISPLAY//////////////////////////////////////////////////////

        hutrieApplication.draw(cursor);
        hutrieApplication.display();
    }
    return 0;
}
