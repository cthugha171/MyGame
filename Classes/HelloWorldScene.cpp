/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

	size = false;

	Texture2D*texture = Director::getInstance()->getTextureCache()->addImage("mariFirst.png");
   
	SpriteFrame* frame0 = SpriteFrame::createWithTexture(texture, Rect(32 * 0, 32 * 0, 32, 32));
	SpriteFrame* frame1 = SpriteFrame::createWithTexture(texture, Rect(32 * 1, 32 * 0, 32, 32));
	SpriteFrame* frame2 = SpriteFrame::createWithTexture(texture, Rect(32 * 2, 32 * 0, 32, 32));
	SpriteFrame* frame3 = SpriteFrame::createWithTexture(texture, Rect(32 * 3, 32 * 0, 32, 32));
	SpriteFrame* frame4 = SpriteFrame::createWithTexture(texture, Rect(32 * 4, 32 * 0, 32, 32));
	SpriteFrame* frame5 = SpriteFrame::createWithTexture(texture, Rect(32 * 5, 32 * 0, 32, 32));

	Texture2D *texture2 = Director::getInstance()->getTextureCache()->addImage("mariene.png");

	SpriteFrame* eframe0 = SpriteFrame::createWithTexture(texture2, Rect(32 * 0, 32 * 0, 32, 32));
	SpriteFrame* eframe1 = SpriteFrame::createWithTexture(texture2, Rect(32 * 1, 32 * 0, 32, 32));
	SpriteFrame* eframe2 = SpriteFrame::createWithTexture(texture2, Rect(32 * 2, 32 * 0, 32, 32));
	SpriteFrame* eframe3 = SpriteFrame::createWithTexture(texture2, Rect(32 * 3, 32 * 0, 32, 32));
	SpriteFrame* eframe4 = SpriteFrame::createWithTexture(texture2, Rect(32 * 4, 32 * 0, 32, 32));
	SpriteFrame* eframe5 = SpriteFrame::createWithTexture(texture2, Rect(32 * 0, 32 * 1, 32, 32));
	SpriteFrame* eframe6 = SpriteFrame::createWithTexture(texture2, Rect(32 * 1, 32 * 1, 32, 32));
	SpriteFrame* eframe7 = SpriteFrame::createWithTexture(texture2, Rect(32 * 1, 32 * 4, 32, 32));


	Vector<SpriteFrame*>runFrame(3);
	runFrame.pushBack(frame0);
	runFrame.pushBack(frame1);
	runFrame.pushBack(frame2);

	Vector<SpriteFrame*>kameFrames(2);
	kameFrames.pushBack(eframe5);
	kameFrames.pushBack(eframe6);
	
	BackGround = Sprite::create("stage.png");
	BackGround->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	BackGround->setScale(5.0f);
	this->addChild(BackGround);

	sprMario = Sprite::createWithSpriteFrame(frame0);
	sprMario->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 4-65));
	sprMario->setScale(5.0f);
	this->addChild(sprMario);

	kame = Sprite::createWithSpriteFrame(eframe5);
	kame->setPosition(Vec2(visibleSize.width / 4 * 3, visibleSize.height / 4-50));
	kame->setFlippedX(true);
	kame->setScale(5.0f);
	this->addChild(kame);

	Box = Sprite::createWithSpriteFrame(eframe0);
	Box->setPosition(Vec2(visibleSize.width / 3, visibleSize.height / 5*2+30));
	Box->setScale(5.0f);
	this->addChild(Box);

	kinoko = Sprite::createWithSpriteFrame(eframe2);
	kinoko->setPosition(Vec2(visibleSize.width / 4*3-90, visibleSize.height));
	kinoko->setScale(5.0f);
	kinoko->setVisible(false);
	this->addChild(kinoko);

	Animation*runaction = Animation::createWithSpriteFrames(runFrame, 0.2f);

    Animate*animate = Animate::create(runaction);

	Repeat*repeat = Repeat::create(animate, 4);

	CallFunc* jumpaction = CallFunc::create(CC_CALLBACK_0(HelloWorld::mariJump, this));

	CallFunc* turnM = CallFunc::create(CC_CALLBACK_0(HelloWorld::turnMario, this));

	MoveBy*run = MoveBy::create(2.0f, Vec2(100.0f, 0));

	MoveBy*running = MoveBy::create(2.0f, Vec2(-100.0f, 0.0f));

	Spawn*runM = Spawn::create(repeat, running, nullptr);

	Repeat*escape = Repeat::create(runM, 4);

	DelayTime*waitMario = DelayTime::create(11.0f);

	JumpBy*jump = JumpBy::create(2.0f, Vec2(50.0f, 0.0f), 100.0f, 1);

	Spawn*runAway = Spawn::create(run, repeat,nullptr);

	Spawn*jumpUp = Spawn::create(jumpaction, jump,nullptr);

	Sequence*move = Sequence::create(runAway, jumpUp, runAway, waitMario, turnM, escape, nullptr);

	//kame
	Animation*kameMove = Animation::createWithSpriteFrames(kameFrames, 0.2f);

	Animate*kameAnime = Animate::create(kameMove);

	Repeat*kameRepeat = Repeat::create(kameAnime, 5);

	MoveBy*kamove = MoveBy::create(2.0f, Vec2(-100.0f, 0.0f));

	Repeat*chase = Repeat::create(kamove, 5);

	Spawn*kamena = Spawn::create(kameRepeat, kamove, nullptr);

	Blink*kameblink = Blink::create(3.0f, 10);

	CallFunc*kamebig = CallFunc::create(CC_CALLBACK_0(HelloWorld::kameten, this));

	DelayTime*waitKame = DelayTime::create(11.3f);

	Spawn*kameChangeSize = Spawn::create(kameblink, kamebig, nullptr);

	Sequence*kamedesu = Sequence::create(kamena, waitKame, kameChangeSize,chase,nullptr);

	//box
	CallFunc*chanBox = CallFunc::create(CC_CALLBACK_0(HelloWorld::changeBox, this));

	DelayTime*waitBox = DelayTime::create(5.0f);
	
	Sequence*boxChange = Sequence::create(waitBox, chanBox, nullptr);
	
	//kinoko
	DelayTime*waitkinoko = DelayTime::create(6.0f);

	CallFunc*actkinoko = CallFunc::create(CC_CALLBACK_0(HelloWorld::activeKinoko, this));

	CallFunc*noActKinoko = CallFunc::create(CC_CALLBACK_0(HelloWorld::noActiveKinoko, this));

	Blink*active = Blink::create(5.0f, 10);

	MoveTo*downkinoko = MoveTo::create(2.0f,Vec2(visibleSize.width / 4 * 3 - 90, visibleSize.height / 4));

	Sequence*kinokoMove = Sequence::create(waitkinoko,actkinoko, active,downkinoko,noActKinoko, nullptr);

	experimental::AudioEngine::play2d("bgm.mp3", true,0.2f);

	sprMario->runAction(move);
	kame->runAction(kamedesu);
	Box->runAction(boxChange);
	kinoko->runAction(kinokoMove);

    return true;
}

void HelloWorld::mariJump()
{
	Texture2D*texture = Director::getInstance()->getTextureCache()->addImage("mariFirst.png");

	SpriteFrame* frame4 = SpriteFrame::createWithTexture(texture, Rect(32 * 4, 32 * 0, 32, 32));
	sprMario->setSpriteFrame(frame4);
}

void HelloWorld::changeBox()
{
	Texture2D *texture2 = Director::getInstance()->getTextureCache()->addImage("mariene.png");

	SpriteFrame* eframe7 = SpriteFrame::createWithTexture(texture2, Rect(32 * 1, 32 * 4, 32, 32));
	Box->setSpriteFrame(eframe7);
	experimental::AudioEngine::play2d("miss.mp3");
}

void HelloWorld::activeKinoko()
{
	kinoko->setVisible(true);
}

void HelloWorld::noActiveKinoko()
{
	kinoko->setVisible(false);
}

void HelloWorld::kameten()
{
	experimental::AudioEngine::play2d("getkinoko.mp3");

	kame->setScale(10.0f);
	kame->setPosition(Vec2(950, 215));
}

void HelloWorld::turnMario()
{
	sprMario->setFlippedX(true);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void HelloWorld :: update(float delta)
{
	
}
