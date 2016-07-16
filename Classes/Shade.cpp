#include "Shade.h"
using namespace std;

bool Shade::init()
{
	return true;
}

void Shade::initWithLevel(int level, int index)
{
	this->level = level;
	this->index = index;
	if (level == 1)
		sp = Sprite::create("g1.png");
	else if (level == 2)
		sp = Sprite::create("g2.png");
	else if (level == 3)
		sp = Sprite::create("g3.png");
	else if (level == 4)
		sp = Sprite::create("g4.png");
	
	sp->setAnchorPoint(Vec2(0, 0));
	sp->setPosition(0, 0);
	this->addChild(sp);
	this->setPosition((index-1)*142, 1000);

	CCLOG("this->getContentSize().width = %f height = %f", this->getContentSize().width, this->getContentSize().height);
}