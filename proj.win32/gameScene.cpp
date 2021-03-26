#include "gameScene.h"
#include "backGround.h"
#include "BraveCookie.h"
#include "Ground.h"

bool gameScene::init()
{
	backGround* back = backGround::create();
	addChild(back);

	Ground* ground = Ground::create();
	addChild(ground);

	BraveCookie* cookie = BraveCookie::create();
	cookie->setScale(0.5);
	cookie->setTag(1);
	addChild(cookie);
	cookie->setPosition(Vec2(100, 100));

	EventListenerKeyboard* key = EventListenerKeyboard::create();
	key->onKeyPressed = CC_CALLBACK_2(gameScene::keyPress, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(key, this);

	scheduleUpdate();

	return true;
}

void gameScene::update(float dt)
{
	
}



void gameScene::keyPress(EventKeyboard::KeyCode key, Event* e)
{
	
}
