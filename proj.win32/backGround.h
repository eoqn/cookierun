#pragma once
#include "cocos2d.h"
USING_NS_CC;
class backGround:public Node
{
public:
	CREATE_FUNC(backGround);
	bool init();

	void update(float dt);
};

