//
//  GCannon.cpp
//  Giant
//
//  Created by Mac on 13-9-5.
//
//

#include "GCannon.h"
#include "GTool.h"
#include "DDefine.h"
#include "GSpriteManager.h"
using namespace std;

static GCannon *s_instance = NULL;
GCannon *GCannon::sharedAdd(CCNode *beHold)
{
    if (!s_instance) {
        s_instance =  GCannon::createGCannon();
        //s_instance->cannonNum=1;
    }
    if (s_instance->_beHold) {
        s_instance->_beHold->removeChild(s_instance->baNode);
    }
    beHold->addChild(s_instance->baNode);
    beHold->addChild(s_instance,cannonZ);
    s_instance->_beHold=beHold;
    return s_instance;

}
GCannon * GCannon::shared()
{
    if (s_instance) {
        return s_instance;
    }
    return NULL;
}

GCannon*  GCannon::createGCannon()
{
    GCannon *cannon =new GCannon();
    cannon->canFire=true;
  CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("cannon.plist");
    CCSpriteBatchNode *batchNode=CCSpriteBatchNode::create("cannon.png");
    cannon->baNode=batchNode;
    cannon->cannonNum=1;
     CCLog("cannonNum=%d",cannon->cannonNum);
    cannon->initWithSpriteFrameName("Barrel.png");
    // 
    cannon->cannonNumSp=CCSprite::createWithSpriteFrameName("Cannon01.png");
    cannon->cannonNumSp->setPosition(ccpsprite(0.5, 0.5, cannon));
    //
    cannon->addChild(cannon->cannonNumSp);
    return cannon;
}

void GCannon::addLevel()
{
    CCLog("cannonNum=%d",this->cannonNum);
    if (cannonNum==MAX_CANNON_LEVEL) {
        return;
    }
    ++cannonNum;
    char name[128];
    sprintf(name,"Cannon%02d.png",cannonNum);
    CCLog("aa=%s",name);
    cannonNumSp->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));
}
void GCannon::subLevel()
{
    if (cannonNum==MIN_CANNON_LEVEL) {
        return;
    }
    --cannonNum;
    char name[128];
    sprintf(name,"Cannon%02d.png",cannonNum);
    
    cannonNumSp->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));
}


void GCannon::fire(CCPoint targetPo)   //开火 
{
    if (canFire) {
        canFire=false;
        CCDelayTime *d=CCDelayTime::create(0.3);
        CCCallFunc *c= CCCallFunc::create(this, callfunc_selector(GCannon::openFire));
        
        CCSequence * se=CCSequence::create(d,c,NULL);
        runAction(se);
        shootBullet(targetPo);
       
    }
    return;
}

void GCannon::shootBullet(CCPoint targetPo)  //发射子弹
{
    float radian= radianAandOrigin(targetPo, GCannon::shared()->getPosition());
    CCPoint po= ccpForAngle(radian); //向量
    CCPoint startPointToCannon=ccpMult(po, this->getContentSize().height*(1-this->getAnchorPoint().y)); //得到起始点 用炮的纹理高度来计算 此点相对于炮自身坐标
    CCPoint startPoint=ccpAdd(GCannon::shared()->getPosition(), startPointToCannon);
    
  GBullet *bul=GSpriteManager::shared()->getBullet();
    bul->setScale(0.3);
    bul->setRotation(this->getRotation()-90);
    bul->setPosition(startPoint);//(this->getPosition());
    if (bul->isVisible()) {
        _beHold->addChild(bul,bulletZ);
    }else{
        bul->setVisible(true);
        
    }
    
    CCMoveTo *m=CCMoveTo::create(0.1, targetPo);
    CCCallFunc *c=CCCallFunc::create(bul, callfunc_selector(GBullet::playExplosionAct));
    CCSequence *se=CCSequence::create(m,c);
    bul->runAction(se);
    bul->playFireAct();
    
    
    
}


#pragma mark--加入触摸监测
void GCannon::onEnter()
{
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
    
    CCSprite::onEnter();
}

void GCannon::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}

#pragma mark  touchDelegate

bool GCannon::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    
    CCPoint touchLocation = touch->getLocation();

    setRotation(-(CC_RADIANS_TO_DEGREES(radianAandOrigin(touchLocation, GCannon::shared()->getPosition()))-90));
    if (canFire) {
        fire(touchLocation);
    }
    return true;
}

void GCannon::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
     CCPoint touchLocation = touch->getLocation();
     setRotation(-(CC_RADIANS_TO_DEGREES(radianAandOrigin(touchLocation, GCannon::shared()->getPosition()))-90));
 
    if (canFire) {
        fire(touchLocation);
    }
}

void GCannon::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    
    
}
