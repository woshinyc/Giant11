#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "LogicDriver.h"
#include "SCSprite.h"
#include "HTTPHelper.h"

using namespace std;

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance

void HelloWorld::aaa(CCNode *node)
{
    SCSprite *sp=(SCSprite *)node;
    printf("ddddddd%d  hp =%d",n,sp->getHp());
    
}

void HelloWorld::httpResponseCallback(CCNode *node,void *data)
{


}
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    n=100;
    SEL_CallFuncN aa=(SEL_CallFuncN)(&HelloWorld::aaa);
   SCSprite*sp=SCSprite::create("Icon-Small-50.png",this,aa);
    sp->setHp(10);
    sp->setMp(20);
    sp->runAction(CCMoveBy::create(30, ccp(400, 400)));
    this->addChild(sp);
    
    HTTPHelper::shared()->post("url", this, callfuncND_selector(HelloWorld::httpResponseCallback));

    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



// typedef int (*FP_CALC)(int, int);
// //注意这里不是函数声明而是函数定义，它是一个地址，你可以直接输出add看看
// int add(int a, int b)
// {
//         return a + b;
// }
//
//
// int sub(int a, int b)
// {
//       return a - b;
//  }
// int mul(int a, int b)
// {
//         return a * b;
//}
// int HelloWorld::diva(int a, int b)
// {
//    return b? a/b : -1;
// }
//
//
//
// FP_CALC HelloWorld::calc_func(char op)
// {
//      switch (op)
//       {
//        case '+': return add;//返回函数的地址
//        case '-': return sub;
//        case '*': return mul;
//        case '/': return diva;
//        default:
//             return NULL;
//        }
//       return NULL;   
//  }   



