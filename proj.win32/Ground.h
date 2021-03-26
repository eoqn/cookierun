#pragma once
#include <cocos2d.h>
USING_NS_CC;
class Ground:public Node
{
//private:

public:
	CREATE_FUNC(Ground);
	bool init();
	
	void update(float dt);
};

