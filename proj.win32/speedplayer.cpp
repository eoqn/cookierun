#include "speedplayer.h"

bool speedplayer::init()
{
	Sprite* speed = Sprite::create("bravecookie/ani_cookie0001/cookie0001_run01.png");
	this->addChild(speed);
	speed->setTag(1);

	Animation* ani = Animation::create();
	ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0036.png");
	ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0037.png");
	ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0038.png");
	ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0039.png");
	ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0038.png");
	ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0037.png");
	ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0036.png");
	ani->setDelayPerUnit(0.1);
	ani->setLoops(5);
	Animate* anime = Animate::create(ani);
	speed->runAction(anime);

    return true;
}

void speedplayer::update(float dt)
{
}
