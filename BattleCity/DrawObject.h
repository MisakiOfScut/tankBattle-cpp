#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include<Windows.h>
#include<iostream>

class DrawObject
{
public:
	DrawObject();
	~DrawObject();
	//根据输入在特定位置打印特定图案
	bool paintPst(int nX, int nY, int nType);
	//根据输入在特定位置打印输入文字
	void paint(int nX, int nY, const char* psz, WORD wArr);
	//根据输入在擦除特定位置的图案
	void erase(int nX, int nY, const char* psz, WORD wArr);

};
#endif