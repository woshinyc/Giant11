//
//  GBullet.cpp
//  Giant
//
//  Created by Mac on 13-9-6.
//
//

#include "GBullet.h"
#include "GSpriteManager.h"
GBullet*GBullet::build()
{
    GBullet *bullet=new GBullet();
    if (bullet&&bullet->initWithSpriteFrameName("fire001.png")) {
        bullet->deployBullet();
        return bullet;
    }
    return NULL;
}


void GBullet::deployBullet()
{
#pragma mark -射击行进动画
    CCArray *animFrames=CCArray::createWithCapacity(3);
    char str[100]={0};
    for (int i = 0; i<3; i++) {
        sprintf(str, "fire%03d.png",(i+1));
        CCSpriteFrame *frame =CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    CCAnimation *fireAnimation = CCAnimation::createWithSpriteFrames(animFrames,0.3);
   fireAct= CCRepeatForever::create( CCAnimate::create(fireAnimation));
    fireAct->retain();

#pragma mark -爆炸动画
    
    animFrames=CCArray::createWithCapacity(17);
    for (int i=0; i<17; i++) {
        sprintf(str, "explosion%03d.png",(i+1));
        CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    CCAnimation *explosionAnimation = CCAnimation::createWithSpriteFrames(animFrames,0.05);
    CCCallFuncN *callFunND=CCCallFuncN::create(this, callfuncN_selector(GBullet::callBack));//callfuncN_selector(GSpriteManager::setFreeBullet));
    CCActionInterval *exAct=CCRepeat::create( CCAnimate::create(explosionAnimation), 1);
   CCActionInterval *seq=CCSequence::create(exAct,callFunND,NULL);
    explosionAct=seq;
   explosionAct->retain();
    
}

void GBullet::callBack(CCNode *nnn)
{
    
    GBullet *bu=(GBullet *)nnn;
    GSpriteManager::shared()->setFreeBullet(bu);
    
}

void GBullet::playFireAct()
{
    runAction(fireAct);
}
void GBullet::playExplosionAct()
{
    stopAction(fireAct);
    runAction(explosionAct);

}