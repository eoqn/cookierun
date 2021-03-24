#include "EndScene.h"

bool EndScene::init()
{
    //���
    Sprite* end = Sprite::create("background/37.png");
    this->addChild(end);
    end->setAnchorPoint(Vec2(0, 0));
 
    //�ű�� UI
    Sprite* record = Sprite::create("UI2/imgTxt_newRecord.png");
    this->addChild(record);
    record->setPosition(Vec2(569, 550));
   

    //��Ϻ����ִ� ��
    Label* score = Label::createWithTTF("Score:0000","Marker Felt.ttf", 100);
    this->addChild(score);
    score->setPosition(Vec2(569, 320));
    score->setTextColor(Color4B::YELLOW);

    //����ȭ������ ���ư��� ��
    Label* replay = Label::createWithTTF("RePlay : Enter", "Marker Felt.ttf", 30);
    this->addChild(replay);
    replay->setPosition(Vec2(569, 200));
    replay->setTextColor(Color4B::RED);

    //���� ȭ�鿡 EnterŰ�� ������ ����ȭ������ ���ư��� key
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
    //Ű���� EnterŰ�� ������ ����ȭ������ ���ư��� �ҽ�
    if(key==EventKeyboard::KeyCode::KEY_ENTER)
    {
        //Director::getInstance()->replaceScene();
    }

}
