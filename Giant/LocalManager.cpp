////
////  LocalManager.cpp
////  Giant
////
////  Created by kanon on 13-9-5.
////
////
//
#include "LocalManager.h"

#define XML_BUFFER_SIZE		(512)

static char * s_pBuffer = new char(512);
static LocalManager * m_localManager = NULL;

//获取单例
LocalManager* LocalManager::sharedLocalManager()
{
    
   if (!m_localManager) {
       m_localManager = new LocalManager();
   }
    
    return m_localManager;
    
}


//获取xml路径
static const char * XML_PATH(const char * fileName)
{
	memset(s_pBuffer, 0, XML_BUFFER_SIZE);
    
#if defined(ANDROID)
	strcpy(s_pBuffer, (cocos2d::CCFileUtils::sharedFileUtils()->getWritablePath() + fileName).c_str());
#else
	strcpy(s_pBuffer, cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName).c_str());
#endif
    
	CCLog("CSV路径：%s", s_pBuffer);
    
	return s_pBuffer;
}


//加载巨人属性xml
void LocalManager::loadGiantXml()
{
    const char * path = XML_PATH("giant.xml");
    
    TiXmlDocument* giantDoc = new TiXmlDocument(path);
    giantDoc->LoadFile();
    
    bool loadOkay = giantDoc->LoadFile();
    // faile to load 'phonebookdata.xml'.
    if (!loadOkay) {
        printf( "Could not load test file %s. Error='%s'. Exiting.\n", path,giantDoc->ErrorDesc() );
        exit( 1 );
    }
    
    //根节点
    TiXmlElement* rootElemnt = giantDoc->RootElement();
    TiXmlElement* item;
    //遍历xml
    for (item = rootElemnt->FirstChildElement("item"); item; item = item->NextSiblingElement("item"))
    {
        
        GiantData *giantData = new GiantData();
        giantData->idGint = GTool::getIntFromString(item->Attribute("id"));
        CCLog("-----------id=%d",giantData->idGint);
        giantData->name = item->Attribute("name");
        
         CCLog("-----------name=%s",giantData->name.c_str());
        giantData->health = GTool::getFloatFromString(item->Attribute("health"));
        giantData->awarldID = GTool::getIntFromString(item->Attribute("awardId"));
        giantData->awarldType = GTool::getIntFromString(item->Attribute("awarldType"));
        giantData->awarldCount = GTool::getIntFromString(item->Attribute("awarldCount"));
        giantData->speed = GTool::getIntFromString(item->Attribute("speed"));
        giantData->awaitProbability = GTool::getFloatFromString(item->Attribute("awaitProbability"));
        giantData->cowrieProbability = GTool::getFloatFromString(item->Attribute("cowrieProbability"));
        giantData->killProbability = GTool::getFloatFromString(item->Attribute("killProbability"));
        giantData->invalidismProbability = GTool::getFloatFromString(item->Attribute("invalidismProbability"));
        giantData->resourceID = GTool::getFloatFromString(item->Attribute("resourceID"));

        
        allGintData.push_back(giantData);
    }
    
}










