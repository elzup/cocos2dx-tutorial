#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (CCLayerGradient::initWithColor(Color4B::BLACK, Color4B::ORANGE, Vec2::ANCHOR_MIDDLE))
	{
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		CCSprite *player = CCSprite::create("monkey01.png",
				CCRectMake(0, 0, 100, 135) );

		player->setPosition(ccp(player->getContentSize().width * 3 / 2,
				winSize.height / 2));

		player->setTag(1);

		this->addChild(player);
	}

	this->schedule(schedule_selector(HelloWorld::gameLogic), 3.0);

	return true;
}

void HelloWorld::addFood()
{

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *food = CCSprite::create("hamburger.png", CCRectMake(0, 0, 36, 30));
	int height = rand() % (int) winSize.height;
	food->setPosition(ccp(winSize.width + food->getContentSize().width / 2, height));
	food->setTag(2);
	this->addChild(food);

	float duration = 2.0f;
	CCMoveTo* actionMove = CCMoveTo::create(duration, ccp(food->getContentSize().width * 3 / 2, food->getPositionY()));

	CCCallFuncN* actionMoveDone =
			CCCallFuncN::create(this, callfuncN_selector(HelloWorld::spriteMoveFinished));
	food->runAction(CCSequence::create(actionMove, actionMoveDone, NULL));
}

void HelloWorld::spriteMoveFinished(CCNode* sender) {
	CCSprite *sprite = (CCSprite *)sender;
	bool isCleanUp = true;
	this->removeChild(sprite, isCleanUp);
}

void HelloWorld::gameLogic(float dt)
{
	this->addFood();
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
