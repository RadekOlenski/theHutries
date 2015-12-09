#include <iostream>

#include "game.h"
#include "unit.h"
#include "mapobject.h"
#include "hutrie.h"
#include "carrier.h"
#include "worker.h"
#include "soldier.h"
#include "building.h"
#include "sawmill.h"
#include "stonecutter.h"
#include "residence.h"
#include "barracks.h"
#include "hutrieshall.h"

Game::Game(int applicationWidth, int applicationHeight) : chosenMode(0),
                                                          tempChosenMode(0),
                                                          hutrieApplication( sf::VideoMode( applicationWidth + 256 ,applicationHeight + 30, 32 ), "The Hutries"),// sf::Style::Fullscreen ),
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
//    backgroundTexture.loadFromFile( "sprites/background/background.jpg" );
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

    sound.setBuffer(buffer);

    pHall = dynamic_cast <HutriesHall *>(world.buildings.at(0));        //rzutowanie hutries hall z vectora building na pelnoprawny object HutriesHall

}

void Game::error()
{
    buffer.loadFromFile("audio/error.wav");
    sound.play();
}

void Game::ting()
{
    buffer.loadFromFile("audio/click.wav");
    sound.setVolume(70);
    sound.play();
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
             chosenMode = 1;                 //HUTRIE BUILDING MODE
             ting();
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2 )
            {
             chosenMode = 2;               //BUILD MODE
             ting();
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F3 )
            {
             chosenMode = 3;                //INFO MODE
             ting();
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4 )
            {
             chosenMode = 4;                //HUTRIE MODE
             ting();
            }
////////////////////// SWITCHING BETWEEN TYPES OF BUILDINGS/////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1 && chosenMode == 2 )
            {
             buildingType = 1;                //SAWMILL
             ting();
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2 && chosenMode == 2 )
            {
             buildingType = 2;                //STONECUTTER
             ting();
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3 && chosenMode == 2 )
            {
             buildingType = 3;                //BARRACKS
             ting();
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4 && chosenMode == 2 )
            {
             buildingType = 4;                //RESIDENCE
             ting();
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                    std::cout<<world.availableSlots << std::endl;
            }

/////////////////////////////OTHER KEYBOARD FEATURES/////////////////////////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                 hutrieApplication.close();

        }

        cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))); //ustawia sprite kursora na pozycji myszki

