#include "EndScene.h"

bool EndScene::init()
{
    //배경
    Sprite* end = Sprite::create("background/37.png");
    this->addChild(end);
    end->setAnchorPoint(Vec2(0, 0));
 
    //신기록 UI
    Sprite* record = Sprite::create("UI2/imgTxt_newRecord.png");
    this->addChild(record);
    record->setPosition(Vec2(569, 550));
   

    //기록보여주는 라벨
    Label* score = Label::createWithTTF("Score:0000","Marker Felt.ttf", 100);
    this->addChild(score);
    score->setPosition(Vec2(569, 320));
    score->setTextColor(Color4B::YELLOW);

    //게임화면으로 돌아가는 라벨
    Label* replay = Label::createWithTTF("RePlay : Enter", "Marker Felt.ttf", 30);
    this->addChild(replay);
    replay->setPosition(Vec2(569, 200));
    replay->setTextColor(Color4B::RED);

    //엔딩 화면에 Enter키를 누르면 시작화면으로 돌아가는 key
    EventListenerKeyboard* key = EventListenerKeyboard::create();
    key->onKeyPressed = CC_CALLBACK_2(EndScene::Return, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(key, this);

    return true;
}

void EndScene::update(float dt)
{
}

void EndScene::Return(EventKeyboard::KeyCode key ,Event* e)
{
    //키보드 Enter키를 누르면 시작화면으로 돌아가는 소스
    if(key==EventKeyboard::KeyCode::KEY_ENTER)
    {
        //Director::getInstance()->replaceScene();
    }

}
