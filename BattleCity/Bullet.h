#pragma once
#include"BaseOBject.h"
#include"DrawObject.h"
#include"Tank.h"
#include<vector>

class Bullet:virtual public  BaseOBject
{
public:
	Bullet();
	~Bullet();

	//打印子弹
	void draw();
	//删除子弹的图像
	void deleBullet();

	//用坦克类对象来创建子弹
	Bullet createBullet(Tank&, std::vector<Tank>& );
	//改变子弹坐标移动子弹
	bool moveBullet(std::vector<Tank>&);
	//检测子弹是否发生碰撞
	bool bulletCollision(Bullet& , std::vector<Tank>& );
	//重载=号方便创建子弹
	bool operator=(Tank&);
	//重载==方便检测子弹与坦克的碰撞
	bool operator==(Tank&);//use to detect collision
	//返回地图指针
	Map *getMap();
	bool getLive();
	int getBulletPosX();
	int getBulletPosY();
	int getBulletDir();
	int getBulletType();

	
private:
	bool ifAlive;//子弹是否存活，存活时为真
	int posX, posY;
	int dir;
	int ntype;//子弹种类，与坦克种类相同
	int bulletColor;//子弹颜色
	Map* pToMap;//地图指针
	Tank* pToTank;
};
