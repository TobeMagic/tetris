#define _CRT_SECURE_NO_WARNINGS
#include"App.h"
#include"UI.h"
#pragma comment(lib,"winmm.lib")	
int Startblockx = StartBlockX;
int Startblocky = StratBlockY;

int Blocknow; //��ǰ��������
int Blocknext; //��һ����������
int G_Map[20][10] = {0};//��Ϸ��ͼ���飬����Ҫ�ȸ���һ��ֵ����Ȼ��������Ĭ��Ϊ0
int	score = 0; //��Ϸ��ǰ���� 
char str[5] = { 0 };
int max_score ; //��߷�����¼
char strmax[5] = { 0 };
int multipleScore = 0; //�����仯����

	//����ͼ��
	int Block[BLOCKTYPE][4][4] =
	{
		//I�η���
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
	//L�η���
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
	//T��
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
	//������
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
	//��L��
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
	// ��λ��
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
	 //����λ��
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


/*��������App_Show_Block
����:��ʾ����
�������������ͣ�����X,Y
����ֵ����
*/
void App_Show_Block(int type,int X,int Y)
{
	settextstyle(30, 0, _T("����"));
	setcolor(RGB(200, 130, 40));
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				outtextxy(X + y * 30, Y + x * 30, "��");
			}
		}
}

/*��������App_Clear_Block
����:�������
�������������ͣ�����X,Y
����ֵ����
*/
void App_Clear_Block(int type,int X,int Y)
{
	//�뱳����ɫһ��
	setcolor(WHITE);
	settextstyle(30, 0, _T("����"));
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (Block[type][x][y] == 1)
			{
				outtextxy(X + y * 30, Y + x * 30, "��");
			}
		}
}
/*��������App_CreateDef
����:��ʼ��������
��������
����ֵ����
*/
void App_CreateDef()
{

	srand(time(NULL));
	Blocknow = rand() % BLOCKTYPE;
	Blocknext = rand() % BLOCKTYPE;
	//APP_LoadMusicR();//��������
}

/*��������App_RunGame
����:�����ƶ�
��������
����ֵ����
*/
void App_RunGame()
{
	while (1)
	{
		score = 0; 
		//�����ͼ
		memset(G_Map, 0, sizeof(G_Map));
		UI_StartView();
		UI_GameView();
		App_GameRunNest();  
		multipleScore = 0;
		cleardevice();
		
	}
	
}

