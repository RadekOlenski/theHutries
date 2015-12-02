#include <iostream>

#include "game.h"
#include "hutrie.h"
#include "building.h"
#include "unit.h"
#include "sawmill.h"
#include "stonecutter.h"
#include "residence.h"
#include "barracks.h"

Game::Game(int applicationWidth, int applicationHeight) : chosenMode(0),
                                                          tempChosenMode(0),
                                                          hutrieApplication( sf::VideoMode( applicationWidth + 256 ,applicationHeight + 30, 32 ), "The Hutries", sf::Style::Fullscreen ),
                                                          gui(applicationWidth,applicationHeight, &hutrieApplication),
                                                          world(&hutrieApplication, applicationWidth,applicationHeight) ,
                                                          titleText (1024 +20, 40, 45),
                                                          titleThread(&GUIText::display, &titleText)
{
    ///////////////////////SIZE OF MAP SCREEN////////////////////////////////////////////////////////////////////

    this->applicationWidth = applicationWidth;
    this->applicationHeight = applicationHeight;

    /////////////////////////// CREATING GAME WINDOW AND GUI //////////////////////////////////////////////////////

    //sf::RenderWindow hutrieApplication( sf::VideoMode::getDesktopMode(), "The Hutries",sf::Style::Fullscreen );
    hutrieApplication.setFramerateLimit(60);

    /////////////////////////// CREATING BACKGROUND //////////////////////////////////////////////////////

    background.setSize (sf::Vector2f(1024,640));
    backgroundTexture.loadFromFile( "sprites/background/background.jpg" );
    background.setTexture( &backgroundTexture );

    /////////////////////////// CREATING CURSOR //////////////////////////////////////////////////////

    hutrieApplication.setMouseCursorVisible(false);
      fixed = hutrieApplication.getView();
    //fixed.zoom(2);
    cursorTexture.loadFromFile("sprites/cursor.png");
    cursor.setTexture(cursorTexture);

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile("audio/celtic.wav")) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);

}

void Game::play()
{
    music.play();
    music.setVolume(40);
    titleThread.launch();
    while( hutrieApplication.isOpen() )
    {
        actions();
        displayAll();
    }
}

void Game::actions()
{
    sf::Event event;
        while( hutrieApplication.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                 hutrieApplication.close();

//////////////////////SWITCHING BETWEEN MODES/////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
            {
             chosenMode = 1;                //BUILD MODE
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2 )
            {
             chosenMode = 2;                //HUTRIE MODE
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F3 )
            {
             chosenMode = 3;                //INFO MODE
            }
////////////////////// SWITCHING BETWEEN TYPES OF BUILDINGS/////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1 )
            {
             buildingType = 1;                //SAWMILL
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2 )
            {
             buildingType = 2;                //STONECUTTER
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3 )
            {
             buildingType = 3;                //BARRACKS
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4 )
            {
             buildingType = 4;                //RESIDENCE
            }

/////////////////////////////OTHER KEYBOARD FEATURES/////////////////////////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                 hutrieApplication.close();

        }

        cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))); //ustawia sprite kursora na pozycji myszki

        if (chosenMode != tempChosenMode)
        {
        if (chosenMode == 2) buttonFlag = true;
        else buttonFlag = false;
        gui.sawmill.setActive(buttonFlag);
        gui.stonecutter.setActive(buttonFlag);
        gui.barracks.setActive(buttonFlag);
        gui.residence.setActive(buttonFlag);
        tempChosenMode = chosenMode;
        }

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

             if (world.lastClickedUnit != NULL )
               {
                   world.lastClickedUnit->getMapObject()->emphasizeUnits(false);
                   world.lastClickedUnit->getMapObject()->setEmphasize(false);
                   world.lastClickedUnit->getMapObject()->soundPlay(false);
               }

///////////////////////////////////////////////////CHOOSING RIGHT UNIT///////////////////////////////////////////////////////////

            std::vector <Unit*>::iterator it;
            int unitIndex = 0;
            for(it = world.units.begin(); it != world.units.end(); ++it)
            {
                if(  (*it)->field.getPosition().x                             <= sf::Mouse::getPosition(hutrieApplication).x &&
                    ((*it)->field.getPosition().x + (*it)->field.getSize().x) >= sf::Mouse::getPosition(hutrieApplication).x &&
                     (*it)->field.getPosition().y                             <= sf::Mouse::getPosition(hutrieApplication).y &&
                    ((*it)->field.getPosition().y + (*it)->field.getSize().y) >= sf::Mouse::getPosition(hutrieApplication).y)
                {
                    unitIndex = std::distance(world.units.begin(),it);
                    break;
                }
            }

