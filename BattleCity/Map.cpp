#include"Map.h"

Map::Map()
{
}

Map::~Map()
{
}

bool Map::setValue(int nX, int nY, int Value)
{
	//防止越界访问数组
	if (nX >= 70 || nX <= 0 || nY <= 0 || nY >= 48)
	{
		return false;
	}
	else
	{
		//map数组是纵坐标在前横坐标在后，即map[y][x]
		ArrMap[nY][nX] = Value;
		return true;
	}
}

int Map::getValue(int nX, int nY)
{
	//map数组是纵坐标在前横坐标在后，即map[y][x]，所以返回（x,y）位置的值应该访问数组中[y][x]位置
	return ArrMap[nY][nX];
}

void Map::drawMap()
{
	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			//map数组是纵坐标在前横坐标在后，即map[y][x]
			//而coord坐标x是横坐标y是纵坐标，再算上字符长度2，所以x=2*j，y=i
			paintPst(j, i, ArrMap[i][j]);
		}
	}
}