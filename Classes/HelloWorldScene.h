#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CardSprite.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
   
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool doUp();
	bool doDown();
	bool doLeft();
	bool doRight();

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unused_event);

	//Create card
	void createCardSprite(cocos2d::Size size);
	CardSprite* cardArr[4][4];

private:
	int firstX, firstY, endX, endY;
	
};

#endif // __HELLOWORLD_SCENE_H__
