/*
auth: Majic 
theme: 俄罗斯方块
last_time:2022/5/2
*/
#include"UI.h"
#include"App.h"

//主函数，系统入口函数
int main()
{
	UI_LoadImage();
	UI_WelcomeView();
	App_CreateDef();
	App_RunGame();
	return 0;
}