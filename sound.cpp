#include "sound.h"
#include <string>
#include <iostream>

using namespace std;

sf::Sound Sound::sound = sound;
sf::SoundBuffer Sound::soundBuffer = soundBuffer;
const string Sound::errorPath = "audio/error.flac";
const string Sound::clickPath = "audio/click.flac";
const string Sound::tingPath = "audio/ting.flac";
const string Sound::notificationPath = "audio/notification.flac";
const string Sound::musicPath = "audio/celtic.flac";
const string Sound::hutrie = "audio/sir.flac";
const string Sound::barracks = "audio/barracks.flac";
const string Sound::farm = "audio/farm.flac";
const string Sound::goldmine = "audio/goldmine.flac";
const string Sound::hutrieshall = "audio/castle.flac";
const string Sound::residence = "audio/residence.flac";
const string Sound::sawmill = "audio/saw.flac";
const string Sound::stonecutter = "audio/stonecutter.flac";
const string Sound::trees = "audio/trees.flac";
const string Sound::mountain = "audio/mountain.flac";
const string Sound::rocks = "audio/rocks.flac";
const string Sound::winSound = "audio/winSound.flac";
const string Sound::loseSound = "audio/loseSound.flac";
const string Sound::menuMusic = "audio/intro.flac";
const string Sound::introMusic = "audio/warHorn.flac";


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
    sound.setVolume(30);
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
