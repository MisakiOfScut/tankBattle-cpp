#include"MainWindow.h"
#include<Windows.h>
#include<mmsystem.h>
#include<iostream>
//#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
#pragma comment(lib,"Winmm.Lib")
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)//定义按键

MainWindow::MainWindow()
{
	Map mapObject;
}

MainWindow::~MainWindow()
{
}

Map & MainWindow::getMapObj()
{
	return mapObject;
}

void MainWindow::Game()
{
	Menu();
}

void MainWindow::clearLastGame()
{
	system("cls");	//清屏
	tankSet.clear();
	bulletSet.clear();
	Map newMap;
	mapObject = newMap;
	gameFail = false;
}

void MainWindow::Menu()
{
	DrawObject temp;

	showCursor();
	setWindow("BattleCity", 140, 48);
	PlaySound(TEXT("res\\start.wav"), NULL, SND_SYNC | SND_NODEFAULT);
	while (true)
	{
		char a0[60]= "*                   Press the Key below                   *";
		char a1[60]= "*                     1.Single Player                     *";
		char a2[60]= "*                     2.Double Player                     *";
		char a3[60]= "*                     Esc. Exit Game                      *";
		temp.paint(20, 20, a0, 7);
		temp.paint(20, 22, a1, 7);
		temp.paint(20, 24, a2, 7);
		temp.paint(20, 26, a3, 7);
		
		if (KEYDOWN('1'))
		{
			system("cls");
			PlaySound(TEXT("res\\keydown.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			onePlayer();
		}
		if (KEYDOWN('2'))
		{
			system("cls");
			PlaySound(TEXT("res\\keydown.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			douPlayers();
		}
		if (KEYDOWN(VK_ESCAPE))
		{
			exit(0);
		}
	}
}

void MainWindow::winMenu()
{
	clearLastGame();
	PlaySound(TEXT("res\\win.wav"), NULL, SND_SYNC | SND_NODEFAULT);
	DrawObject temp;
	while (true)
	{
		char a0[58] = "*                   !!!What a pity!!!                   *";
		char a1[58] = "*                      Player1 lost                     *";
		char a2[58] = "*                Enter. Back to start menu              *";
		char a3[58] = "*                     Esc. Exit Game                    *";
		temp.paint(20, 20, a0, 7);
		temp.paint(20, 22, a1, 7);
		temp.paint(20, 24, a2, 7);
		temp.paint(20, 26, a3, 7);
		if (KEYDOWN(VK_ESCAPE))
		{
			exit(0);
		}
		if (KEYDOWN(VK_RETURN))
		{
			PlaySound(TEXT("res\\keydown.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			Menu();
		}
	}
}

void MainWindow::lostMenu()
{
	clearLastGame();
	PlaySound(TEXT("res\\lost.wav"), NULL, SND_SYNC | SND_NODEFAULT);
	DrawObject temp;
	while (true)
	{
		char a0[58] = "*                   !!!What a pity!!!                   *";
		char a1[58] = "*                      Player1 lost                     *";
		char a2[58] = "*                Enter. Back to start menu              *";
		char a3[58] = "*                     Esc. Exit Game                    *";
		temp.paint(20, 20, a0, 7);
		temp.paint(20, 22, a1, 7);
		temp.paint(20, 24, a2, 7);
		temp.paint(20, 26, a3, 7);
		if (KEYDOWN(VK_ESCAPE))
		{
			exit(0);
		}
		if (KEYDOWN(VK_RETURN))
		{
			PlaySound(TEXT("res\\keydown.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			Menu();
		}
	}
}

void MainWindow::scoreBoard(int i)
{
	DrawObject t;
	if (i == 1)
	{
		char a[7] = "Score:";
		char A[2] = "";
		A[0] = tankSet[0].getScore() + '0';
		t.paint(56, 2, a, 7);
		t.paint(59, 2, A, 7);

		char b[14] = "Player Blood:";
		char B[2] = ""; 
		B[0] = tankSet[0].getValue() + '0';
		t.paint(56, 3, b, 7);
		t.paint(63, 3, B, 7);

		char c[20] = "Number of Enemies:";
		char C[2] = "";
		C[0] = enemyNum + '0';
		t.paint(56, 4, c, 7);
		t.paint(66, 4, C, 7);
	}
	else if (i == 2)
	{
		char b[15] = "Player1 Blood:";
		char B[2] = "";
		B[0] = tankSet[0].getValue() + '0';
		t.paint(56, 2, b, 7);
		t.paint(63, 2, B, 7);

		char c[15] = "Player2 Blood:";
		char C[2] = "";
		C[0] = tankSet[1].getValue() + '0';
		t.paint(56, 4, c, 7);
		t.paint(63, 4, C, 7);
	}
}

void MainWindow::tankIntroBoard()
{
	DrawObject t;
	char a[12] = "Tank Color:";
	//tank1
	t.paint(56, 13, a, 7);
	t.paint(61, 13, "█ (enemy)", 11);
	char b[14] = "Tank Blood: 1";
	t.paint(56, 14, b, 7);
	//tank2
	t.paint(56, 16, a, 7);
	t.paint(61, 16, "█ (enemy)", 6);
	char c[14] = "Tank Blood: 2";
	t.paint(56, 17, c, 7);
	//tank 3
	t.paint(56, 19, a, 7);
	t.paint(61, 19, "█ (enemy)", 15);
	char d[14] = "Tank Blood: 5";
	t.paint(56, 20, d, 7);
	//tank 4
	t.paint(56, 22, a, 7);
	t.paint(61, 22, "█ (ally)", 10);
	char e[14] = "Tank Blood: 3";
	t.paint(56, 23, e, 7);
	//tank 5
	t.paint(56, 25, a, 7);
	t.paint(61, 25, "█ (player1)", 1);
	char f[14] = "Tank Blood: 5";
	t.paint(56, 26, f, 7);
}

void MainWindow::showCursor()
{
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOutStd, &cci);
}

bool MainWindow::setWindow(const char* wdsName, short wid,short height)
{
	//设置当前控制台窗口标题
	SetConsoleTitleA(wdsName);
	HANDLE hStdIn, hStdOut;//
	//获取标准输出句柄
	hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD BufferSize = { pos.X + 1,pos.Y + 1 };
	if (!SetConsoleScreenBufferSize(hStdOut, BufferSize)) 
	{
		std::cout << "buffer err(" << BufferSize.X << BufferSize.Y << "," << GetLastError() << std::endl;
		return false;
	}
	SMALL_RECT srctWindow = { 0,0,wid-1,height-1};
	//这个函数设置控制台屏幕缓冲区窗口的大小和位置
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)) 
	{
		printf("size err%d\n", GetLastError());
		return false;
	}
	COORD Buffer = { wid +1,height+1  };
	//这个函数设置控制台屏幕缓冲区的大小
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)) 
	{
		std::cout << "buffer err(" << BufferSize.X << BufferSize.Y << "," << GetLastError() << std::endl;		
		return false;
	}
	return true;
}

//将一个坦克的值写入地图
Map MainWindow::pushOneMap(Map & temp, int i)
{
		for (size_t j = 0; j < 8; j++)
		{
			temp.setValue(tankSet[i].getTankPst(j).X, tankSet[i].getTankPst(j).Y, tankSet[i].getTanktype());
		}
	return temp;
}

//将所有坦克的值写入地图
Map MainWindow::pushMap(Map & temp)
{
	for (size_t i = 0; i < tankSet.size(); i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			temp.setValue(tankSet[i].getTankPst(j).X, tankSet[i].getTankPst(j).Y, tankSet[i].getTanktype());
		}
	}
	return temp;
}

void MainWindow::setProps()
{
	//18 12; 18 29 ;37 12;37 29 四点内随机生成加血道具
	int x = rand() % 19 + 18, y = rand() % 17 + 12;	
	mapObject.paint(x, y, "▲", 4);
	mapObject.setValue(x, y, 11);

}

void MainWindow::initialGame1()
{
	getMapObj().drawMap();
	tankIntroBoard();
	setProps();

	Tank mytank(4);
	Tank mytank2(5);
	Tank enemyTank1(6);
	Tank enemyTank2(7);
	tankSet.push_back(mytank);
	tankSet.push_back(mytank2);	
	tankSet.push_back(enemyTank1);
	tankSet.push_back(enemyTank2);
	enemyNum = 2;

	pushMap(mapObject);

	for (size_t i = 0; i < tankSet.size(); i++)
	{
		tankSet[i].setMap(&mapObject);
		tankSet[i].draw();
	}

}

void MainWindow::onePlayer()
{
	initialGame1();
	
	//GetTickCount函数返回从游戏启动经过的毫秒数
	DWORD playerBegin = GetTickCount(), playerEnd, bulletBegin = GetTickCount(), bulletEnd;

	while (true)
	{
		scoreBoard(1);

		if (enemyNum == 0 )
		{			
			winMenu();
		}
		else if (gameFail || !tankSet[0].getLive())
		{
			lostMenu();
		}
		playerEnd = GetTickCount();


		if (playerEnd - playerBegin > 60)//控制打印频率，也可以说是坦克移动速度
		{
			playerBegin = playerEnd;

			////////处理玩家坦克

			tankSet[0].DeleTank();

			for (size_t j = 0; j < 8; j++)
			{
				mapObject.setValue(tankSet[0].getTankPst(j).X, tankSet[0].getTankPst(j).Y, 0);
			}
			//mytank move
			Press(tankSet[0].getTanktype());

			tankSet[0].draw();
			
			pushOneMap(mapObject, 0);

			////////////////////////处理电脑坦克		
			int k = rand() % 3 + 1;	

			if(k<tankSet.size())
			if (tankSet[k].getLive())
			{			
				tankSet[k].DeleTank();
				for (size_t j = 0; j < 8; j++)
					mapObject.setValue(tankSet[k].getTankPst(j).X, tankSet[k].getTankPst(j).Y, 0);
				enemyMove(tankSet[k]);
				tankSet[k].draw();
				pushOneMap(mapObject, k);
		    }
						
		}

		bulletEnd = GetTickCount();
		if (bulletEnd - bulletBegin > 50)
		{
			bulletBegin = bulletEnd;
			//处理子弹，循环一次处理一颗
			for (size_t i = 0; i < bulletSet.size(); i++)
			{
				if (bulletSet[i].getLive())
				{
					bulletSet[i].moveBullet(tankSet);
					getMapObj() = *(bulletSet[i].getMap());					
				}
				else
				{
					bulletSet.erase(bulletSet.begin() + i);
				}
			}
		}
	}
}

void MainWindow::initialGame2()
{
	getMapObj().drawMap();
	tankIntroBoard();

	Tank mytank(4);
	Tank enemyTank3(8);
	tankSet.push_back(mytank);
	tankSet.push_back(enemyTank3);
	enemyNum = 1;

	pushMap(mapObject);

	for (size_t i = 0; i < tankSet.size(); i++)
	{
		tankSet[i].setMap(&mapObject);
		tankSet[i].draw();
	}
}

void MainWindow::douPlayers()
{
	initialGame2();

	//GetTickCount函数返回从游戏启动经过的毫秒数
	DWORD playerBegin = GetTickCount(), playerEnd, bulletBegin = GetTickCount(), bulletEnd;

	while (true)
	{
		scoreBoard(2);

		if ( !tankSet[0].getLive()||gameFail)
		{
			lostMenu();
		}
		else if (!tankSet[1].getLive())
		{
			winMenu();
		}
		playerEnd = GetTickCount();


		if (playerEnd - playerBegin > 60)
		{
			playerBegin = playerEnd;

			////////处理玩家1的坦克
			tankSet[0].DeleTank();
			
			for (size_t j = 0; j < 8; j++)
			{
				mapObject.setValue(tankSet[0].getTankPst(j).X, tankSet[0].getTankPst(j).Y, 0);				
			}

			Press(tankSet[0].getTanktype());//mytank move

			for (size_t i = 0; i < tankSet.size(); i++)
			{
				if (tankSet[i].getLive())
					tankSet[i].draw();
			}
			pushOneMap(mapObject, 0);

			/////处理玩家2的坦克
			tankSet[1].DeleTank();
			for (size_t j = 0; j < 8; j++)
			{				
				mapObject.setValue(tankSet[1].getTankPst(j).X, tankSet[1].getTankPst(j).Y, 0);
			}
			Press(tankSet[1].getTanktype());//enemy move
			for (size_t i = 0; i < tankSet.size(); i++)
			{
				if(tankSet[i].getLive())
				tankSet[i].draw();
			}
			pushOneMap(mapObject, 1);
			
		}

		bulletEnd = GetTickCount();
		if (bulletEnd - bulletBegin > 50)
		{
			bulletBegin = bulletEnd;
			//处理子弹，循环一次处理一颗
			for (size_t i = 0; i < bulletSet.size(); i++)
			{
				if (bulletSet[i].getLive())
				{
					bulletSet[i].moveBullet(tankSet);
					getMapObj() = *(bulletSet[i].getMap());					
				}
				else
				{
					bulletSet.erase(bulletSet.begin() + i);
				}
			}
		}
	}
}

bool MainWindow::enemyMove(Tank & tankObj)
{
	int randNum = getRand();
    Bullet bullet2;

	switch (randNum)
	{
	case 1:
		tankObj.MoveTank('w');
		break;
	case 2:
		tankObj.MoveTank('a');
		break;
	case 3:
		tankObj.MoveTank('s');
		break;
	case 4:
		tankObj.MoveTank('d');
		break;
	case 5:
		static int cT = GetTickCount(), ct1;
		ct1 = GetTickCount();
		if (ct1 - cT < 200)
			return false;
		cT = ct1;

		bullet2 = bullet2.createBullet(tankObj, tankSet);
		if (bullet2.getLive())
			bulletSet.push_back(bullet2);
		break;
	default:
		break;
	}
	return true;
}

bool MainWindow::Press(int id)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		clearLastGame();
		Menu();
	}
	if (id==4)
	{
		if (KEYDOWN('w') || KEYDOWN('W'))
		{
			tankSet[0].MoveTank('w');
		}

		if (KEYDOWN('S') || KEYDOWN('s'))
		{
			tankSet[0].MoveTank('s');
		}

		if (KEYDOWN('A') || KEYDOWN('a'))
		{
			tankSet[0].MoveTank('a');
		}

		if (KEYDOWN('D') || KEYDOWN('d'))
		{
			tankSet[0].MoveTank('d');
		}
		if (KEYDOWN(VK_SPACE))
		{
			PlaySound(TEXT("res\\fire.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			static int cT = GetTickCount(), ct1;
			ct1= GetTickCount();
			if (ct1 - cT < 200)
			{
				return false;
			}
			cT = ct1;

			Bullet bullet1;
			bullet1 = bullet1.createBullet(tankSet[0], tankSet);
			if (bullet1.getLive())		
				bulletSet.push_back(bullet1);						

		}
		return true;
	}
	if (id==8)
	{
		if (KEYDOWN(VK_UP))
		{
			tankSet[1].MoveTank('w');
		}

		if (KEYDOWN(VK_DOWN))
		{
			tankSet[1].MoveTank('s');
		}

		if (KEYDOWN(VK_LEFT))
		{
			tankSet[1].MoveTank('a');
		}

		if (KEYDOWN(VK_RIGHT))
		{
			tankSet[1].MoveTank('d');
		}
		if (KEYDOWN(VK_RCONTROL))
		{
			PlaySound(TEXT("res\\fire.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			static int cT = GetTickCount(), ct1;
			ct1 = GetTickCount();
			if (ct1 - cT < 200)
			{
				return false;
			}
			cT = ct1;

			Bullet bullet1;
			bullet1 = bullet1.createBullet(tankSet[1], tankSet);
			if (bullet1.getLive())
				bulletSet.push_back(bullet1);

		}
		return true;
	}

	return true;
}

int MainWindow::getRand()
{
	srand(time(NULL));
	return rand() % 5 + 1;
}