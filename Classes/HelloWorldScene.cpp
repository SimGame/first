#include "HelloWorldScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    if ( !Layer::init() )
    {
        return false;
    } 

	auto layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(180, 170, 160, 255));
	this->addChild(layerColorBG);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	createCardSprite(visibleSize);


	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	Point touchPoint = touch->getLocation();//get OpenGL position, the origin is downleft
	touch->getLocationInView();
	firstX = touchPoint.x;
	firstY = touchPoint.y;

	return true;
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	Point touchPoint = touch->getLocation();
	endX = firstX - touchPoint.x;
	endY = firstY - touchPoint.y;

	//Compare the move distance
	if(abs(endX) > abs(endY))
	{
		if(endX + 5 > 0)
		{
			doLeft();
		}
		else
		{
			doRight();
		}
	}
	else
	{
		if(endY + 5 > 0)
		{
			doDown();
		}
		else
		{
			doUp();
		}
	}
}

bool HelloWorld::doUp(){
    bool isdo = false;
    for (int x = 0; x < 4; x++) {
        for (int y = 3; y >= 0; y--) {
             
            for (int y1 = y - 1; y1 >= 0; y1--) {
                if (cardArr[x][y1]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                         
                        y++;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x][y1]->setNumber(0);
                         
                        isdo = true;
                    }
                    break;
                }
            }
             
        }
    }
	log("doUp");
    return isdo;
	//return true;
}

bool HelloWorld::doDown(){
    bool isdo = false;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
             
            for (int y1 = y + 1; y1 < 4; y1++) {
                if (cardArr[x][y1]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                         
                        y--;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x][y1]->setNumber(0);
                         
                        isdo = true;
                    }
                    break;
                }
            }
             
        }
    }
	log("doDown");
    return isdo;
}

bool HelloWorld::doLeft(){
    bool isdo = false;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
             
            for (int x1 = x + 1; x1 < 4; x1++) {
                if (cardArr[x1][y]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                         
                        x--;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x1][y]->setNumber(0);
                         
                        isdo = true;
                    }
                    break;
                }
            }
             
        }
    }
	log("doLeft");
    return isdo;
}

bool HelloWorld::doRight(){
    bool isdo = false;
    for (int y = 0; y < 4; y++) {
        for (int x = 3; x >= 0; x--) {
             
            for (int x1 = x - 1; x1 >= 0; x1--) {
                if (cardArr[x1][y]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                         
                        x++;
                        isdo = true;
                    }else if(cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()){
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        cardArr[x1][y]->setNumber(0);
                         
                        isdo = true;
                    }
                    break;
                }
            }
             
        }
    }
	log("doRight");
    return isdo;
}

//Create card
void HelloWorld::createCardSprite(cocos2d::Size size)
{
	//Caculate the unit size
	int unitSize = (size.height-28)/4;

	//4*4 unit grid
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			CardSprite* card = CardSprite::createCardSprite(2, unitSize, unitSize, unitSize * i + 140, unitSize * j + 20);
			cardArr[i][j] = card;
			addChild(card);
		}
	}
}

