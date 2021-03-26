#pragma once
#include <cocos2d.h>
USING_NS_CC;
class speedplayer:public Node
{
public:
	CREATE_FUNC(speedplayer);
	bool init();
	void update(float dt);
};

