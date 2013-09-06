//
//  GTool.cpp
//  Giant
//
//  Created by Mac on 13-9-3.
//
//

#include "GTool.h"
std::string GTool::formartTimeToString(int timeStamp)
{
    std::string str ;
    
    time_t time = timeStamp;
    tm * localnow = localtime(&time);
    
    int mon = localnow->tm_mon;
    int day = localnow->tm_mday;
    int whour = localnow->tm_hour;
    int wminute = localnow->tm_min;
    int wsecond = localnow->tm_sec;
    
    //    int wminute = timeStamp / 60 ;
    //    int wsecond = timeStamp % 60 ;
    
    str = CCString::createWithFormat("%02d点:%02d分",whour,wminute)->getCString() ;
    
    return str ;
}


//获取随机数
int GTool::getRandomInt(float max,float min){
    srand(millisecondNow());
	// Determine speed of the target
	float minDuration = min;
	float maxDuration = max;
	int rangeDuration = (int)(maxDuration - minDuration);
	int actualDuration = ( rand() % rangeDuration ) + (int)minDuration;
    
    //	CCLOG("random value:%d",actualDuration);
	return actualDuration;
}

long GTool::millisecondNow()
{
	struct cc_timeval now;
	CCTime::gettimeofdayCocos2d(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
    
}

//字符串转int
string GTool::getStringFromInt(int intvalue){
	char strFileName[64];
	sprintf(strFileName,"%d",intvalue);
	string result=strFileName;
	return result;
}

//string转long
string GTool::getStringFromLongLong(long long longvalue){
	char strFileName[64];
    
	sprintf(strFileName,"%lld",longvalue);
	string result=strFileName;
	return result;
}

//string转float
string GTool::getStringFromFloat(float floatvalue)
{
    char strFileName[64];
    
	sprintf(strFileName,"%f",floatvalue);
	string result=strFileName;
	return result;
}

//int转string
int GTool::getIntFromString(const char * str){
	int n=-1;
	n = atoi(str);
	return n;
}

//long转string
long GTool::getLongFromString( const char* str )
{
	long n = -1;
	n = atol(str);
	return n;
}

//float转string
float GTool::getFloatFromString( const char* str)
{
    float n = -1;
    n = atof(str);
    return n;
}

//string转bool
string GTool::getStrnigFromBool(bool flag)
{
	if (flag)
	{
		return "true";
	}
	else
	{
		return "false";
	}
}

//bool转string
bool GTool::getBoolFromeString( const char* str )
{
	if( "TRUE" == string(str) || "true" == string(str) || "真" == string(str) || getIntFromString(str)>0 )
		return true;
	return false;
}






