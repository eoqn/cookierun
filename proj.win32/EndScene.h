#pragma once
#include <cocos2d.h>
USING_NS_CC;
class EndScene :public Scene
{
public:
	CREATE_FUNC(EndScene);

	bool init();
	void update(float dt);

	void Return(EventKeyboard::KeyCode key, Event* e);

};