/*��������App_RolckIsDown
����:ʶ�𷽿��Ƿ񴥵�
�������������ͣ���ǰ����X,Y
����ֵ�����׷���1.��Ϊ0
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

/*��������App_MarkMap
����:��ǵ�ͼ
��������ǰ��ʾ�������ͣ���ʼλ��xy
����ֵ����
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

/*��������App_ShowMap
����:��ʾ�ѱ�ǵ�ͼ
��������
����ֵ����
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

/*��������App_MonitorKey
����:������������
�������������ͣ���ǰ����X,Y
����ֵ����
*/
void App_GMonitorKey(int type, int X, int Y)
{
		_getch();
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (!App_RolckIsLeft(type, X, Y))
			{
				Startblockx -= 30;
				printf("������");
			}

		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			if (!App_RolckIsRight(type, X, Y))
			{
				Startblockx += 30;
				printf("�����ҽ�");
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
			
			printf("�����Ͻ�");

		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (!App_RolckIsDown(type, X, Y))

			{
				Startblocky += 30;
				printf("�����½�");
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

/*��������App_RolckIsLeft
����:ʶ�𷽿��Ƿ���߿�
�������������ͣ���ǰ����X,Y
����ֵ�����׷���1.��Ϊ0
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
/*��������App_RolckIsRight
����:ʶ�𷽿��Ƿ��ұ߿�
�������������ͣ���ǰ����X,Y
����ֵ�����׷���1.��Ϊ0
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

/*��������App_RotationIsTouch
����:ʶ�𷽿��Ƿ���߿�
�������������ͣ���ǰ����X,Y
����ֵ�����׷���1.��Ϊ0
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

/*��������App_GameOver
����: �ж���Ϸ����
��������
����ֵ��1-���鵽����0-����û������
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

/*��������App_GameRunNest
����: ������Ƕ����
��������
����ֵ����
*/
void App_GameRunNest()
{
	//��������
	APP_LoadMusic();
	while (1)//��ѭ����������ʧ����
	{

		//�ж��Ƿ񴥵�
		if (App_RolckIsDown(Blocknow, Startblockx, Startblocky) == 1)
		{  
			App_MarkMap(Blocknow, Startblockx, Startblocky);
			App_ShowMap(); //���ڲ��Ե�ͼ
			//�ж���Ϸ�Ƿ����
			if (App_GameOver())
			{
				settextstyle(40, 0, "����");
				settextcolor(RGB(20, 100, 300));
				outtextxy(100, 300, "GAME OVER!!");
				settextstyle(10, 0, "����");
				settextcolor(RED);
				outtextxy(100, 260, "��Shift��������ҳ��");
				outtextxy(100, 280, "���ո�����¿�ʼ��Ϸ");
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
			
			
			Show_score(); // ������ʾ 
			App_GameRemoveLine();  // ����

			App_Clear_Block(Blocknow, Startblockx, Startblocky); // �����ƶ�
			Startblocky += 30;
			App_GMonitorKey(Blocknow, Startblockx, Startblocky); //��������
			App_Show_Block(Blocknow, Startblockx, Startblocky);
			App_Show_Block(Blocknext, 350, 50);

			Sleep(200);
				
		}

	}
}

/*��������App_GameRemoveLine
����: ���к���
��������
����ֵ����
*/
void App_GameRemoveLine()
{
	for (int j = 19; j >= 0; j--)
	{
		int i = 0;
		
		for (; i < 10; i++)
		{
			//�жϸ����Ƿ�����
			if (G_Map[j][i] == 0)
			{
				break;
			}
		}

		//��ʱ��Ҫ����j��
		if (i == 10)
		{	
			multipleScore += 8;
			//���µ�ͼ
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
			//���»��Ʒ���
			for (int m = 0; m < 20; m++)
			{
				for (int n = 0; n < 10; n++)
				{
					if (G_Map[m][n] == 1)
					{
						settextstyle(30, 0, _T("����"));
						setcolor(RGB(200, 130, 40));
						outtextxy(10 + n * 30, 10 + m * 30, "��");
						//mciSendString("close bgmclear", NULL, 0, 0);
					}
				}
			}

			//�����仯
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

/*��������APP_LoadMusicR
����:������������
��������
����ֵ����
*/
void  APP_LoadMusicR()
{
	//open ��һ������ ����Ҫ�ո� ��Ȼϵͳ�޷���ʶ
	mciSendString("open  ./Music/����.mp3  alias bgmclear", NULL, 0, 0);
	mciSendString("play bgmclear from 9", NULL, 0, 0);
}

/*��������APP_LoadMusic
����:������Ϸ����
��������
����ֵ����
*/
void  APP_LoadMusic()
{
	//��������
	mciSendString("open  ./Music/��Ϸ��.mp3  alias gamerun", NULL, 0, 0);
	mciSendString("play gamerun repeat", NULL, 0, 0);
}


#define MAXSTAR 28000	// ��������
struct STAR             //���ǽṹ��
{
	double	x;
	int		y;
	double	step;
	int		color;
};
STAR star[MAXSTAR];

/*��������Easter_Egg
����:��Ϸ�ʵ�
��������
����ֵ����
*/
void  Easter_Egg()
{

		initgraph(640, 480);			// ������ͼ����
		mciSendString("open  ./Music/�ʵ�.mp3  alias egg", NULL, 0, 0);
		mciSendString("play egg", NULL, 0, 0);

		
	
		
		// ��ʼ����������
		for (int i = 0; i < MAXSTAR; i++)
		{
			star[i].x = 0;
			star[i].y = rand() % 480;
			star[i].step = (rand() % 5000) / 1000.0 + 1;
			star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
			star[i].color = RGB(star[i].color, star[i].color, star[i].color);
			star[i].x = rand() % 640;
		}

		// �����ǿգ���������˳�
		while (!_kbhit())
		{
		
			//����˵��
			settextcolor(RGB(180, 200, 20));
			settextstyle(20, 0, "����");
			outtextxy(100, 260, "��ϲ��ͨ��");
			/*outtextxy(150, 180, "�Ұ���");
			outtextxy(150, 220, "���ﶼ���㣬�����ǳ��̲�����");
			outtextxy(150, 250, "�Ǻ��貣�ȫ�������Ұ��ֻ����һ��");*/
			settextcolor(RGB(18, 200, 20));
			settextstyle(30, 0, "����");
			//outtextxy(250, 340, "LOVER");
			for (int i = 0; i < MAXSTAR; i++)
			{
				// ����ԭ��������
				putpixel((int)star[i].x, star[i].y, 0);
					
				// ������λ��
				star[i].x += star[i].step;
				if (star[i].x > 640)
				{
					star[i].x = 0;
					star[i].y = rand() % 480;
					star[i].step = (rand() % 5000) / 1000.0 + 1;
					star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
					star[i].color = RGB(star[i].color, star[i].color, star[i].color);
				}
				// ��������
				putpixel((int)star[i].x, star[i].y, star[i].color);
			}
			Sleep(20);
		}

		closegraph();					// �رջ�ͼ����
}

/*��������Load_maxscore
����:������߷���
��������
����ֵ����
*/
void  Load_maxscore()
{
	// ��¼��߷ּ�¼
	FILE* f1 = fopen("./max_score.txt", "r"); //��ȡ
	if (f1 == NULL)
	{
		settextstyle(26, 0, _T("����"));
		settextcolor(RED);
		outtextxy(393, 285, "���ļ�ʧ�ܣ���");
	}
	else
	{
		fscanf(f1, "%d", &max_score);
		printf("%d", max_score);
		fclose(f1);
		if (score > max_score)
		{
			
			FILE* f2 = fopen("./max_score.txt", "w"); //д��
			if (f2 == NULL)
			{
				settextstyle(26, 0, _T("����"));
				settextcolor(RED);
				outtextxy(393, 285, "���ļ�ʧ�ܣ���");
			}
			else
			{
				
				fprintf(f2, "%d", score);	
				fclose(f2);
			}
		}
	}
}

/*��������Show_score
����:������߷���
��������
����ֵ����
*/
void  Show_score()
{
	// ��ʾ��ǰ����
	_itoa_s(score, str, 10);
	settextstyle(20, 0, _T("����"));
	settextcolor(RED);
	outtextxy(393, 285, str);


	// ��ʾ��߷���
	settextstyle(30	, 0, _T("����"));
	setcolor(RGB(153, 217, 234));
	outtextxy(390, 340, "��");
	settextstyle(20, 0, _T("����"));
	settextcolor(RED);
	_itoa_s(max_score, strmax, 10);
	outtextxy(390, 340, strmax);
}
