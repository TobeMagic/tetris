#pragma once
#ifndef _ELS_APP_H
#define _ELS_APP_H

#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<conio.h> // console io funtions library
#include<mmsystem.h>

//���鿪ʼ��ַ
#define StartBlockX 130
#define StratBlockY 10


//��������
#define BLOCKTYPE 28

/*��������Show_Block
���ܣ���ʾ����
��������ǰ��ʾ�������ͣ���ʼλ��xy
����ֵ����
*/
void App_Show_Block(int,int,int);

/*��������Clear_Block
���ܣ��������
��������ǰ��ʾ�������ͣ���ʼλ��xy
����ֵ����
*/
void App_Clear_Block(int type, int X, int Y);

/*��������CraateDef
���ܣ���ʼ������
�������޲���
����ֵ����
*/
void App_CreateDef();

/*��������RemoveBlock
���ܣ������ƶ�
�������޲���
����ֵ����
*/
void App_RunGame();

/*��������App_RolckIsDown
���ܣ��ж��Ƿ񴥵�
��������ǰ��ʾ�������ͣ���ʼλ��xy
����ֵ������-0��������-1
*/
int App_RolckIsDown(int type, int X, int Y);

/*��������App_MarkMap
����:��ǵ�ͼ
��������ǰ��ʾ�������ͣ���ʼλ��xy
����ֵ����
*/
void App_MarkMap(int type, int X, int Y);

/*��������App_ShowMap
����:��ʾ�ѱ�ǵ�ͼ
��������
����ֵ����
*/
void App_ShowMap();

/*��������App_GMonitorKey
����: ��Ϸ��������������
��������
����ֵ����
*/
void App_GMonitorKey(int type, int X, int Y);

/*��������App_RolckIsRight
����:ʶ�𷽿��Ƿ��ұ߿�
�������������ͣ���ǰ����X,Y
����ֵ�����׷���1.��Ϊ0
*/
int App_RolckIsRight(int type, int X, int Y);

/*��������App_RolckIsLeft
����:ʶ�𷽿��Ƿ���߿�
�������������ͣ���ǰ����X,Y
����ֵ�����׷���1.��Ϊ0
*/
int App_RolckIsLeft(int type, int X, int Y);

/*��������App_RotationIsTouch
����:ʶ�𷽿��Ƿ���߿�
�������������ͣ���ǰ����X,Y
����ֵ�����׷���1.��Ϊ0
*/
int App_RotationIsTouch(int type, int X, int Y);

/*��������App_GameOver
����: �ж���Ϸ����
��������
����ֵ��1-���鵽����0-����û������
*/
int App_GameOver();


/*��������App_GameRunNest
����: ������Ƕ����
��������
����ֵ����
*/
void App_GameRunNest();


/*��������App_GameRemoveLine
����: ���к���
��������
����ֵ����
*/
void App_GameRemoveLine();

/*��������UI_LoadMusicR
����:������������
��������
����ֵ����
*/
void APP_LoadMusicR();

/*��������APP_LoadMusic
����:������Ϸ����
��������
����ֵ����
*/
void  APP_LoadMusic();

/*��������Easter_Egg
����:��Ϸ�ʵ�
��������
����ֵ����
*/
void  Easter_Egg();


/*��������Load_maxscore
����:������߷���
��������
����ֵ����
*/
void  Load_maxscore();

/*��������Show_score
����:չʾ��߷���
��������
����ֵ����
*/
void  Show_score();
#endif