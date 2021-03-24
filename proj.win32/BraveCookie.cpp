#include "BraveCookie.h"

bool BraveCookie::init()
{

    Sprite* cookie = Sprite::create("BraveCookie/ani_cookie0001/cookie0001_run01.png");
    this->addChild(cookie);
    cookie->setPosition(Vec2(100, 0));
    cookie->setAnchorPoint(Vec2(0, 0));
    Animation* ani = Animation::create();
    ani->addSpriteFrameWithFile("BraveCookie/ani_cookie0001/cookie0001_run01.png");
    ani->addSpriteFrameWithFile("BraveCookie/ani_cookie0001/cookie0001_run02.png");
    ani->addSpriteFrameWithFile("BraveCookie/ani_cookie0001/cookie0001_run03.png");
    ani->addSpriteFrameWithFile("BraveCookie/ani_cookie0001/cookie0001_run04.png");
    ani->setDelayPerUnit(0.1);
    ani->setLoops(-1);
    Animate* anime = Animate::create(ani);
    RemoveSelf* self = RemoveSelf::create();
    Sequence* seq = Sequence::create(anime, self, 0);
    cookie->runAction(seq);
   

    return true;
}

void BraveCookie::update(float dt)
{
}

void BraveCookie::jump(EventKeyboard::KeyCode key, Event* e)
{
}
