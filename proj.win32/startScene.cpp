#include "startScene.h"
#include "gameScene.h"
#include "EndScene.h"
#include "audioManager.h"
//1138, 640
bool startScene::init()
{
	BGMstop = false;
	audioManager::getIns()->playBGM("sound/bgm_lobby.ogg");

	Sprite* back = Sprite::create("background/2.png");
	back->setPosition(Vec2(569, 320));
	back->setScaleX(1.32);
	back->setScaleY(2);
	addChild(back);

	Sprite* cristal = Sprite::create("UI/icon_ingame_rescueCristal.png");
	cristal->setPosition(Vec2(410, 610));
	cristal->setZOrder(1);
	addChild(cristal);

	Sprite* cristal_ground = Sprite::create("UI/gaugebg_heart02_bossBig.png");
	cristal_ground->setScaleX(0.1);
	cristal_ground->setPosition(445, 610);
	addChild(cristal_ground);

	Sprite* coin = Sprite::create("UI/icon_ingame_relayCoin.png");
	coin->setPosition(Vec2(540, 610));
	coin->setZOrder(1);
	addChild(coin);

	Sprite* coin_ground = Sprite::create("UI/gaugebg_heart02_bossBig.png");
	coin_ground->setScaleX(0.2);
	coin_ground->setPosition(605, 610);
	addChild(coin_ground);

	Sprite* cookieground = Sprite::create("startScene/cookieground.png");
	cookieground->setScaleY(1.2);
	addChild(cookieground);
	cookieground->setPosition(Vec2(900, 300));

	Sprite* itemBoard = Sprite::create("startScene/Itemboard.png");
	itemBoard->setScale(1.2);
	itemBoard->setPosition(Vec2(200, 300));
	addChild(itemBoard);

	Sprite* cookie = Sprite::create("bravecookie/img_tutorial_brave06.png");
	cookie->setScale(0.5);
	addChild(cookie);
	cookie->setPosition(Vec2(900, 340));

	Sprite* rankingBoard = Sprite::create("startScene/rankingboard.png");
	rankingBoard->setScale(1.2);
	rankingBoard->setPosition(Vec2(600, 300));
	addChild(rankingBoard);

	Label* best = Label::createWithTTF("9999", "fonts/SangSangFlowerRoad.otf", 50);
	addChild(best);
	best->enableOutline(Color4B::BLACK, 1);
	best->setPosition(Vec2(600, 260));

	int score1 = UserDefault::getInstance()->getIntegerForKey("myKey");
	int score2 = UserDefault::getInstance()->getIntegerForKey("myKey2");
	int score3 = UserDefault::getInstance()->getIntegerForKey("myKey3");
	std::string str = StringUtils::format(" 1À§ : %04d\n2À§ : %04d\n3À§ : %04d", score1, score2, score3);
	best->setString(str);

	Button* btn = Button::create("startScene/start_btn.png");
	btn->setPosition(Vec2(900, 85));
	btn->setScale(1.5);
	addChild(btn);
	btn->addTouchEventListener(CC_CALLBACK_2(startScene::btnClick, this));

	Button* btn2 = Button::create("startScene/exit_btn.png");
	btn2->setPosition(Vec2(80, 40));
	btn2->setScale(0.8);
	addChild(btn2);
	btn2->addTouchEventListener(CC_CALLBACK_2(startScene::btnClick2, this));

	Button* btn3 = Button::create("startScene/startBGM.png");
	btn3->setPosition(Vec2(1093, 605));
	btn3->setScale(0.8);
	addChild(btn3);
	btn3->addTouchEventListener(CC_CALLBACK_2(startScene::btnClick3, this));

    return true;
}

void startScene::btnClick(Ref* ref, Widget::TouchEventType type)
{
	Button* btn = (Button*)ref;
	if (type == Widget::TouchEventType::ENDED) {
		audioManager::getIns()->stopBGM();
		gameScene* game = gameScene::create();
		Director::getInstance()->replaceScene(game);
	}
}

void startScene::btnClick2(Ref* ref, Widget::TouchEventType type)
{
	Button* btn = (Button*)ref;
	if (type == Widget::TouchEventType::ENDED) {
		exit(0);
		return;
	}
}

void startScene::btnClick3(Ref* ref, Widget::TouchEventType type)
{
	Button* btn = (Button*)ref;
	if (type == Widget::TouchEventType::ENDED) {
		if (BGMstop == false) {
			audioManager::getIns()->setVolume(0);
			btn->loadTextureNormal("startScene/stopBGM.png");
			btn->setColor(Color3B::RED);
			BGMstop = true;
		}
		else {
			audioManager::getIns()->setVolume(1);
			btn->loadTextureNormal("startScene/startBGM.png");
			btn->setColor(Color3B::WHITE);
			BGMstop = false;
		}
	}
}


