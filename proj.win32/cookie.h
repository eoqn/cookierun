#pragma once
#include<cocos2d.h> 
USING_NS_CC;
class cookie:public Node
{
public:
	CREATE_FUNC(cookie);
	bool init();
	void update(float dt);

	void keyPress(EventKeyboard::KeyCode key, Event* e);
	void keyRelease(EventKeyboard::KeyCode key, Event* e);

	int jump;
};