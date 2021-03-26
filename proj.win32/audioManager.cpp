#include "audioManager.h"
static audioManager* obj = NULL;
bool audioManager::init()
{
    volume = 1;

    return true;
}

audioManager* audioManager::getIns()
{
    if (obj == NULL) {
        obj = audioManager::create();
        obj->retain();
    }
    return obj;
}

void audioManager::playBGM(std::string filename)
{
    
    AudioEngine::stop(bgmTag);
    bgmTag = AudioEngine::play2d(filename, true, volume);
    CCLOG("tag:%d", bgmTag);
}

void audioManager::playSE(std::string filename)
{
    AudioEngine::play2d(filename, false, volume);
}

void audioManager::stopBGM()
{
    AudioEngine::stop(bgmTag);
}

void audioManager::setVolume(float f)
{
    volume = f;
    AudioEngine::setVolume(bgmTag, volume);
}

void audioManager::pauseBGM()
{
    AudioEngine::pause(bgmTag);
}

void audioManager::resumeBGM()
{
    AudioEngine::resume(bgmTag);
}
