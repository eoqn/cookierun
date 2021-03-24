#pragma once
#include<cocos2d.h>
USING_NS_CC;
class BraveCookie : public Node
{
public:
	CREATE_FUNC(BraveCookie);

	bool init();
	void update(float dt);

	void jump(EventKeyboard::KeyCode key, Event* e);
	

	
};

