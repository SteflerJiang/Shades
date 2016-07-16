#include "ShadeView.h"

USING_NS_CC;

Scene* ShadeView::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ShadeView::create();
	auto controller = ShadeController::create();
	layer->setController(controller);
	controller->setShadeView(layer);

	// add layer as a child to scene
	scene->addChild(layer);
	scene->addChild(controller);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ShadeView::init()
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

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(ShadeView::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Score : 0", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);


	auto bg = Sprite::create("bg.png");
	this->addChild(bg);
	bg->setAnchorPoint(Vec2(0, 0));
	bg->setPosition(0, 0);

	auto shade = Shade::create();
	this->addChild(shade);
	shade->setPosition(100, 100);

	return true;
}


void ShadeView::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void ShadeView::setController(ShadeController* controller)
{
	m_controller = controller;
}
