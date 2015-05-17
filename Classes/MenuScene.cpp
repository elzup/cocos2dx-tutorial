#include "MenuScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    auto centerpos = visibleSize / 2;

    auto spritebg = Sprite::create("helloBG.png");
    spritebg->setPosition(create());
    addChild(spritebg);


    MenuItemFont::setFontSize(60);


    auto menuItemPlay = MenuItemImage::create(
    		"start_n.png",
			"start_s.png",
			CC_CALLBACK_1(MenuScene::onPlay, this));
    auto menu = Menu::create(menuItemPlay, NULL);
    addChild(menu);

    return true;

}
