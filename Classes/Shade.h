#ifndef __SHADE_H__
#define __SHADE_H__

#include "cocos2d.h"
USING_NS_CC;

class Shade : public Node
{
public:

	virtual bool init();
	void initWithLevel(int level, int index);

	// implement the "static create()" method manually
	CREATE_FUNC(Shade);

public:
	Sprite* sp;
	int level; //color
	int index; //pos
};

#endif // __SHADE_H__
