#ifndef THEHUTRIES_SOUND_H
#define THEHUTRIES_SOUND_H

#include <string>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

class Sound
{

public:

    static void setSoundBuffer();

    static void error();

    static void click();

    static void ting();

    static const std::string musicPath;
    static const std::string barracks;
    static const std::string trees;
    static const std::string farm;
    static const std::string goldmine;
    static const std::string hutrie;
    static const std::string hutrieshall;
    static const std::string residence;
    static const std::string sawmill;
    static const std::string stonecutter;

private:
    static sf::Sound sound;
    static sf::SoundBuffer soundBuffer;
    static const std::string errorPath;
    static const std::string clickPath;
    static const std::string tingPath;
};


#endif //THEHUTRIES_SOUND_H
