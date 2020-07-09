#ifndef TANK_H
#define TANK_H
#include"BaseOBject.h"
#include"DrawObject.h"
#include"Map.h"
enum DIRE { UP, DOWN, RIGHT, LEFT };//枚举方向

class Tank : virtual public BaseOBject
{
public:
	Tank(int);
	~Tank();
	//打印坦克
	void draw();
	//删除坦克图像
	void DeleTank();
	//根据键盘输入改变坦克方向
	bool MoveTank(char);
	//检测坦克是否碰撞
	bool CollisionDetect(char);
	//改变坦克坐标实现移动
	void posChange(DIRE);//zuo biao zhuan huan, get pos data for draw func
	//设置指针
	void setMap(Map * mapObject);
	//获取坦克某一部分的coord坐标
	COORD getTankPst(int);

	int getValue();
	//重设坦克血量用于扣血
	void setValue(int);
	void setScore(int);
	int getTanktype();
	int getTankColor();
	int getTankPosX();
	int getTankPosY();
	int getTankDir();
	int getScore();
	bool getLive();
	Map* getMapObj();

private:
	void setLive(bool);//设置坦克存活状态
	bool ifAlive;//判断坦克是否存活
	//存储坦克8个部分的coord坐标，█组成车身，┃组成炮管
	COORD TankPos[8];
	int posX, posY;//坦克中心坐标
	int Direction;
	int value;//血量
	int tankType;//坦克类型，用于分别坦克阵营、等级
	int tankColor;
	int tankScore;
	Map* pToMap;//地图指针
};

#endif
