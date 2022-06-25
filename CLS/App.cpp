#define _CRT_SECURE_NO_WARNINGS
#include"App.h"
#include"UI.h"
#pragma comment(lib,"winmm.lib")	
int Startblockx = StartBlockX;
int Startblocky = StratBlockY;

int Blocknow; //当前方块类型
int Blocknext; //下一个方块类型
int G_Map[20][10] = {0};//游戏地图数组，必须要先赋第一个值，不然其他不会默认为0
int	score = 0; //游戏当前分数 
char str[5] = { 0 };
int max_score ; //最高分数记录
char strmax[5] = { 0 };
int multipleScore = 0; //分数变化量级

	//方块图像
	int Block[BLOCKTYPE][4][4] =
	{
		//I形方块
	{
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
	},
	{
		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0,
	},
	{
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
	},
	{
		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0,
	},
	//L形方块
	{
		1,0,0,0,
		1,0,0,0,
		1,1,0,0,
		0,0,0,0,
	},
	{
		1,1,1,0,
		1,0,0,0,
		0,0,0,0,
		0,0,0,0,
	},
	{
		1,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,0,0,0,
	},
	{
		0,0,1,0,
		1,1,1,0,
		0,0,0,0,
		0,0,0,0,
	},
	//T型
	{
		0,0,0,0,
		1,1,1,0,
		0,1,0,0,
		0,0,0,0,
	},
	{
		1,0,0,0,
		1,1,0,0,
		1,0,0,0,
		0,0,0,0,
	},
	{
		0,1,0,0,
		1,1,1,0,
		0,0,0,0,
		0,0,0,0,
	},
	{
		0,1,0,0,
		1,1,0,0,
		0,1,0,0,
		0,0,0,0,
	},
	//田字形
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,
	},
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,
	},
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,
	},
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,
	},
	//反L型
	{
		0,1,0,0,
		0,1,0,0,
		1,1,0,0,
		0,0,0,0,
	},
	{
		0,0,0,0,
		1,1,1,0,
		0,0,1,0,
		0,0,0,0,
	},
	{
		0,1,1,0,
		0,1,0,0,
		0,1,0,0,
		0,0,0,0,
	},
	{
		1,0,0,0,
		1,1,1,0,
		0,0,0,0,
		0,0,0,0,
	},
	// 错位型
	{
		0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0,
	},
	{
	  0,1,0,0,
	  1,1,0,0,
	  1,0,0,0,
	  0,0,0,0,
	},
	{
	  1,1,0,0,
	  0,1,1,0,
	  0,0,0,0,
	  0,0,0,0,
	 },
	{
	  0,0,1,0,
	  0,1,1,0,
	  0,1,0,0,
	  0,0,0,0,
	 },
	 //反错位型
	{
	  0,0,0,0,
	  0,1,1,0,
	  1,1,0,0,
	  0,0,0,0,
	 },
	{
	  0,1,0,0,
	  0,1,1,0,
	  0,0,1,0,
	  0,0,0,0,
	 },
	{
	  0,0,0,0,
	  0,1,1,0,
	  1,1,0,0,
	  0,0,0,0,
	 },
	{
	  0,1,0,0,
	  0,1,1,0,
	  0,0,1,0,
	  0,0,0,0,
	},
	};


/*函数名：App_Show_Block
功能:显示方块
参数：方块类型，坐标X,Y
返回值：无
*/
void App_Show_Block(int type,int X,int Y)
{
	settextstyle(30, 0, _T("黑体"));
	setcolor(RGB(200, 130, 40));
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				outtextxy(X + y * 30, Y + x * 30, "■");
			}
		}
}

/*函数名：App_Clear_Block
功能:清楚方块
参数：方块类型，坐标X,Y
返回值：无
*/
void App_Clear_Block(int type,int X,int Y)
{
	//与背景颜色一致
	setcolor(WHITE);
	settextstyle(30, 0, _T("黑体"));
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				outtextxy(X + y * 30, Y + x * 30, "■");
			}
		}
}
/*函数名：App_CreateDef
功能:初始化处理函数
参数：无
返回值：无
*/
void App_CreateDef()
{

	srand(time(NULL));
	Blocknow = rand() % BLOCKTYPE;
	Blocknext = rand() % BLOCKTYPE;
	//APP_LoadMusicR();//加载音乐
}

