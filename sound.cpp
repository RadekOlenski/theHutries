#include "sound.h"
#include "gamebalance.h"

using namespace std;

sf::Sound Sound::sound = sound;
sf::SoundBuffer Sound::soundBuffer = soundBuffer;
sf::Sound Sound::hutriesSound = hutriesSound;
sf::SoundBuffer Sound::hutriesSoundBuffer = hutriesSoundBuffer;
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
const string Sound::construction = "audio/construction.flac";
const string Sound::purchaseSoundPath = "audio/purchase.flac";
const string Sound::soldierVoicePath = "audio/soldier_voice.flac";
const string Sound::workerVoicePath = "audio/worker_voice.flac";
const string Sound::archerVoicePath = "audio/archer_voice.flac";
const string Sound::carrierVoicePath = "audio/carrier_voice.flac";
const string Sound::reminder = "audio/churchbell.wav";


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
    sound.setVolume(GameBalance::sfxVolume);
    sound.play();
}

void Sound::ting()
{
    Sound::setSoundBuffer();
    soundBuffer.loadFromFile(tingPath);
    sound.play();
}

void Sound::purchaseSound()
{
    Sound::setSoundBuffer();
    soundBuffer.loadFromFile(purchaseSoundPath);
    sound.setVolume(GameBalance::sfxVolume);
    sound.play();
}

void Sound::soldierSound()
{
    hutriesSound.setBuffer(hutriesSoundBuffer);
    hutriesSoundBuffer.loadFromFile(soldierVoicePath);
    hutriesSound.setVolume(GameBalance::sfxVolume);
    hutriesSound.play();
}

void Sound::workerSound()
{
    hutriesSound.setBuffer(hutriesSoundBuffer);
    hutriesSoundBuffer.loadFromFile(workerVoicePath);
    hutriesSound.setVolume(GameBalance::sfxVolume);
    hutriesSound.play();
}

void Sound::carrierSound()
{
    hutriesSound.setBuffer(hutriesSoundBuffer);
    hutriesSoundBuffer.loadFromFile(carrierVoicePath);
    hutriesSound.setVolume(GameBalance::sfxVolume);
    hutriesSound.play();
}

void Sound::archerSound()
{
    hutriesSound.setBuffer(hutriesSoundBuffer);
    hutriesSoundBuffer.loadFromFile(archerVoicePath);
    hutriesSound.setVolume(GameBalance::sfxVolume);
    hutriesSound.play();
}

void Sound::notification()
{
    Sound::setSoundBuffer();
    soundBuffer.loadFromFile(notificationPath);
    sound.play();
}

