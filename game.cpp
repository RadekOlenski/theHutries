#include "game.h"
#include <iostream>

Game::Game(int applicationWidth, int applicationHeight) : chosenMode(0), hutrieApplication( sf::VideoMode( applicationWidth + 256 ,applicationHeight + 30, 32 ), "The Hutries", sf::Style::Fullscreen ), gui(applicationWidth,applicationHeight, &hutrieApplication), world(&hutrieApplication, applicationWidth,applicationHeight) , titleThread(&GUIText::display, &titleText)
{
    ///////////////////////SIZE OF MAP SCREEN////////////////////////////////////////////////////////////////////

    this->applicationWidth = applicationWidth;
    this->applicationHeight = applicationHeight;

    /////////////////////////// CREATING GAME WINDOW AND GUI //////////////////////////////////////////////////////

    //hutrieApplication.create( sf::VideoMode( applicationWidth + 256 ,applicationHeight, 32 ), "The Hutries", sf::Style::Fullscreen );
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

//////////////////////SWITCHING BETWEEN BUILDING AND HUTRIE MODE/////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
            {
             chosenMode = 1;
            }
            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2 )
            {
             chosenMode = 2;
            }

/////////////////////////////OTHER KEYBOARD FEATURES/////////////////////////////////////////////////////////////////////////////////////////

            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape )
                 hutrieApplication.close();
//            if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space )
//            {
//                std::vector <Unit*>::iterator it;                       //sprawdzenie czy informacje miedzy MapObject i Unit s¹ dobrze przekazywane
//                for(it = world.units.begin(); it != world.units.end(); ++it)
//                {
//                    if( (*it)->isEmpty()) std::cout<< "empty" << std::endl;
//                    else std::cout<< (*it)->getMapObject()->introduceYourSelf << std::endl;
//                }
//            }
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
                    //std::cout << "Kwadrat: " << std::distance(units.begin(),it) << std::endl;
                    unitIndex = std::distance(world.units.begin(),it);
                    //sf::Mouse::setPosition( static_cast <sf::Vector2i> ((*it)->field.getPosition()), hutrieApplication );
                    break;
                }
            }
           //std::cout << "Kwadrat: " << std::distance(world.units.begin(),it) << std::endl;

//////////////////////////////////////////////////////////LEFT MOUSE MAP ACTIONS/////////////////////////////////////////////////////////////////////////

           if ( world.units.at( unitIndex )->isEmpty() )   //jesli unit jest wolny, bez zadnego mapobjectu
           {
               switch(chosenMode) //klikniecie klawisz F1 lub F2
                {
                    case 1:     //poruszanie Hutrim
                    {
                        std::vector <Unit*> usedUnits;
                        usedUnits.push_back(world.units.at(unitIndex));
                        world.hutries.push_back(new Hutrie(&hutrieApplication, usedUnits ));
                        world.hutries.at(world.hutries.size()-1)->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
                        break;
                    }
                    case 2:   //postawienie budynku                                                                                                                                   //BUILDING zajmuje 4 pola na mapie!
                    {
                        if ( (unitIndex % world.getHorizontalUnitsCounter()) != world.getHorizontalUnitsCounter() - 1)
                        {
                            std::vector <Unit*> usedUnits;
                            world.prepareUnits(unitIndex,2,2,&usedUnits);
                            if(world.isFieldEmpty(usedUnits))
                            {
                               world.buildings.push_back(new Building(&hutrieApplication, usedUnits)); //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
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
               world.units.at(unitIndex)->getMapObject()->emphasizeUnits();
               //world.units.at(unitIndex)->getMapObject()->showStatus();
               world.units.at(unitIndex)->getMapObject()->setEmphasize(true);
               world.units.at(unitIndex)->getMapObject()->soundPlay();
               world.lastClickedUnit = world.units.at(unitIndex);
           }
////////////////////////////BUTTONS ACTIONS///////////////////////////////////////////////////////////////////////////////////
          }
          else if(gui.buildButton.checkBounds()) chosenMode = 2;
          else if(gui.hutrieButton.checkBounds()) chosenMode = 1;

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
        hutrieApplication.draw( background );
        hutrieApplication.draw(titleText.text);             //migoczacy tekst tytulowy
        std::vector <Unit*>::iterator it;                  //rysowanie zielonych kratek pOl
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
                if ((*it)->getMapObject()->isEmphasize()) hutrieApplication.draw((*it)->getMapObject()->description.text);
            }
        }

///////////////////////////ADD CURSOR SPRITE AND DISPLAY//////////////////////////////////////////////////////

        hutrieApplication.draw(cursor);
        hutrieApplication.display();
    }
