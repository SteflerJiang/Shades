#include "ShadeController.h"
#include "ShadeView.h"

bool ShadeController::init()
{
	runningShade = nullptr;
	v1 = nullptr;
	v2 = nullptr;
	v3 = nullptr;
	v4 = nullptr;
	for (int i = 0; i < 4; i ++)
	{
		indexes[i] = 0;
		levels[i] = 0;
	}

	auto listener = EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(ShadeController::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(ShadeController::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(ShadeController::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

	return true;
}

void ShadeController::addShade()
{
	int level = random(1, 4);
	int index = random(1, 4);
	runningShade = Shade::create();
	runningShade->initWithLevel(level, index);
	m_view->addChild(runningShade);
}

void ShadeController::update(float dt) 
{
	float bottom = 10.0f;
	float speed = 10.0f;
	if (runningShade == nullptr)
	{
		addShade();
	}
	else
	{
		if (runningShade->getPositionY() < bottom)
		{
			runningShade = nullptr;
			addShade();
		}
		else
		{
			runningShade->setPositionY(runningShade->getPositionY() - speed);
		}
	}
}

void ShadeController::setShadeView(ShadeView* view)
{
	m_view = view;
}

bool ShadeController::onTouchBegan(Touch *touch, Event *unused_event)
{
	Vec2 pos = touch->getLocation();
	CCLOG("touch pos is x = %f, y = %f", pos.x, pos.y);
	return true;
}

void ShadeController::onTouchMoved(Touch *touch, Event *unused_event) {}

void ShadeController::onTouchEnded(Touch *touch, Event *unused_event) {}