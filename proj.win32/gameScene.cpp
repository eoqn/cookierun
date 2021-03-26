#include "gameScene.h"
#include "cocostudio/CocoStudio.h"
#include "backGround.h"
#include "cookie.h"
#include "Ground.h"
#include "audioManager.h"

bool gameScene::init()
{
	isPause = false;

	audioManager::getIns()->playBGM("sound/Bgm_epN01-1 (1).mp3");

	backGround* back = backGround::create();
	addChild(back);

	Ground* ground = Ground::create();
	addChild(ground);

	cookie* _cookie = cookie::create();
	_cookie->setScale(0.7);
	_cookie->setName("player");
	addChild(_cookie);
	_cookie->setZOrder(100);

	Sprite* jump = Sprite::create("UI2/btn_jump.png");

	this->addChild(jump);
	jump->setPosition(Vec2(100, 80));
	jump->setScale(0.7);
	jump->setOpacity(150);
	Sprite* slide = Sprite::create("UI2/btn_slide.png");

	this->addChild(slide);
	slide->setPosition(Vec2(1020, 80));
	slide->setScale(0.7);
	slide->setOpacity(150);

	EventListenerKeyboard* key = EventListenerKeyboard::create();
	key->onKeyPressed = CC_CALLBACK_2(gameScene::keyPress, this);
	key->onKeyReleased = CC_CALLBACK_2(gameScene::keyRelease, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(key, this);

	Button* stopBtn = Button::create("UI/blue_boxTick.png");
	stopBtn->setScale(1.2);
	stopBtn->pauseSchedulerAndActions();
	stopBtn->setPosition(Vec2(1108, 610));
	addChild(stopBtn);
	stopBtn->addTouchEventListener(CC_CALLBACK_2(gameScene::btnClick, this));

	scheduleUpdate();

	return true;
}

void gameScene::update(float dt)
{

}



void gameScene::keyPress(EventKeyboard::KeyCode key, Event* e)
{
	if (key == EventKeyboard::KeyCode::KEY_F && isPause == false)
	{
		Sprite* outjump = Sprite::create("UI2/btn_jump_dim.png");
		this->addChild(outjump);
		outjump->setPosition(Vec2(100, 80));
		outjump->setScale(0.7);
		outjump->setZOrder(2);
		outjump->setTag(2);
		outjump->setOpacity(150);



	}
	if (key == EventKeyboard::KeyCode::KEY_J && isPause == false)
	{
		Sprite* slider = Sprite::create("UI2/btn_slide_dim.png");
		this->addChild(slider);
		slider->setPosition(Vec2(1020, 80));
		slider->setScale(0.7);
		slider->setZOrder(2);
		slider->setTag(2);
		slider->setOpacity(150);
	}
}

void gameScene::keyRelease(EventKeyboard::KeyCode key, Event* e)
{
	if (key == EventKeyboard::KeyCode::KEY_F && isPause == false) {
		Sprite* outjump = (Sprite*)this->getChildByTag(2);
		outjump->removeFromParent();


	}
	if (key == EventKeyboard::KeyCode::KEY_J && isPause == false) {
		Sprite* slider = (Sprite*)this->getChildByTag(2);
		slider->removeFromParent();
	}
}

void gameScene::btnClick(Ref* ref, Widget::TouchEventType type)
{
	Button* btn = (Button*)ref;
	if (type == Widget::TouchEventType::ENDED) {
		if (Director::getInstance()->isPaused() == false) {
			audioManager::getIns()->pauseBGM();
			Director::getInstance()->pause();
			btn->loadTextureNormal("UI/blue_boxCross.png");
			isPause = true;
		}
		else {
			audioManager::getIns()->resumeBGM();
			Director::getInstance()->resume();
			btn->loadTextureNormal("UI/blue_boxTick.png");
			isPause = false;
		}
	}
}
