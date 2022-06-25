#pragma once
#ifndef _ELS_APP_H
#define _ELS_APP_H

#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<conio.h> // console io funtions library
#include<mmsystem.h>

//方块开始地址
#define StartBlockX 130
#define StratBlockY 10


//方块类型
#define BLOCKTYPE 28

/*函数名：Show_Block
功能：显示方块
参数：当前显示方块类型，起始位置xy
返回值：无
*/
void App_Show_Block(int,int,int);

/*函数名：Clear_Block
功能：清除方块
参数：当前显示方块类型，起始位置xy
返回值：无
*/
void App_Clear_Block(int type, int X, int Y);

/*函数名：CraateDef
功能：初始化数据
参数：无参数
返回值：无
*/
void App_CreateDef();

/*函数名：RemoveBlock
功能：方块移动
参数：无参数
返回值：无
*/
void App_RunGame();

/*函数名：App_RolckIsDown
功能：判断是否触底
参数：当前显示方块类型，起始位置xy
返回值：触底-0，不触底-1
*/
int App_RolckIsDown(int type, int X, int Y);

/*函数名：App_MarkMap
功能:标记地图
参数：当前显示方块类型，起始位置xy
返回值：无
*/
void App_MarkMap(int type, int X, int Y);

/*函数名：App_ShowMap
功能:显示已标记地图
参数：无
返回值：无
*/
void App_ShowMap();

/*函数名：App_GMonitorKey
功能: 游戏区按键监听函数
参数：无
返回值：无
*/
void App_GMonitorKey(int type, int X, int Y);

/*函数名：App_RolckIsRight
功能:识别方块是否触右边框
参数：方块类型，当前方块X,Y
返回值：触底返回1.否为0
*/
int App_RolckIsRight(int type, int X, int Y);

/*函数名：App_RolckIsLeft
功能:识别方块是否触左边框
参数：方块类型，当前方块X,Y
返回值：触底返回1.否为0
*/
int App_RolckIsLeft(int type, int X, int Y);

/*函数名：App_RotationIsTouch
功能:识别方块是否触左边框
参数：方块类型，当前方块X,Y
返回值：触底返回1.否为0
*/
int App_RotationIsTouch(int type, int X, int Y);

/*函数名：App_GameOver
功能: 判断游戏结束
参数：无
返回值：1-方块到顶格，0-方块没到顶格
*/
int App_GameOver();


/*函数名：App_GameRunNest
功能: 运行内嵌函数
参数：无
返回值：无
*/
void App_GameRunNest();


/*函数名：App_GameRemoveLine
功能: 消行函数
参数：无
返回值：无
*/
void App_GameRemoveLine();

/*函数名：UI_LoadMusicR
功能:加载消行音乐
参数：无
返回值：无
*/
void APP_LoadMusicR();

/*函数名：APP_LoadMusic
功能:加载游戏音乐
参数：无
返回值：无
*/
void  APP_LoadMusic();

/*函数名：Easter_Egg
功能:游戏彩蛋
参数：无
返回值：无
*/
void  Easter_Egg();


/*函数名：Load_maxscore
功能:加载最高分数
参数：无
返回值：无
*/
void  Load_maxscore();

/*函数名：Show_score
功能:展示最高分数
参数：无
返回值：无
*/
void  Show_score();
#endif