//////////////////////////////////////////////////////////LEFT MOUSE MAP ACTIONS/////////////////////////////////////////////////////////////////////////

           if ( world.units.at( unitIndex )->isEmpty() )   //jesli unit jest wolny, bez zadnego mapobjectu
           {
               switch(chosenMode) //BUTTONS F1,F2,F3 OR GUIBUTTONS
                {
                    case 1:     //poruszanie Hutrim
                    {
                        std::vector <Unit*> usedUnits;
                        usedUnits.push_back(world.units.at(unitIndex));
                        world.hutries.push_back(new Hutrie(&hutrieApplication, usedUnits,"sprites/carrier/right.png" ));
                        world.hutries.at(world.hutries.size()-1)->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
                        break;
                    }
                    case 2:   //postawienie budynku                                                                                                                                   //BUILDING zajmuje 4 pola na mapie!
                    {
                        if ( (unitIndex % world.getHorizontalUnitsCounter()) != world.getHorizontalUnitsCounter() - 1 && unitIndex < world.getHorizontalUnitsCounter() * (world.getVerticalUnitsCounter()-1))
                        {
                            std::vector <Unit*> usedUnits;
                            world.prepareUnits(unitIndex,2,2,&usedUnits);
                            if(world.isFieldEmpty(usedUnits))
                            {
                               switch(buildingType)                                                                      //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
                               {
                                   case 1: world.buildings.push_back(new Sawmill(&hutrieApplication, usedUnits,"sprites/buildings/sawmill.png" ,buildingType)); break;
                                   case 2: world.buildings.push_back(new StoneCutter(&hutrieApplication, usedUnits,"sprites/buildings/stone.png", buildingType)); break;
                                   case 3: world.buildings.push_back(new Barracks(&hutrieApplication, usedUnits,"sprites/buildings/barracks.png", buildingType)); break;
                                   case 4: world.buildings.push_back(new Residence(&hutrieApplication, usedUnits,"sprites/buildings/residence.png", buildingType)); break;
                               }
                               world.buildings.at(world.buildings.size()-1)->placeOnMap();
                            }
                        }
                        break;
                    }
                };
           }
           else

////////////////////////////EMPHASIZE UNIT WITH MAPOBJECT///////////////////////////////////////////////////////////////////////////////////
           {
               chosenMode = 3;
               world.units.at(unitIndex)->getMapObject()->emphasizeUnits();
               world.units.at(unitIndex)->getMapObject()->showStatus();
               world.units.at(unitIndex)->getMapObject()->setEmphasize(true);
               world.units.at(unitIndex)->getMapObject()->soundPlay();
               world.lastClickedUnit = world.units.at(unitIndex);
           }
////////////////////////////BUTTONS ACTIONS///////////////////////////////////////////////////////////////////////////////////
          }
          else if(gui.buildButton.checkBounds())  chosenMode = 2;
          else if(gui.hutrieButton.checkBounds()) chosenMode = 1;
          else if(gui.sawmill.checkBounds()     && gui.sawmill.isActive())      buildingType = 1;
          else if(gui.stonecutter.checkBounds() && gui.stonecutter.isActive())  buildingType = 2;
          else if(gui.barracks.checkBounds()    && gui.barracks.isActive())     buildingType = 3;
          else if(gui.residence.checkBounds()   && gui.residence.isActive())    buildingType = 4;

////////////////////////////RESTART CLOCK WHICH FORBIDS MULTICLICKING///////////////////////////////////////////////////////////////////////////////////

           clock.restart();
        }
}

void Game::displayAll()
{
    /////////////////////////DRAWING INTERFACE, GREEN GRID AND BACKGROUND///////////////////////////

        hutrieApplication.clear( sf::Color::Black );        //czyszczenie ekranu dla pierwszego wyswietlenia
        hutrieApplication.setView(fixed);
        gui.displayGUI();
        if (chosenMode == 2) gui.displayGUIBuildings();
        hutrieApplication.draw( background );
        hutrieApplication.draw(titleText.text);             //migoczacy tekst tytulowy
        std::vector <Unit*>::iterator it;                  //rysowanie zielonych kratek pol
        for(it = world.units.begin(); it != world.units.end(); ++it)
        {
            hutrieApplication.draw((*it)->field);
        }

///////////////////////////DRAWING MAP OBJECTS//////////////////////////////////////////////////////

        for(it = world.units.begin(); it != world.units.end(); ++it)     //rysosowanie wszystkich mapobjectow na mapie - druga petla zeby ruszajacy sie Hutrie byli rysowani nad zielona kratka a nie pod
        {
            if ( !((*it)->isEmpty()) && (*it)->getMapObject()->isActive() )
            {
                hutrieApplication.draw((*it)->getMapObject()->sprite);
                if ((*it)->getMapObject()->isEmphasize() && chosenMode == 3)
                {
                   hutrieApplication.draw((*it)->getMapObject()->title.text);
                   hutrieApplication.draw((*it)->getMapObject()->description.text);
                   hutrieApplication.draw((*it)->getMapObject()->descriptionFrame.button);
                }
            }
        }

///////////////////////////ADD CURSOR SPRITE AND DISPLAY//////////////////////////////////////////////////////

        hutrieApplication.draw(cursor);
        hutrieApplication.display();
    }
