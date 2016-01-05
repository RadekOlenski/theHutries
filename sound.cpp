#include "sound.h"
#include <string>
#include <iostream>

using namespace std;

sf::Sound Sound::sound = sound;
sf::SoundBuffer Sound::soundBuffer = soundBuffer;
const string Sound::errorPath = "audio/error.wav";
const string Sound::clickPath = "audio/click.wav";
const string Sound::tingPath = "audio/ting.wav";
const string Sound::notificationPath = "audio/notification.wav";
const string Sound::musicPath = "audio/celtic.wav";
const string Sound::hutrie = "audio/sir.wav";
const string Sound::trees = "audio/trees.wav";
const string Sound::barracks = "audio/barracks.wav";
const string Sound::farm = "audio/farm.wav";
const string Sound::goldmine = "audio/goldmine.wav";
const string Sound::hutrieshall = "audio/castle.wav";
const string Sound::residence = "audio/residence.wav";
const string Sound::sawmill = "audio/saw.wav";
const string Sound::stonecutter = "audio/rock.wav";

void Sound::setSoundBuffer()
{
   sound.setBuffer(soundBuffer);
}

void Sound::error()
{
    Sound::setSoundBuffer();
    soundBuffer.loadFromFile(errorPath);
    sound.play();
}

void Sound::click()
{
    Sound::setSoundBuffer();
    soundBuffer.loadFromFile(clickPath);
    sound.play();
}

void Sound::ting()
{
    Sound::setSoundBuffer();
    soundBuffer.loadFromFile(tingPath);
    sound.play();
}

void Sound::notification()
{
    Sound::setSoundBuffer();
    soundBuffer.loadFromFile(notificationPath);
    sound.play();
}
