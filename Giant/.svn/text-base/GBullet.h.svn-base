//
//  GBullet.h
//  Giant
//
//  Created by Mac on 13-9-6.
//
//

#ifndef __Giant__GBullet__
#define __Giant__GBullet__

#include <iostream>
#include "DBaseSprite.h"

class GBullet:public DBaseSprite
{
private:
    void deployBullet();
    CCAction *fireAct;
    CCAction *explosionAct;
    void callBack(CCNode *nnn);
public:
    static GBullet*build();
    void playFireAct();
    void playExplosionAct();
    


};
#endif /* defined(__Giant__GBullet__) */
