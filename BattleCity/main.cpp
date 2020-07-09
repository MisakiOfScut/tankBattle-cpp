#include "MainWindow.h"
#include<Windows.h>

int main()
{
	MainWindow a;
	a.Game();

	getchar();
}

/* 
简单说明：map、drawobject都是工具类，map类定义地图、drawobject提供打印函数
地图给tank和bullet提供载体，它们所有的移动通过改变地图数组中的数字实现
所有对象公共用一张地图，打印函数根据地图中的数字来打印图像
但地图是一开始就打好的，游戏中只刷新对象的图像或地图被改变的地方

实现的功能：坦克移动、碰撞检测、发射子弹、吃道具（子弹或车身碰撞道具）、
子弹破坏建筑、计分计血

处理流程：
*/