/*函数名：App_RunGame
功能:方块移动
参数：无
返回值：无
*/
void App_RunGame()
{
	while (1)
	{
		score = 0; 
		//清除地图
		memset(G_Map, 0, sizeof(G_Map));
		UI_StartView();
		UI_GameView();
		App_GameRunNest();  
		multipleScore = 0;
		cleardevice();
		
	}
	
}

/*函数名：App_RolckIsDown
功能:识别方块是否触底
参数：方块类型，当前方块X,Y
返回值：触底返回1.否为0
*/
int App_RolckIsDown(int type,int X,int Y)
	{
	int judge;
	int m, n;
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				judge = Y + x * 30;
				n = (X - 10) / 30 + y;
				m = (Y - 10) / 30 + x;
				if (judge == 580 || G_Map[m+1][n] == 1)
				{
				return 1;
				}
			}
		}
	return 0;
}

/*函数名：App_MarkMap
功能:标记地图
参数：当前显示方块类型，起始位置xy
返回值：无
*/
void App_MarkMap(int type, int X, int Y)
{
	int m, n;
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				n = (X - 10) / 30 + y;
				m = (Y - 10) / 30 + x;
				G_Map[m][n] = 1;
			}
		}
}

/*函数名：App_ShowMap
功能:显示已标记地图
参数：无
返回值：无
*/
void App_ShowMap()
{
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			printf("%d ", G_Map[x][y]);
		}
		 
		printf("\n");
	}
}

/*函数名：App_MonitorKey
功能:按键监听函数
参数：方块类型，当前方块X,Y
返回值：无
*/
void App_GMonitorKey(int type, int X, int Y)
{
		_getch();
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (!App_RolckIsLeft(type, X, Y))
			{
				Startblockx -= 30;
				printf("按下左健");
			}

		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			if (!App_RolckIsRight(type, X, Y))
			{
				Startblockx += 30;
				printf("按下右健");
			}

		}
		else if (GetAsyncKeyState(VK_UP))
		{
			if (((Blocknow+1) % 4 == 0) && (App_RotationIsTouch(type, X, Y) == 0))
			{
				Blocknow -= 3;
			}
			else if (((Blocknow + 1) % 4 != 0) && App_RotationIsTouch(type, X, Y) == 0)
			{
				Blocknow += 1;
			}
			
			printf("按下上健");

		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (!App_RolckIsDown(type, X, Y))

			{
				Startblocky += 30;
				printf("按下下健");
			}
		}

		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			App_Show_Block(Blocknow, Startblockx, Startblocky);
			mciSendString("close gamerun", NULL, 0, 0);
			while (1)
			{
				
				if (GetAsyncKeyState(VK_ESCAPE))
				{
					APP_LoadMusic();
					App_Clear_Block(Blocknow, Startblockx, Startblocky);
					
					break;
				}

			}
		}
}

/*函数名：App_RolckIsLeft
功能:识别方块是否触左边框
参数：方块类型，当前方块X,Y
返回值：触底返回1.否为0
*/
int App_RolckIsLeft(int type, int X, int Y)
{
	int judge,n,m;
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				judge = X + y * 30;
				n = (X - 10) / 30 + y;
				m = (Y - 10) / 30 + x;
				if (judge == 10 || G_Map[m][n-1] == 1)
				{
					return 1;
				}

			}
		}
	return 0;
}
/*函数名：App_RolckIsRight
功能:识别方块是否触右边框
参数：方块类型，当前方块X,Y
返回值：触底返回1.否为0
*/
int App_RolckIsRight(int type,int X,int Y)
	{
	int judge,n,m;
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				n = (X - 10) / 30 + y;
				m = (Y - 10) / 30 + x;
				judge = X + y * 30;
				if (judge == 280 || G_Map[m][n+1] == 1)
				{
				return 1;
				}
			}
		}
	return 0;
}

