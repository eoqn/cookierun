#pragma execution_character_set("UTF-8")
#pragma once
#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;
using namespace ui;
class gameScene:public Scene
{
public:
	CREATE_FUNC(gameScene);
	bool init();
	void update(float dt);
	bool isPause;

	void keyPress(EventKeyboard::KeyCode key, Event* e);
	void keyRelease(EventKeyboard::KeyCode key, Event* e);
	void btnClick(Ref* ref, Widget::TouchEventType type);
};
