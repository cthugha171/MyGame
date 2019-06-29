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

	//乱数の初期化
	srand(time(nullptr));

	for(int i=0;i<1;i++)
	{
		sprite[i] = Sprite::create("kuma.png");
		this->addChild(sprite[i]);
		sprite[i]->setPosition(Vec2(200*i, visibleSize.height / 2.0f));
		sprite[i]->setScale(0.2f);

		float mx, my;
		mx =(float)rand()/RAND_MAX*500-250;
		my =(float)rand()/RAND_MAX*500-250;

		//アクションの作成(1秒かけて　右の200、上に100動く）
		//MoveBy*action1 = MoveBy::create(1.0f, Vec2(mx, my));

		//JumpBy*action1 = JumpBy::create(2.0f, Vec2(mx,my), 80.0f, 1);

		/*sprite[i]->setAnchorPoint(Vec2(0, 1));*/

		/*MoveBy*action1 = MoveBy::create(2.0f, Vec2(-100, 0));*/

		//RotateBy*action1 = RotateBy::create(2.0f, Vec3(0, 0, 1000));

		/*sprite[i]->setColor(Color3B(255, 0, 0));

		TintTo*action1 = TintTo::create(2.0f, Color3B(0, 0, 255));*/

		FadeOut*action1 = FadeOut::create(2.0f);

		/*FadeOut*action2 = FadeOut::create(5.0f);*/
		sprite[i]->runAction(action1);
		/*sprite[i]->runAction(action2);*/
	}

	//sprite = Sprite::create("sample05.png");
	//this->addChild(sprite);
	//sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	//
	//sprite2 = Sprite::create("kuma.png");
	//this->addChild(sprite2);
	
	
	//sprite2->runAction(action1->clone());
	/*MoveBy*action2 = MoveBy::create(1.0f, Vec2(200, 100));

	*/
	//ScaleBy*action1 = ScaleBy::create(1.0f,5.0f);	//ノードに対してアクションを実行する
	//JumpTo*action1 = JumpTo::create(1.0f, Vec2(200, 100), 500.0f, 1);

	//ベジェ曲線
	//ccBezierConfig conf;
	/*conf.controlPoint_1 = Vec2(800, 700);
	conf.controlPoint_2 = Vec2(1000, 700);
	conf.endPosition = Vec2(1000, 360);*/

	//BezierTo*action1 = BezierTo::create(2.0f, conf);

	//フェード
	/*sprite->setOpacity(0);

	FadeIn* action1 = FadeIn::create(1.0f);*/

	//SkewTo*action1 = SkewTo::create(5.0f,4.0f,9.0f);

	//Blink*action1 = Blink::create(5.0f, 9);

	//イージングアクション
	//EaseIn*action2 = EaseIn::create(action1, 2.0f);

	//EaseBackInOut*action2 = EaseBackInOut::create(action1);

	//EaseBounceInOut*action2 = EaseBounceInOut::create(action1);
	
	
	//sprite->setScale(3.0f, 3.0f);;
	//sprite->setAnchorPoint(Vec2(0, 1.0f));//原点の設定
	////sprite->setRotation(45.0f);
	//sprite2->setOpacity(0);
	///*sprite->setColor(Color3B(255, 0, 0));*/
	//sprite->setTextureRect(Rect(0, 0, 32, 32));//（開始位置.X,開始位置.Y,範囲.width,範囲.height）

	////update関数を有効にする
	//this->scheduleUpdate();
	//
	//state = 0;
	//rote = 0;
	//blue = 0;

    return true;
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
	//rote += 15.0f;

	//sprite->setRotation(rote);

	/*blue += 255.0f / 180.0f;

	if (blue > 255.0f)
	{
		blue = 255.0f;
	}

	sprite->setColor(Color3B(255.0f-blue, 0, blue));*/

	//Vec2 pos = sprite->getPosition();

	//pos.x += 1;

	//if (pos.x <= 50)
	//{
	//	sprite->setFlippedX(true);
	//	pos.x += 1;
	//}
	//if (pos.x >= 1000)
	//{
	//	sprite->setFlippedX(true);
	//	pos.x += -2;
	//}

	//sprite->setPosition(pos);

	//
	////スプライトの現在透明度を取得
	//float opa ;
	//opa = sprite->getOpacity();
 //   //徐々に薄く
	//opa -= 1.0f;

	//float opa2 = sprite2->getOpacity();

	//opa2 += 1.0f;

	////移動後の座標を反映
	////sprite->setPosition(pos);
	////透明度を反映
	//sprite->setOpacity(opa);
	//sprite2->setOpacity(opa2);
}
