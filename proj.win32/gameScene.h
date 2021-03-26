#pragma execution_character_set("UTF-8")
#pragma once
#include <cocos2d.h>
USING_NS_CC;
class gameScene:public Scene
{
public:
	CREATE_FUNC(gameScene);
	bool init();
	void update(float dt);

	void keyPress(EventKeyboard::KeyCode key, Event* e);
};

