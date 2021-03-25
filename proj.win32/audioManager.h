#pragma once
#include <cocos2d.h>
USING_NS_CC;
#include <AudioEngine.h>
using namespace experimental;
class audioManager:public Node
{
private:
	CREATE_FUNC(audioManager);
	bool init();
	int bgmTag;
public:
	static audioManager* getIns();
	void playBGM(std::string filename);
	void playSE(std::string filename);
	void stopBGM();
	float volume;
	void setVolume(float f);
};

