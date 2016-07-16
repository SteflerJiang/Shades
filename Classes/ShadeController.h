#ifndef __SHADECONTROLLER_H__
#define __SHADECONTROLLER_H__

#include "cocos2d.h"
#include "Shade.h"
//#include "ShadeView.h"

class ShadeView;

class ShadeController : public cocos2d::Layer
{
public:

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(ShadeController);

public:
	Shade* v1;
	Shade* v2;
	Shade* v3;
	Shade* v4;
	Shade* runningShade;

	int indexes[4];
	int levels[4];

	ShadeView* m_view;
	void setShadeView(ShadeView* view);

	void update(float dt);
	void addShade();

	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

};

#endif // __SHADECONTROLLER_H__
