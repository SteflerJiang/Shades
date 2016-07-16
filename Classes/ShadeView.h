#ifndef __SHADEVIEW_H__
#define __SHADEVIEW_H__

#include "cocos2d.h"
#include "ShadeController.h"
#include "Shade.h"

class ShadeView : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(ShadeView);

public:
	ShadeController* m_controller;
	void setController(ShadeController* controller);

};

#endif // __SHADEVIEW_H__
