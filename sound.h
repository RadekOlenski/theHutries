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

    static void purchaseSound();

    static void reminderSound();

    static void soldierSound();

    static void workerSound();

    static void archerSound();

    static void carrierSound();

    static void notification();

    static const std::string musicPath;
    static const std::string barracks;
    static const std::string farm;
    static const std::string goldmine;
    static const std::string hutrie;
    static const std::string hutrieshall;
    static const std::string residence;
    static const std::string sawmill;
    static const std::string stonecutter;
    static const std::string trees;
    static const std::string mountain;
    static const std::string rocks;
    static const std::string winSound;
    static const std::string loseSound;
    static const std::string introMusic;
    static const std::string menuMusic;
    static const std::string construction;
    static const std::string reminder;

private:

    static sf::Sound sound;
    static sf::SoundBuffer soundBuffer;
    static sf::Sound hutriesSound;
    static sf::SoundBuffer hutriesSoundBuffer;
    static const std::string errorPath;
    static const std::string clickPath;
    static const std::string tingPath;
    static const std::string notificationPath;
    static const std::string purchaseSoundPath;
    static const std::string soldierVoicePath;
    static const std::string archerVoicePath;
    static const std::string workerVoicePath;
    static const std::string carrierVoicePath;
};


#endif //THEHUTRIES_SOUND_H
