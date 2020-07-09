#ifndef BASEOBJECT_H
#define BASEOBJECT_H

//定义两个全局变量
extern int enemyNum;
extern bool gameFail;

class BaseOBject
{
public:
	BaseOBject();
	virtual ~BaseOBject();
	virtual void draw()=0;
};

#endif

