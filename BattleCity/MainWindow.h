#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"BaseOBject.h"
#include"Map.h"
#include"DrawObject.h"
#include"Tank.h"
#include"Bullet.h"
#include<Windows.h>
#include<vector>
using namespace std;

class MainWindow
{
public:
	MainWindow();
	~MainWindow();
	//设置窗口大小
	bool setWindow(const char*, short width, short height);
	//隐藏输入光标
	void showCursor();
	//获取地图对象地址
	Map& getMapObj();
	//将所有坦克的值写入地图中
	Map pushMap(Map &);
	//将一个坦克的值写入地图
	Map pushOneMap(Map &,int);

	//打印初始菜单
	void Menu();
	//输赢界面
	void winMenu();
	void lostMenu();
	//打印计分板
	void scoreBoard(int);
	//打印坦克介绍板
	void tankIntroBoard();
	//初始化单人游戏
	void initialGame1();
	//初始化双人对战游戏
	void initialGame2();
	//清除上场游戏的数据
	void clearLastGame();
	// 生成道具
	void setProps();
	void Game();
	//单人游戏进程
	void onePlayer();
	//双人对战游戏进程
	void douPlayers();
	//一个简单的电脑AI
	bool enemyMove(Tank&);
	//从键盘上获得输入并相应处理
	bool Press(int);
	//获取随机数
	int getRand();

private:
	Map mapObject;//地图对象
	vector <Tank> tankSet;//坦克容器
	vector<Bullet> bulletSet;//子弹容器
};


#endif