/*函数名：App_RotationIsTouch
功能:识别方块是否触左边框
参数：方块类型，当前方块X,Y
返回值：触底返回1.否为0
*/
int App_RotationIsTouch(int type, int X, int Y)
{
	int judgeX, judgeY,m,n;
	if ((type+1) % 4 == 0)
	{
		type -= 3;
	}
	else
	{
		type += 1;
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				judgeX = X + y * 30;
				judgeY = Y + x * 30;
				n = (X - 10) / 30 + y;
				m = (Y - 10) / 30 + x;
				if (judgeX <= 10 || G_Map[m][n] == 1)
				{
					return 1;
				}
				else if (judgeX >= 280 || G_Map[m][n] == 1)
				{
					return 1;
				}
				else if (judgeY >= 580 || G_Map[m][n] == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

/*函数名：App_GameOver
功能: 判断游戏结束
参数：无
返回值：1-方块到顶格，0-方块没到顶格
*/
int App_GameOver()
{
	for(int i = 0; i < 10; i++)
		if (G_Map[0][i] == 1)
		{
			return 1;
		}
	return 0;
}

/*函数名：App_GameRunNest
功能: 运行内嵌函数
参数：无
返回值：无
*/
void App_GameRunNest()
{
	//播放音乐
	APP_LoadMusic();
	while (1)//死循环，不会消失窗口
	{

		//判断是否触底
		if (App_RolckIsDown(Blocknow, Startblockx, Startblocky) == 1)
		{  
			App_MarkMap(Blocknow, Startblockx, Startblocky);
			App_ShowMap(); //用于测试地图
			//判断游戏是否结束
			if (App_GameOver())
			{
				settextstyle(40, 0, "黑体");
				settextcolor(RGB(20, 100, 300));
				outtextxy(100, 300, "GAME OVER!!");
				settextstyle(10, 0, "黑体");
				settextcolor(RED);
				outtextxy(100, 260, "按Shift键返回主页面");
				outtextxy(100, 280, "按空格键重新开始游戏");
				_getch();
				if (GetAsyncKeyState(VK_SPACE))
				{
					Sleep(100);
					break;
				}
				else if (GetAsyncKeyState(VK_SHIFT))
				{
					mciSendString("close gamerun", NULL, 0, 0);
					closegraph();
					UI_WelcomeView();
					App_RunGame();
				}

			}
			
			Startblockx = StartBlockX;
			Startblocky = StratBlockY;
			Blocknow = Blocknext;
			App_Clear_Block(Blocknext, 350, 50);
			Blocknext = rand() % BLOCKTYPE;
			App_GameOver();
		}
		else
		{
			Load_maxscore();
			
			
			Show_score(); // 分数显示 
			App_GameRemoveLine();  // 消行

			App_Clear_Block(Blocknow, Startblockx, Startblocky); // 方块移动
			Startblocky += 30;
			App_GMonitorKey(Blocknow, Startblockx, Startblocky); //按键监听
			App_Show_Block(Blocknow, Startblockx, Startblocky);
			App_Show_Block(Blocknext, 350, 50);

			Sleep(200);
				
		}

	}
}

/*函数名：App_GameRemoveLine
功能: 消行函数
参数：无
返回值：无
*/
void App_GameRemoveLine()
{
	for (int j = 19; j >= 0; j--)
	{
		int i = 0;
		
		for (; i < 10; i++)
		{
			//判断改行是否满行
			if (G_Map[j][i] == 0)
			{
				break;
			}
		}

		//此时需要消第j行
		if (i == 10)
		{	
			multipleScore += 8;
			//更新地图
			for (int y = j; y > 0; y--)
			{
				for (int x = 0; x < 10; x++)
				{
					G_Map[y][x] = G_Map[y - 1][x];
				}
			}
			cleardevice();
			UI_GameView();
			APP_LoadMusicR();
			//重新绘制方块
			for (int m = 0; m < 20; m++)
			{
				for (int n = 0; n < 10; n++)
				{
					if (G_Map[m][n] == 1)
					{
						settextstyle(30, 0, _T("黑体"));
						setcolor(RGB(200, 130, 40));
						outtextxy(10 + n * 30, 10 + m * 30, "■");
						//mciSendString("close bgmclear", NULL, 0, 0);
					}
				}
			}

			//分数变化
			score += multipleScore;
			if (score >= 10)
			{
				closegraph();
				mciSendString("close gamerun", NULL, 0, 0);
				Easter_Egg();
			}
					}

	}
}

/*函数名：APP_LoadMusicR
功能:加载消行音乐
参数：无
返回值：无
*/
void  APP_LoadMusicR()
{
	//open 是一个命令 必须要空格 不然系统无法辨识
	mciSendString("open  ./Music/消行.mp3  alias bgmclear", NULL, 0, 0);
	mciSendString("play bgmclear from 9", NULL, 0, 0);
}

/*函数名：APP_LoadMusic
功能:加载游戏音乐
参数：无
返回值：无
*/
void  APP_LoadMusic()
{
	//播放音乐
	mciSendString("open  ./Music/游戏中.mp3  alias gamerun", NULL, 0, 0);
	mciSendString("play gamerun repeat", NULL, 0, 0);
}


#define MAXSTAR 28000	// 星星总数
struct STAR             //星星结构体
{
	double	x;
	int		y;
	double	step;
	int		color;
};
STAR star[MAXSTAR];

/*函数名：Easter_Egg
功能:游戏彩蛋
参数：无
返回值：无
*/
void  Easter_Egg()
{

		initgraph(640, 480);			// 创建绘图窗口
		mciSendString("open  ./Music/彩蛋.mp3  alias egg", NULL, 0, 0);
		mciSendString("play egg", NULL, 0, 0);

		
	
		
		// 初始化所有星星
		for (int i = 0; i < MAXSTAR; i++)
		{
			star[i].x = 0;
			star[i].y = rand() % 480;
			star[i].step = (rand() % 5000) / 1000.0 + 1;
			star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
			star[i].color = RGB(star[i].color, star[i].color, star[i].color);
			star[i].x = rand() % 640;
		}

		// 绘制星空，按任意键退出
		while (!_kbhit())
		{
		
			//文字说明
			settextcolor(RGB(180, 200, 20));
			settextstyle(20, 0, "仿宋");
			outtextxy(100, 260, "恭喜您通关");
			/*outtextxy(150, 180, "我爱你");
			outtextxy(150, 220, "眼里都是你，亿万星辰犹不及。");
			outtextxy(150, 250, "星河璀璨，全宇宙的视野，只有你一人");*/
			settextcolor(RGB(18, 200, 20));
			settextstyle(30, 0, "仿宋");
			//outtextxy(250, 340, "LOVER");
			for (int i = 0; i < MAXSTAR; i++)
			{
				// 擦掉原来的星星
				putpixel((int)star[i].x, star[i].y, 0);
					
				// 计算新位置
				star[i].x += star[i].step;
				if (star[i].x > 640)
				{
					star[i].x = 0;
					star[i].y = rand() % 480;
					star[i].step = (rand() % 5000) / 1000.0 + 1;
					star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
					star[i].color = RGB(star[i].color, star[i].color, star[i].color);
				}
				// 画新星星
				putpixel((int)star[i].x, star[i].y, star[i].color);
			}
			Sleep(20);
		}

		closegraph();					// 关闭绘图窗口
}

/*函数名：Load_maxscore
功能:加载最高分数
参数：无
返回值：无
*/
void  Load_maxscore()
{
	// 记录最高分记录
	FILE* f1 = fopen("./max_score.txt", "r"); //读取
	if (f1 == NULL)
	{
		settextstyle(26, 0, _T("仿宋"));
		settextcolor(RED);
		outtextxy(393, 285, "打开文件失败！！");
	}
	else
	{
		fscanf(f1, "%d", &max_score);
		printf("%d", max_score);
		fclose(f1);
		if (score > max_score)
		{
			
			FILE* f2 = fopen("./max_score.txt", "w"); //写入
			if (f2 == NULL)
			{
				settextstyle(26, 0, _T("仿宋"));
				settextcolor(RED);
				outtextxy(393, 285, "打开文件失败！！");
			}
			else
			{
				
				fprintf(f2, "%d", score);	
				fclose(f2);
			}
		}
	}
}

/*函数名：Show_score
功能:加载最高分数
参数：无
返回值：无
*/
void  Show_score()
{
	// 显示当前分数
	_itoa_s(score, str, 10);
	settextstyle(20, 0, _T("仿宋"));
	settextcolor(RED);
	outtextxy(393, 285, str);


	// 显示最高分数
	settextstyle(30	, 0, _T("黑体"));
	setcolor(RGB(153, 217, 234));
	outtextxy(390, 340, "■");
	settextstyle(20, 0, _T("仿宋"));
	settextcolor(RED);
	_itoa_s(max_score, strmax, 10);
	outtextxy(390, 340, strmax);
}
