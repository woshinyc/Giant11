//
//  GTool.h
//  Giant
//
//  Created by Mac on 13-9-3.
//
//

#ifndef __Giant__GTool__
#define __Giant__GTool__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include <regex.h>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

#define ccps(_x,_y) ccp(CCDirector::sharedDirector()->getWinSize().width * (_x) ,CCDirector::sharedDirector()->getWinSize().height * (_y))

#define ccpsprite(_x ,_y , sprite) ccp(sprite->getContentSize().width * (_x) , sprite->getContentSize().height * (_y))
#define radianAandOrigin(_a,_o) ccpToAngle(ccpSub(_a,_o))

typedef std::vector<std::string> strArray;

class GTool
{
public:
    /**
     *  图片资源缩放适配
     */
    inline static float scaleFitXY(CCSize res, CCSize des)
    {
        float trsW = des.width/res.width;
        float trsH = des.height/res.height;
        return trsH < trsW ? trsH : trsW;
    }
    inline static float scaleFitX(CCSize res, CCSize des)
    {
        float trsW = des.width/res.width;
        return trsW;
    }
    inline static float scaleFitY(CCSize res, CCSize des)
    {
        float trsH = des.height/res.height;
        return trsH;
    }
    static bool isEmail(const char *email)
    {
        const char *eset = "[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
        regex_t   re = regex_t();
        regmatch_t   subs[10];
        regex_t stuRT;
        
        regcomp(&stuRT, eset, REG_EXTENDED);
        int err = regexec(&stuRT, email, (size_t)10, subs, 0);
        
        if (err) {
            
            regfree   (&re);
            return false;
        }
        else
        {
            regfree   (&re);
            return true;
        }
        
    }
    
    static std::string formartTimeToString(int timeStamp) ;
    
    //获取随机数
    static int getRandomInt(float max,float min);
    static long millisecondNow(void);
    //字符串转int
	static string getStringFromInt(int intvalue);
    //string转long
	static string getStringFromLongLong(long long longvalue);
    //string转float
    static string getStringFromFloat(float floatvalue);
    //int转string
	static int getIntFromString(const char * str);
    //string转bool
	static string getStrnigFromBool(bool flag);
    //bool转string
	static bool getBoolFromeString( const char* str );
    //long转string
	static long getLongFromString( const char* str );
    //float转string
    static float getFloatFromString( const char* str);



};
#endif /* defined(__Giant__GTool__) */
