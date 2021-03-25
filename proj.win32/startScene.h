#pragma execution_character_set("UTF-8")
#pragma once
#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;
using namespace ui;
class startScene:public Scene
{
public:
	CREATE_FUNC(startScene);
	bool init();

	void btnClick(Ref* ref, Widget::TouchEventType type);
	void btnClick2(Ref* ref, Widget::TouchEventType type);
	void btnClick3(Ref* ref, Widget::TouchEventType type);

	bool BGMstop;
};

