#include "cookie.h"
#include "gameScene.h"

bool cookie::init()
{
    jump = 0;

    Sprite* player = Sprite::create("bravecookie/ani_cookie0001/cookie0001_run01.png");
    this->addChild(player);
    player->setPosition(Vec2(300, 310));
    player->setTag(1);

    Animation* ani = Animation::create();
    ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run01.png");
    ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
    ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
    ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run04.png");
    ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
    ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
    ani->setDelayPerUnit(0.08);
    ani->setLoops(-1);
    Animate* anime = Animate::create(ani);
    player->runAction(anime);
    anime->setTag(2);

    EventListenerKeyboard* key = EventListenerKeyboard::create();
    key->onKeyPressed = CC_CALLBACK_2(cookie::keyPress, this);
    key->onKeyReleased = CC_CALLBACK_2(cookie::keyRelease, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(key, this);

    this->scheduleUpdate();

    return true;
}

void cookie::update(float dt)
{
    if (this->getPositionY() > 0)
    {
        this->setPositionY(this->getPositionY() - dt * 350);
    }

    else if (this->getPositionY() < 0)
    {
        jump = 0;
        CCLOG("reset:%d", jump);
        this->setPositionY(0);
        if (jump == 0)
        {
            Sprite* s = (Sprite*)this->getChildByTag(1);
            if (s->getActionByTag(5)) {
                s->stopActionByTag(5);
            }
            if (s->getActionByTag(7)) {
                s->stopActionByTag(7);
            }
            //3,점프하고 내려올때 다시 걷는 애니매이션
            Animation* ani = Animation::create();
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run01.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run04.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
            ani->setDelayPerUnit(0.08);
            ani->setLoops(-1);
            Animate* anime = Animate::create(ani);
            s->runAction(anime);
            s->setPosition(Vec2(300, 310));
            s->setScale(1);
            anime->setTag(6);
        }
    }
}

void cookie::keyPress(EventKeyboard::KeyCode key, Event* e)
{
    gameScene* scene = (gameScene*)getParent();
    if (key == EventKeyboard::KeyCode::KEY_F && scene->isPause == false)
    {
        if (jump < 2) {
            if (this->getActionByTag(1)) {
                this->stopActionByTag(1);
            }


            MoveBy* by = MoveBy::create(0.2, Vec2(0, 250));
            by->setTag(1);
            this->runAction(by);
            jump += 1;
            CCLOG("jump:%d", jump);
            if (jump == 1)
            {
                Sprite* s = (Sprite*)this->getChildByTag(1);
                if (s->getActionByTag(2)) {
                    s->stopActionByTag(2);
                }
                if (s->getActionByTag(4)) {
                    s->stopActionByTag(4);
                }
                if (s->getActionByTag(6)) {
                    s->stopActionByTag(6);
                }
                if (s->getActionByTag(3)) {
                    s->stopActionByTag(3);
                }
                //2.1단점프하는 애니메이션
                Animation* ani = Animation::create();
                ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run01.png");
                ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
                ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
                ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run04.png");
                ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
                ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
                ani->setDelayPerUnit(0.08);
                ani->setLoops(-1);
                Animate* anime = Animate::create(ani);
                s->runAction(anime);
                s->setPosition(Vec2(300, 350));
                s->setScale(1);
                anime->setTag(7);
            }
            if (jump == 2)
            {
                Sprite* s = (Sprite*)this->getChildByTag(1);
                if (s->getActionByTag(2)) {
                    s->stopActionByTag(2);
                }
                if (s->getActionByTag(4)) {
                    s->stopActionByTag(4);
                }
                if (s->getActionByTag(6)) {
                    s->stopActionByTag(6);
                }
                if (s->getActionByTag(7)) {
                    s->stopActionByTag(7);
                }
                //1. 이단 점프 하는 애니메이션
                Animation* ani = Animation::create();
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0001.png");
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0002.png");
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0003.png");
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0004.png");
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0005.png");
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0006.png");
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0007.png");
                ani->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0008.png");
                ani->setDelayPerUnit(0.13);
                ani->setLoops(1);
                Animate* anime = Animate::create(ani);
                s->runAction(anime);
                s->setScale(1.5);
                s->setPosition(Vec2(300, 430));
                anime->setTag(5);
            }


        }

    }
    if (key == EventKeyboard::KeyCode::KEY_J && scene->isPause == false)
    {
        if (jump < 1)
        {
            Sprite* s = (Sprite*)this->getChildByTag(1);
            if (s->getActionByTag(2)) {
                s->stopActionByTag(2);

            }
            if (s->getActionByTag(4))
            {
                s->stopActionByTag(4);
            }
            if (s->getActionByTag(6))
            {
                s->stopActionByTag(6);
            }
            if (s->getActionByTag(7)) {
                s->stopActionByTag(7);
            }
            //4, 슬라이드하는 애니메이션
            Animation* ani1 = Animation::create();
            ani1->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0010.png");
            ani1->addSpriteFrameWithFile("bravecookie/cookie0001x2/cookie0001x2_0011.png");
            ani1->setDelayPerUnit(0.1);
            ani1->setLoops(-1);
            Animate* anime1 = Animate::create(ani1);
            s->runAction(anime1);
            s->setScale(1.5);
            s->setPosition(Vec2(300, 430));
            anime1->setTag(3);
        }
    }
}

void cookie::keyRelease(EventKeyboard::KeyCode key, Event* e)
{
    if (jump < 1)
    {
        gameScene* scene = (gameScene*)getParent();
        if (key == EventKeyboard::KeyCode::KEY_J && scene->isPause == false) {
            Sprite* s = (Sprite*)this->getChildByTag(1);
            if (s->getActionByTag(3)) {
                s->stopActionByTag(3);
                //5.슬라이드를 떄고 다시 걷는 애니메이션
            }
            Animation* ani = Animation::create();
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run01.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run04.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run03.png");
            ani->addSpriteFrameWithFile("bravecookie/ani_cookie0001/cookie0001_run02.png");
            ani->setDelayPerUnit(0.08);
            ani->setLoops(-1);
            Animate* anime = Animate::create(ani);
            s->runAction(anime);
            anime->setTag(4);
            s->setPosition(Vec2(300, 310));
            s->setScale(1);
        }
    }
}