//////////////////// DEACTIVATING BUTTONS WHILE NOT DRAWN ///////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////// CHECK BUILDING-HUTRIES ACTIONS ///////////////////////////////////////////////////////////////

        if (pHall->getMakeCarrier())
        {
            if (world.availableSlots > 0)
            {
                std::cout << "Utworze dla ciebie Carriera!" << std::endl;
                world.availableSlots --;
            }
            else error();
            pHall->setMakeCarrier(false);
        }

        if (pHall->getMakeWorker())
        {
            if (world.availableSlots > 0)
            {
                std::cout << "Utworze dla ciebie Workera!" << std::endl;
                world.availableSlots --;
            }
            else error();
            pHall->setMakeWorker(false);
        }

        std::vector <Building*>::iterator it;
        for(it = world.buildings.begin(); it != world.buildings.end(); ++it)
        {
          if ( (*it)->getNeedWorker() )
          {
              if((*it)->getHutriesCounter() < (*it)->getCapacity() )                    //jesli aktualna ilosc przebywajacych w budynku mniejsza od pojemnosci
                {
                    int unitIndex = (*it)->getUnitIndex(2);
                    std::vector <Unit*> usedUnits;
                    usedUnits.push_back(world.units.at(unitIndex));
                    world.workers.push_back(new Worker(&hutrieApplication, usedUnits,"sprites/worker/right.png" ));
                    world.hutries.push_back(world.workers.back());
                    world.hutries.back()->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
                    world.units.at(unitIndex)->addHutrie(world.hutries.back());
                    (*it)->setHutriesCounter( (*it)->getHutriesCounter() + 1 );
                    (*it)->showStatus();                                                                //zeby po kliknieciu od razu zaktualizowala sie liczba workerow w GUI

                }
              else error();
              (*it)->setNeedWorker(false);
          }
          if ( (*it)->getNeedCarrier() )
          {
          int unitIndex = (*it)->getUnitIndex(2);                                                     // ktore z pol budynku ma byc zajete przez carriera
          std::vector <Unit*> usedUnits;
          usedUnits.push_back(world.units.at(unitIndex));
          world.carriers.push_back(new Carrier(&hutrieApplication, usedUnits,"sprites/carrier/right.png" ));
          world.hutries.push_back(world.carriers.back());
          world.hutries.back()->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
          world.units.at(unitIndex)->addHutrie(world.hutries.back());
          (*it)->setNeedCarrier(false);
          }

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
            int unitIndex = 70;
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

           if (chosenMode == 1 && !(world.units.at( unitIndex )->isEmpty()))    //poruszanie Hutrim do budynku
            {
                std::vector <Unit*> usedUnits;
                usedUnits.push_back(world.units.at(unitIndex));
                world.hutries.push_back(new Worker(&hutrieApplication, usedUnits,"sprites/worker/right.png" ));
                world.hutries.back()->hutrieThread.launch();                         //tworzy watek w ktorym porusza sie Hutrie
                world.units.at(unitIndex)->addHutrie(world.hutries.back());
            }

           if ( world.units.at( unitIndex )->isEmpty() )                                                 //jesli unit jest wolny, bez zadnego mapobjectu
           {
               switch(chosenMode) //BUTTONS F1,F2,F3 OR GUIBUTTONS
                {

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
                                   case 4:
                                       {
                                           world.availableSlots += 10;
                                           world.buildings.push_back(new Residence(&hutrieApplication, usedUnits,"sprites/buildings/residence.png", buildingType, &(world.availableSlots)));
                                           break;
                                       }
                               }
                               world.buildings.back()->placeOnMap();
                               buffer.loadFromFile("audio/ting.flac");
                               sound.play();
                            }
                            else error();
                        }
                        else error();
                        break;
                    }
                    case 4:     //poruszanie Hutrim
                    {
                        std::vector <Unit*> usedUnits;
                        usedUnits.push_back(world.units.at(unitIndex));
                        world.soldiers.push_back(new Soldier(&hutrieApplication, usedUnits,"sprites/warrior/right.png" ));
                        world.hutries.push_back(world.soldiers.back());
                        world.hutries.back()->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
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
          else if(gui.buildButton.checkBounds())  { chosenMode = 2; ting(); }
          else if(gui.hutrieButton.checkBounds()) { chosenMode = 1; ting(); }
          else if(gui.sawmill.checkBounds()     && gui.sawmill.isActive())      { buildingType = 1; ting(); }
          else if(gui.stonecutter.checkBounds() && gui.stonecutter.isActive())  { buildingType = 2; ting(); }
          else if(gui.barracks.checkBounds()    && gui.barracks.isActive())     { buildingType = 3; ting(); }
          else if(gui.residence.checkBounds()   && gui.residence.isActive())    { buildingType = 4; ting(); }
          else if(world.lastClickedUnit) { world.lastClickedUnit->getMapObject()->buttonAction();}

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
        if (chosenMode == 1) gui.displayGUIHutries(world.hutries.size(), world.carriers.size(), world.workers.size(), world.soldiers.size());
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
            if ( !((*it)->isEmpty()))
            {
                hutrieApplication.draw((*it)->getMapObject()->sprite);          //rysuje obiekty (budynki, przyroda) widoczne na mapie
                if ( (*it)->hutriesNumber() > 0 )
                {
                   for ( int i =0; i < (*it)->hutriesNumber(); i++)             //jesli w wektorze jest jakis hutri
                   {
                       hutrieApplication.draw((*it)->getHutrieIndex(i)->sprite);     //rysuj hutrich z vectora dwellers
                   }
                }

                if ((*it)->getMapObject()->isEmphasize() && chosenMode == 3)            //jesli tryb info rysuj w prawym gui
                {
                   hutrieApplication.draw((*it)->getMapObject()->title.text);
                   hutrieApplication.draw((*it)->getMapObject()->description.text);
                   hutrieApplication.draw((*it)->getMapObject()->descriptionFrame.button);
                   (*it)->getMapObject()->showButtons();
                }
                else (*it)->getMapObject()->deactivateButtons();
            }
        }

///////////////////////////ADD CURSOR SPRITE AND DISPLAY//////////////////////////////////////////////////////

        hutrieApplication.draw(cursor);
        hutrieApplication.display();
//        std::cout << int (clock.getElapsedTime().asSeconds())<< std::endl;
    }

    void Game::deliverGoods (Hutrie * hutrie)
    {

    }
