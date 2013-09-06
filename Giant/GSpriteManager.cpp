//
//  GSpriteManager.cpp
//  Giant
//
//  Created by Mac on 13-9-6.
//
//

#include "GSpriteManager.h"
#include "GGlobalScene.h"

static GSpriteManager *s_instance = NULL;
GSpriteManager *GSpriteManager::shared()
{
    if (!s_instance) {
        s_instance=new GSpriteManager();
        s_instance->arr_using_bullet=new CCArray();

    }
    return s_instance;
}

GBullet* GSpriteManager::getBullet()
{
    GBullet*bullet;
    if (v_free_bullet.size()>0) {
        CCLOG("不创建了");
        GBullet *oldBullet= (GBullet*)v_free_bullet.back();
        v_free_bullet.pop_back();
        bullet=oldBullet;
       
    }else{
        CCLOG("创建");
        bullet=GBullet::build();
    }
    CCLog("zidanshu=%d",arr_using_bullet->count());
    arr_using_bullet->addObject(bullet);
    return bullet;
    
}
void GSpriteManager::setFreeBullet(GBullet *freeBullet)
{
    arr_using_bullet->removeObject(freeBullet);
    v_free_bullet.push_back(freeBullet);
    freeBullet->setVisible(false);

}