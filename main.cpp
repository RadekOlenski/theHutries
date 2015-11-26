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

class TitleText
{
public:
    TitleText();
    sf:: Text text;
    sf::Font font;
    void display();
};

TitleText::TitleText()
{
    font.loadFromFile("prince_valiant.ttf");
    text.setFont(font);
    text.setCharacterSize(45);      //60
    text.setStyle(sf::Text::Bold);
    text.setPosition(1024 + 20,40);
    text.setColor(sf::Color::Black);
}

void TitleText::display()
{
    while(1)
    {

      text.setString("The");
      sf::sleep(sf::seconds(2));
      text.setPosition(text.getPosition().x + 88 , text.getPosition().y);  //116
      text.setString("Hutries");
      sf::sleep(sf::seconds(2));
      text.setPosition(text.getPosition().x - 88, text.getPosition().y);   //116
      text.setString("The Hutries");
      sf::sleep(sf::seconds(2));
    }
}
int main()
{
    srand(time(0));
    std::vector <Hutrie*> hutries;
    std::vector <Building*> buildings;
    int choice = 0, i = 0, j=0;
    const int applicationWidth = 1024;
    const int applicationHeight = 640;
    GUI gui(applicationWidth,applicationHeight);
    sf::RenderWindow hutrieApplication( sf::VideoMode( applicationWidth + gui.getWidth(),applicationHeight, 32 ), "The Hutries");//,sf::Style::Fullscreen );
    //sf::RenderWindow hutrieApplication( sf::VideoMode::getDesktopMode(), "The Hutries",sf::Style::Fullscreen );
    hutrieApplication.setFramerateLimit(60);
    hutrieApplication.setMouseCursorVisible(false);
    sf::View fixed = hutrieApplication.getView();
    //fixed.zoom(2);


    int horizontalUnitsCounter = applicationWidth/64;  //jak wszystko w klasach zamien liczbe na rozmiar kwadracika
    int verticalUnitsCounter = applicationHeight/64;  //jak wszystko w klasach zamien liczbe na rozmiar kwadracika
    std::vector <Unit*> units;
    sf::Vector2f position(0, 0);
    int counter = 0;
    for (int j = 0; j < verticalUnitsCounter; j++)
    {
        for (int i = 0; i < horizontalUnitsCounter ; i++)
        {
        units.push_back(new Unit (position));
        position.x += 64;
        counter++;
        }
        position.y += 64;
        position.x = 0;
    }

    Hutrie hut(&hutrieApplication, units.at(0));
    hut.sprite.setTexture( hut.texture );
    hut.sprite.setOrigin( 65, 75 );
    hut.sprite.setPosition( 420, 120 );

    sf::RectangleShape background (sf::Vector2f(1024,640));
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile( "background.jpg" );
    background.setTexture( &backgroundTexture );

    sf::Texture cursorTexture;
    cursorTexture.loadFromFile("sprites/cursor.png");
    sf::Sprite cursor(cursorTexture);

    TitleText titleText;
    sf::Thread thread(&TitleText::display, &titleText);
    thread.launch();

    sf::Clock clock;

    sf::Music music;
    if (!music.openFromFile("celtic.wav"))
    return -1; // error
    music.setLoop(true);
    music.play();

    while( hutrieApplication.isOpen() )
    {
        sf::Event zdarzenie;
        while( hutrieApplication.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 hutrieApplication.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::F1)
            {
             choice = 1;
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::F2 )
            {
             choice = 2;
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
            {
                hut.texture.loadFromFile( "sprites/carrier/up.png" );
                 hut.sprite.setTexture( hut.texture );
                 hut.sprite.move(0,-15);;
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
             {
                hut.texture.loadFromFile( "sprites/carrier/down.png" );
                 hut.sprite.setTexture( hut.texture );
                 hut.sprite.move(0,15);
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Q )  hut.sprite.move(-15,-15);;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::E )  hut.sprite.move(15,-15);;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right )
             {
                hut.texture.loadFromFile( "sprites/carrier/right.png" );
                 hut.sprite.setTexture( hut.texture );
                 hut.sprite.move(15,0);
            }

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left )
             {
                 hut.texture.loadFromFile( "sprites/carrier/left.png" );
                 hut.sprite.setTexture( hut.texture );
                 hut.sprite.move(-15,0);
            }

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 hutrieApplication.close();
            /*if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Space )
            {
                std::vector <Unit*>::iterator it;
                for(it = units.begin(); it != units.end(); ++it)
                {
                    if( (*it)->isEmpty()) std::cout<< "empty" << std::endl;
                    else std::cout<< "full" << std::endl;
                }
            }*/

            /*
           if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left )
            {
            }
            */
        }

        cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))); //ustawia obrazek kursora

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
              sf::Vector2f distance = gui.guiFrame.getPosition() - static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication));
              std::cout << distance.x << "," << distance.y << std::endl;
              fixed.setCenter(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication)));
              //gui.guiFrame.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))+distance);
            }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& clock.getElapsedTime().asSeconds()>0.5)
        {
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

           if ( units.at( unitIndex )->isEmpty() )
           {
               switch(choice)
                {
                    case 1:
                    {
                        hutries.push_back(new Hutrie(&hutrieApplication, units.at(unitIndex)));
                        std::cout << "i: " << i+1 << std::endl;
                        std::cout << "vector.size: " << hutries.size() << std::endl;
                        i++;
                        hutries.at(i-1)->hutrieThread.launch();
                            break;
                    }
                    case 2:                                                                                                                                      //BUILDING zajmuje 4 pola na mapie!
                    {
                        int buildingField [] = {unitIndex,unitIndex + 1, unitIndex + horizontalUnitsCounter, unitIndex + horizontalUnitsCounter + 1 };           // wpisuje do tablicy indexy Unitow na ktorych bedzie wybudowany Building
                        if ( units.at(buildingField[1])->isEmpty() && units.at(buildingField[2])->isEmpty() && units.at(buildingField[3])->isEmpty())
                        { //buildingField[1] <= horizontalUnitsCounter &&
                            buildings.push_back(new Building(&hutrieApplication,units.at(buildingField[0]),units.at(buildingField[1]),units.at(buildingField[2] ),units.at(buildingField[3]))); //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
                            buildings.at(j)->placeOnMap();
                            j++;
                        }
                        break;
                    }
                };
           }
           clock.restart();
        }

// RYSOWANIE

        hutrieApplication.clear( sf::Color::Black );        //czyszczenie ekranu dla pierwszego wyswietlenia
        hutrieApplication.setView(fixed);
        hutrieApplication.draw(gui.guiFrame);
        hutrieApplication.draw( background );
        std::vector <Unit*>::iterator it3;                  //rysowanie zielonych kratek pól
        for(it3 = units.begin(); it3 != units.end(); ++it3)
        {
            hutrieApplication.draw((*it3)->field);
        }
        hutrieApplication.draw(titleText.text);             //migoczacy tekst tytulowy
         std::vector <Building*>::iterator it2;              //rysowanie aktywnych budynkow
        for(it2 = buildings.begin(); it2 != buildings.end(); ++it2)
        {
            hutrieApplication.draw((*it2)->sprite);
        }
        hutrieApplication.draw(  hut.sprite );              //rysowanie hutriego na strzalki
        std::vector <Hutrie*>::iterator it;                 //rysowanie aktywnych Hutrich
        for(it = hutries.begin(); it != hutries.end(); ++it)
        {
            hutrieApplication.draw((*it)->sprite);
        }
        hutrieApplication.draw(cursor);
        hutrieApplication.display();
    }
    return 0;
}
