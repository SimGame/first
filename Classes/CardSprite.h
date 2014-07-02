#ifndef __CARDSPRITE_SCENE_H__
#define __CARDSPRITE_SCENE_H__

#include "cocos2d.h"

class CardSprite : public cocos2d::Sprite
{
public:
	//init
	static CardSprite* createCardSprite(int numbers, int width, int height, float CardSpriteX, float CardSpriteY);
	virtual bool init();
	CREATE_FUNC(CardSprite);

	//get number
	int getNumber();
	//set number
	void setNumber(int num);

private:
	//displayed number
	int number;
	void enemyInit(int numbers, int width, int height, float CardSpriteX, float CardSpriteY);

	//define the label to display number
	cocos2d::LabelTTF* labelTTFCardNumber;

	//display background
	cocos2d::LayerColor* layerColorBG;
};

#endif //__CARDSPRITE_SCENE_H__