#ifndef _ELS_DEF_H
#define _ELS_DEF_H

#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>


//窗口长
#define InterfaceX 500 
//窗口宽
#define InterfaceY 620

//游戏区起始点横坐标
#define GameViewX_1 10 
//游戏区起始点纵坐标
#define GameViewY_1 10
//游戏区终点横坐标
#define GameViewX_2 310
//游戏区终点纵坐标
#define GameViewY_2 610


//分数显示起始点横坐标
#define GameScoreX_1 320
//分数显示起始点纵坐标
#define GameScoreY_1 220
//分数显示终点横坐标
#define GameScoreX_2 490
//分数显示终点纵坐标
#define GameScoreY_2 380

//提示框起始点横坐标
#define GameRemindX_1 320
//提示框起始点纵坐标
#define GameRemindY_1 10
//提示框终点横坐标
#define GameRemindX_2 490
//提示框终点纵坐标
#define GameRemindY_2 210

//操作介绍框起始点横坐标
#define GameOperaX_1 320
//操作介绍框起始点纵坐标
#define GameOperaY_1 390
//操作介绍框终横坐标
#define GameOperaX_2 490
//操作介绍框终点纵坐标
#define GameOperaY_2 610



/*函数名：UI_StartView
功能：游戏开始倒计时
参数：无参数
返回值：无
*/
void UI_StartView();

/*函数名：UI_GameView
功能：显示游戏主界面
参数：无参数
返回值：无
*/
void UI_GameView();

/*函数名：WelcomeView
功能：游戏欢迎界面
参数：无参数
返回值：无
*/
void UI_WelcomeView();

/*函数名：BackImage
功能：显示游戏背景
参数：无参数
返回值：无
*/
void UI_LoadImage();

/*函数名：UI_LoadMusicT
功能:加载音乐
参数：无
返回值：无
*/
void UI_LoadMusicT();

#endif // !_ELS_DEF_H

