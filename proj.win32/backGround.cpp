#include "backGround.h"

bool backGround::init()
{
	auto back = Sprite::create("background/0.png");
	back->setAnchorPoint(Vec2(0, 0));
	back->setScale(2);
	addChild(back);
	back->setTag(1);

	auto back2 = Sprite::create("background/0.png");
	back2->setAnchorPoint(Vec2(0, 0));
	back2->setPosition(Vec2(1138, 0));
	back2->setScale(2);
	addChild(back2);
	back2->setTag(2);

	scheduleUpdate();

    return true;
}

void backGround::update(float dt)
{
	auto back = getChildByTag(1);
	back->setPositionX(back->getPositionX() - 200 * dt);

	auto back2 = getChildByTag(2);
	back2->setPositionX(back2->getPositionX() - 200 * dt);

	if (back->getPositionX() <= -1138) {
		back->setPositionX(back2->getPositionX() + 1138);
	}
	if (back2->getPositionX() <= -1138) {
		back2->setPositionX(back->getPositionX() + 1138);
	}
}
