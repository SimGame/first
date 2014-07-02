#include "CardSprite.h"

CardSprite* CardSprite::createCardSprite(int numbers, int width, int height, float CardSpriteX, float CardSpriteY)
{
	CardSprite* enemy = new CardSprite();
	if(enemy && enemy->init())
	{
		enemy->autorelease();
		enemy->enemyInit(numbers, width, height, CardSpriteX, CardSpriteY);

		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}

bool CardSprite::init()
{
	if(!Sprite::init())
	{
		return false;
	}
	return true;
}

void CardSprite::enemyInit(int numbers, int width, int height, float CardSpriteX, float CardSpriteY)
{
	//init
	number = numbers;

	//Add background color
	layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(200, 190, 180, 255), width - 15, height - 15);
	layerColorBG->setPosition(cocos2d::Point(CardSpriteX, CardSpriteY));

	//Judge: if >0, display; else blank
	if(number > 0)
	{
		//add intermediate font
		labelTTFCardNumber = cocos2d::LabelTTF::create(cocos2d::String::createWithFormat("%i", number)->getCString(), "STHeitiSC-Medium", 100);
		labelTTFCardNumber->setPosition(cocos2d::Point(layerColorBG->getContentSize().width / 2, layerColorBG->getContentSize().height / 2));
		layerColorBG->addChild(labelTTFCardNumber);
	}
	else
	{
		labelTTFCardNumber = cocos2d::LabelTTF::create("", "STHeitiSC-Medium", 100);
		labelTTFCardNumber->setPosition(cocos2d::Point(layerColorBG->getContentSize().width / 2, layerColorBG->getContentSize().height / 2));
		labelTTFCardNumber->setTag(8);
		layerColorBG->addChild(labelTTFCardNumber);
	}

	this->addChild(layerColorBG);
}

int CardSprite::getNumber()
{
	return number;
}

void CardSprite::setNumber(int num)
{
	number = num;

	if(number > 0)
	{
		//get number and update it
		labelTTFCardNumber->setString(cocos2d::String::createWithFormat("%i", number)->getCString());
	}
	else
	{
		labelTTFCardNumber->setString("");
	}
}