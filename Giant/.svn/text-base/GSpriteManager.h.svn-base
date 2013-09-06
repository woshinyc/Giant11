//
//  GSpriteManager.h
//  Giant
//
//  Created by Mac on 13-9-6.
//
//

#ifndef __Giant__GSpriteManager__
#define __Giant__GSpriteManager__

#include <iostream>
#include "cocos2d.h"
#include "GBullet.h"
USING_NS_CC;
using namespace std;
class GSpriteManager
{
private:
public:
    static  GSpriteManager *shared();
    
    //***************子弹->
    GBullet* getBullet();
    void setFreeBullet(GBullet *freeBullet);
//vector<GBullet *> v_using_bullet;
    CCArray * arr_using_bullet;
vector<GBullet *> v_free_bullet;
    //***************/子弹

};
#endif /* defined(__Giant__GSpriteManager__) */
