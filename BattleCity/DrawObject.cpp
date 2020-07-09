#include"DrawObject.h"
#include<Windows.h>
#include<iostream>

DrawObject::DrawObject()
{
}
DrawObject::~DrawObject()
{
}

bool DrawObject::paintPst(int nX, int nY, int nType)
{
	//所有文字图案长度为两个字符
	switch (nType)
	{
	case 0: paint(nX, nY, "  ", 0);
		break;

	case 1:paint(nX, nY, "█", 7);
		break;

	case 2:paint(nX, nY, "▓", 4);
		break;

	case 3:paint(nX, nY, "★", 9);
		break;
	default:
		break;
	}
	return true;
}
/*所以文字图案占两个字符位，实际显示的地图宽度是地图数组的两倍
所以下面的coord坐标中的x坐标要是数组列坐标的两倍*/
void DrawObject::paint(int nX, int nY, const char* psz, WORD wArr)
{
	//获取句柄
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	//这里的X，Y坐标是控制台里的坐标值
	pos.X = nX * 2;
	pos.Y = nY;
	//设置光标位置（输出位置）
	SetConsoleCursorPosition(hOutStd, pos);
	//设置字体颜色
	SetConsoleTextAttribute(hOutStd, wArr);
	std::cout << psz;
}
//擦除的原理就是在原位置打印空字符覆盖原理的字符
void DrawObject::erase(int nX, int nY, const char* psz, WORD wArr)
{
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = nX * 2;
	pos.Y = nY;
	SetConsoleCursorPosition(hOutStd, pos);
	SetConsoleTextAttribute(hOutStd, wArr);
	std::cout <<"  ";
}