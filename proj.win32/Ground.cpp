#include "Ground.h"

static Ground* obj = NULL;

bool Ground::init()
{
	auto sprBatch = SpriteBatchNode::create("obstacle/1. The Witch's Oven/epN01_tm01_tb1.png");
	addChild(sprBatch);
	sprBatch->setTag(1);
	sprBatch->setPosition(Vec2(60, 50));

	auto sprBatch2 = SpriteBatchNode::create("obstacle/1. The Witch's Oven/epN01_tm01_tb1.png");
	addChild(sprBatch2);
	sprBatch2->setTag(2);
	sprBatch2->setPosition(Vec2(1300, 50));

	for (int i = 0; i < 10; i++) {
		auto ground = Sprite::create("obstacle/1. The Witch's Oven/epN01_tm01_tb1.png");
		sprBatch->addChild(ground);
		ground->setPosition(Vec2(i * 124, 0));
	}

	for (int i = 0; i < 10; i++) {
		auto ground = Sprite::create("obstacle/1. The Witch's Oven/epN01_tm01_tb1.png");
		sprBatch2->addChild(ground);
		ground->setPosition(Vec2(i * 124, 0));
	}

	scheduleUpdate();

    return true;
}

void Ground::update(float dt)
{
	auto ground = getChildByTag(1);
	ground->setPositionX(ground->getPositionX() - 200 * dt);

	auto ground2 = getChildByTag(2);
	ground2->setPositionX(ground2->getPositionX() - 200 * dt);

	if (ground->getPositionX() <= -1240) {
		ground->setPositionX(ground2->getPositionX() + 1240);
	}
	if (ground2->getPositionX() <= -1240) {
		ground2->setPositionX(ground->getPositionX() + 1240);
	}
}
