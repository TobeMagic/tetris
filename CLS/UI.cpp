#define _CRT_SECURE_NO_WARNINGS
#include"UI.h"


//设置图片类
IMAGE BeginImage;
IMAGE GameImage;
IMAGE ExplainImage;

/*函数名：UI_WelcomeView
功能:游戏欢迎界面
参数：无
返回值：无
*/
void UI_WelcomeView()
{
	
	initgraph(700, 500); 
	// set background mode 
	setbkmode(TRANSPARENT);
	putimage(0, 0, &BeginImage);
	

	setcolor(BLACK);
	settextstyle(45, 0, _T("楷体"));
	outtextxy(150, 150, "Welcome to the Game");

	settextstyle(18, 0, _T("仿宋"));
	setcolor(RGB(20, 20, 120));
	outtextxy(230, 460, "--按空格键开始游戏--");
	settextstyle(12, 0, _T("仿宋"));
	setcolor(RGB(20, 20, 200));
	outtextxy(250, 450, "查看游戏说明按ESC");
	while (1)
	{
		  
		_getch();
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			cleardevice();
				putimage(0, 0, &ExplainImage);
				settextcolor(RGB(15, 10, 204));
				settextstyle(23, 0, _T("仿宋"));
				outtextxy(150, 70, "游戏介绍");
				outtextxy(50, 100, "俄罗斯方块是一个老少咸宜的小游戏，它实现有");
				outtextxy(50, 120, "四个正方形的色块组成，然后存储于一个数");
				outtextxy(50, 140, "组的四个元素中，计算机随机产生七种不同类型的");
				outtextxy(50, 160, "方块，根据计算机时钟控制它在一定的时间");
				outtextxy(50, 180, "不停的产生，用户根据键盘的四个方向键进行向");
				outtextxy(50, 200, "左，向右，向下，翻转操作,暂停。");
				setcolor(RGB(20, 20, 120));
				outtextxy(450, 230, "操作说明:");
				outtextxy(450, 260, "←：向左移动");
				outtextxy(450, 290, "↓：向下移动");
				outtextxy(450, 320, "→：向右移动");
				outtextxy(450, 350, "↑：方块旋转");
				outtextxy(450, 380, "Esc：暂停游戏");

				settextstyle(18, 0, _T("仿宋"));
				setcolor(RGB(20, 20, 120));
				outtextxy(230, 460, "--按Tab返回主页面--");
				while (1)
				{

					_getch();
					if (GetAsyncKeyState(VK_TAB))
					{
						break;
					}
				}

				UI_WelcomeView();
		}
			
	}
	
}	
/*函数名：UI_StartView
功能:游戏开始倒计时
参数：无
返回值：无
*/
void UI_StartView()
{
	closegraph();
	//存放num转化字符 并留一个‘/0’所以str[2]长度为2
	char str[2] = { 0 };

	//创建游戏窗口        特别注意事项：这里的控制台窗口显示不是因为 printf 第三个参数
	                     //而是在用该函数创建窗口 可以选择是否 显示控制台  	initgraph(InterfaceX, InterfaceY,SHOWCONSOLE);
	initgraph(InterfaceX, InterfaceY);

	//字体大小及风格
	settextstyle(30, 0, _T("仿宋"));
	//文字输出
	outtextxy(110, 180, "俄罗斯方块开始倒计时");
	//加载音乐倒计时
	UI_LoadMusicT();
	//关闭音乐
	mciSendString("close gamerun", NULL, 0, 0);
	for (int num = 3; num > 0; num--)
	{
		//整数 
		_itoa_s(num, str,10);
		//sprintf(str, "%c", num);
		outtextxy(240, 480, str);
		//设置播放起点 from 时间点 或者重复播放 repeat
		
		//延时	
		Sleep(1000); //1-1ms
	}
}

/*函数名：UI_GameView
功能:显示游戏主界面
参数：无
返回值：无
*/
void UI_GameView()
{
	//清屏函数
	cleardevice();
	//必须要先清屏，不然会报错
	
	//显示图片背景
	setbkmode(TRANSPARENT);
	putimage(0, 0, &GameImage);

	//字体大小及风格
	settextstyle(20, 0, _T("仿宋"));
	/*
	//游戏区域
	rectangle(GameViewX_1, GameViewY_1, GameViewX_2, GameViewY_2);
	//操作说明框
	rectangle(GameOperaX_1, GameOperaY_1, GameOperaX_2, GameOperaY_2);
	//分数 级别框
	rectangle(GameScoreX_1, GameScoreY_1, GameScoreX_2, GameScoreY_2);
	//显示下一个方块框
	rectangle(GameRemindX_1, GameRemindY_1, GameRemindX_2, GameRemindY_2);
	*/
	
	//文本提示框
	settextcolor(BLACK);
	outtextxy(350,195,"下一个方块");
	settextcolor(RED);
	outtextxy(380,260,"分数");

	outtextxy(370,315,"最高分数");

	//操作说明
	//颜色也可以用RGB红绿蓝RGB(225,225,225)和十六进制一样的
	settextcolor(RGB(150,105,204));
	outtextxy(337,410,"操作说明:");
	outtextxy(337,440,"←：向左移动");
	outtextxy(337,470,"↓：向下移动");
	outtextxy(337,500,"→：向右移动");
	outtextxy(337,530,"↑：方块旋转");
	outtextxy(337,560,"Esc：暂停游戏");


}

/*函数名：UI_LoadImage
功能:加载图片
参数：无
返回值：无
*/
void UI_LoadImage()
{
	loadimage(&BeginImage, "img/R-C (2).jpg",700,500,0);
	loadimage(&ExplainImage, "img/Backg.jpg",700,500,0);
	loadimage(&GameImage, "img/back1.jpg",500,620,0);
}

/*函数名：UI_LoadMusicT
功能:加载倒计时音乐
参数：无
返回值：无
*/
void UI_LoadMusicT()
{
	//open 是一个命令 必须要空格 不然系统无法辨识
	mciSendString("open ./Music/倒计时.mp3 alias bgm_time", NULL, 0, 0);
	mciSendString("play  bgm_time from 0", NULL, 0, 0);
}