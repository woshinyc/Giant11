//
//  MainGameLayer.cpp
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#include "MainGameLayer.h"
#include "ResourcesHelper.h"
#include "LocalManager.h"
#include "GTool.h"
#include "GCannon.h"
#include "SCSprite.h"
#include "tinyxml.h"

CCScene* MainGameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainGameLayer *layer = MainGameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool MainGameLayer::init()
{
    if (DBaseLayer::init()) {
        
        
//        ResourcesHelper::shared(this)->readResourcesWithLevel(1);
       CCSprite *bg=CCSprite::create("bg.jpg");
        
        
        bg->setPosition(ccps(0.5, 0.5));
        addChild(bg);
        createCannon();
        LocalManager::sharedLocalManager()->loadGiantXml();
        return true;
    }
    return false;
}

#pragma mark---构建大炮
void MainGameLayer::createCannon()
{
    GCannon *canno=GCannon::sharedAdd(this);
    canno->setPosition(ccps(0.5, 0.1));
    CCSprite *cannonBg=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Metope.png"));
    cannonBg->setAnchorPoint(ccp(0.5, 0));
    cannonBg->setPosition(ccps(0.5, 0));
    addChild(cannonBg);
    
    SCSprite *subLevel=SCSprite::create("Icon.png",this,callfuncN_selector(MainGameLayer::subCannonLevel));
    SCSprite *addLevel=SCSprite::create("Icon.png",this,callfuncN_selector(MainGameLayer::addCannonLevel));
    subLevel->setPosition(ccps(0.3, 0.1));
    addLevel->setPosition(ccps(0.7, 0.1));
    addChild(subLevel);
    addChild(addLevel);
   

}
void MainGameLayer::addCannonLevel(CCNode *node)
{
    GCannon::shared()->addLevel();
}
void MainGameLayer::subCannonLevel(CCNode *node)
{
    GCannon::shared()->subLevel();
}

#pragma mark--加入触摸监测
void MainGameLayer::onEnter()
{
    setTouchEnabled(true);
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    CCLayer::onEnter();
}

void MainGameLayer::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

#pragma mark  touchDelegate

bool MainGameLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
   
 CCPoint touchLocation = touch->getLocation();
   


    
    return true;
}

void MainGameLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    
//    CCPoint touchLocation = touch->getLocation();
//    GCannon::shared()->setRotation(-(CC_RADIANS_TO_DEGREES(radianAandOrigin(touchLocation, GCannon::shared()->getPosition()))-90));
}

void MainGameLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{

    
}



