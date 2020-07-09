#include"Tank.h"

Tank::Tank(int Ttype)
{
	ifAlive = true;
	tankScore = 0;
	if (Ttype==4)//mytank
	{		
		tankType = 4;
		tankColor = 1;
		posX = 22;
		posY = 44;
		Direction = UP;
		value = 5;
		posChange(UP);
	}
	else if (Ttype==5)
	{
		tankType = 5;
		tankColor = 10;
		posX = 53;
		posY = 42;
		Direction = UP;
		value = 3;
		posChange(UP);
	}
	else if (Ttype == 6)
	{
		tankType = 6;
		tankColor = 11;
		posX = 2;
		posY = 2;
		Direction = DOWN;
		value = 1;
		posChange(DOWN);
	}
	else if (Ttype==7)
	{
		tankType = 7;
		tankColor =6;
		posX = 53;
		posY = 2;
		Direction = DOWN;
		value = 2;
		posChange(DOWN);
	}
	else if (Ttype == 8)
	{
		tankType = 8;
		tankColor = 15;
		posX = 32;
		posY = 2;
		Direction = DOWN;
		value = 5;
		posChange(DOWN);
	}
	//
}

void Tank::draw()
{
	DrawObject temp;
	if (Direction==UP||Direction==DOWN)
	{
		temp.paint(TankPos[0].X, TankPos[0].Y, "┃", tankColor);
	}
	else
	{
		temp.paint(TankPos[0].X, TankPos[0].Y, "━", tankColor);
	}
	for (size_t i = 1; i < 8; i++)
	{
		temp.paint(TankPos[i].X, TankPos[i].Y, "█", tankColor);
	}
}

void Tank::DeleTank()
{
	DrawObject temp;
	for (size_t i = 0; i < 8; i++)
	{
		temp.erase(TankPos[i].X, TankPos[i].Y, "  ", tankType);
	}

}

bool Tank::MoveTank(char dir)
{
	DeleTank();

	switch (dir)
	{
	case 'w':
		//如果坦克不朝按键方向改变其方向为按键方向，否则移动一单位
		if (Direction!=UP)
		{
			//if (!CollisionDetect('w'))
				//return false;

			Direction = UP;
			posChange(UP);
		}
		else
		{
			if (!CollisionDetect('w'))
				return false;

			posY -= 1;
			for (size_t i = 0; i < 8; i++)
			{
				TankPos[i].Y -= 1;
			}
		}
		break;

	case'a':
		if (Direction!=LEFT)
		{
			//if (!CollisionDetect('a'))
				//return false;
			Direction = LEFT;
			posChange(LEFT);
		}
		else
		{
			if (!CollisionDetect('a'))
				return false;
			posX -= 1;
			for (size_t i = 0; i < 8; i++)
			{
				TankPos[i].X -= 1;
			}
		}
		break;

	case 'd':
		if (Direction != RIGHT)
		{
			//if (!CollisionDetect('d'))
				//return false;
			Direction = RIGHT;
			posChange(RIGHT);
		}
		else
		{
			if (!CollisionDetect('d'))
				return false;
			posX += 1;
			for (size_t i = 0; i < 8; i++)
			{
				TankPos[i].X += 1;
			}
		}
		break;

	case's':
		if (Direction != DOWN)
		{
			//if (!CollisionDetect('s'))
				//return false;
			Direction = DOWN;
			posChange(DOWN);
		}
		else
		{
			if (!CollisionDetect('s'))
				return false;
			posY += 1;
			for (size_t i = 0; i < 8; i++)
			{
				TankPos[i].Y += 1;
			}
		}
		break;

	default:
		break;
	}

	draw();
	return true;
}

void Tank::posChange(DIRE dir)
{
	switch (dir)
	{
	case UP:
		/*2 0 5
		  3 1 6
		  4   7*/
		TankPos[0].X = posX;//xiang dui wei zhi
		TankPos[0].Y = posY - 1;//zuo shang wei yuan dian
		TankPos[1].X = posX;
		TankPos[1].Y = posY;
		TankPos[2].X = posX - 1;
		TankPos[2].Y = posY - 1;
		TankPos[3].X = posX - 1;
		TankPos[3].Y = posY;
		TankPos[4].X = posX - 1;
		TankPos[4].Y = posY + 1;
		TankPos[5].X = posX + 1;
		TankPos[5].Y = posY - 1;
		TankPos[6].X = posX + 1;
		TankPos[6].Y = posY;
		TankPos[7].X = posX + 1;
		TankPos[7].Y = posY + 1;
		break;
	case DOWN:
		/*7   4
		  6 1 3
		  5 0 2*/
		TankPos[0].X = posX;
		TankPos[0].Y = posY + 1;
		TankPos[1].X = posX;
		TankPos[1].Y = posY;
		TankPos[2].X = posX + 1;
		TankPos[2].Y = posY + 1;
		TankPos[3].X = posX + 1;
		TankPos[3].Y = posY;
		TankPos[4].X = posX + 1;
		TankPos[4].Y = posY - 1;
		TankPos[5].X = posX - 1;
		TankPos[5].Y = posY + 1;
		TankPos[6].X = posX - 1;
		TankPos[6].Y = posY;
		TankPos[7].X = posX - 1;
		TankPos[7].Y = posY - 1;
		break;
	case RIGHT:
		/*4 3 2
		    1 0
		  7 6 5*/
		TankPos[0].X = posX+1;
		TankPos[0].Y = posY;
		TankPos[1].X = posX;
		TankPos[1].Y = posY;
		TankPos[2].X = posX + 1;
		TankPos[2].Y = posY - 1;
		TankPos[3].X = posX ;
		TankPos[3].Y = posY-1;
		TankPos[4].X = posX - 1;
		TankPos[4].Y = posY - 1;
		TankPos[5].X = posX + 1;
		TankPos[5].Y = posY + 1;
		TankPos[6].X = posX;
		TankPos[6].Y = posY+1;
		TankPos[7].X = posX - 1;
		TankPos[7].Y = posY + 1;
		break;
	case LEFT:
		/*5 6 7
		  0 1
		  2 3 4*/
		TankPos[0].X = posX-1;
		TankPos[0].Y = posY ;
		TankPos[1].X = posX;
		TankPos[1].Y = posY;
		TankPos[2].X = posX - 1;
		TankPos[2].Y = posY + 1;
		TankPos[3].X = posX ;
		TankPos[3].Y = posY+1;
		TankPos[4].X = posX + 1;
		TankPos[4].Y = posY + 1;
		TankPos[5].X = posX - 1;
		TankPos[5].Y = posY - 1;
		TankPos[6].X = posX;
		TankPos[6].Y = posY-1;
		TankPos[7].X = posX + 1;
		TankPos[7].Y = posY - 1;
		break;
	default:
		break;
	}
}

bool Tank::CollisionDetect(char dir)
{
	DrawObject t;

	switch (dir)
	{
	case'w':
		if (pToMap->getValue(TankPos[2].X, TankPos[2].Y - 1) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if(pToMap->getValue(TankPos[5].X, TankPos[5].Y - 1) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[0].X, TankPos[0].Y - 1) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}				
		else if (pToMap->getValue(TankPos[2].X, TankPos[2].Y - 1) != 0 ||
				pToMap->getValue(TankPos[5].X, TankPos[5].Y - 1) != 0 ||
				pToMap->getValue(TankPos[0].X, TankPos[0].Y - 1) != 0)
		{
			return false;
		}
		break;

	case 'a':
		if (pToMap->getValue(TankPos[2].X - 1, TankPos[2].Y) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[5].X - 1, TankPos[5].Y) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[0].X - 1, TankPos[0].Y) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[2].X-1, TankPos[2].Y ) != 0||
			pToMap->getValue(TankPos[5].X - 1, TankPos[5].Y) != 0||
			pToMap->getValue(TankPos[0].X-1, TankPos[0].Y ) != 0)
		{ 
			return false;
		}
		break;

	case 's':
		if (pToMap->getValue(TankPos[2].X, TankPos[2].Y + 1) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[5].X , TankPos[5].Y+1) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[0].X, TankPos[0].Y + 1) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[2].X, TankPos[2].Y + 1) != 0 ||
			pToMap->getValue(TankPos[5].X, TankPos[5].Y + 1) != 0 ||
			pToMap->getValue(TankPos[0].X, TankPos[0].Y + 1) != 0)
		{
			return false;
		}
		break;

	case 'd':
		if (pToMap->getValue(TankPos[2].X + 1, TankPos[2].Y) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[5].X + 1, TankPos[5].Y) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[0].X + 1, TankPos[0].Y) == 11)
		{
			PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			this->setValue(value + 1);
		}
		else if (pToMap->getValue(TankPos[2].X + 1, TankPos[2].Y) != 0 ||
			pToMap->getValue(TankPos[5].X + 1, TankPos[5].Y) != 0 ||
			pToMap->getValue(TankPos[0].X + 1, TankPos[0].Y) != 0)
		{
			return false;
		}
		break;
	default:
		break;
	}
	return true;
}

void Tank::setMap(Map * mapObject)
{
	pToMap = mapObject;
}

COORD Tank::getTankPst(int i)
{
	return TankPos[i];
}

int Tank::getValue()
{
	return value;
}

void Tank::setValue(int n)
{
	if (n==0)
	{
		setLive(false);
	}
	value = n;
}

void Tank::setLive(bool live)
{
	ifAlive = live;
}

void Tank::setScore(int n)
{
	tankScore = n;
}

bool Tank::getLive()
{
	return ifAlive;
}

int Tank::getTanktype()
{
	return tankType;
}

int Tank::getTankPosX()
{
	return posX;
}

int Tank::getTankPosY()
{
	return posY;
}

int Tank::getTankDir()
{
	return Direction;
}

int Tank::getTankColor()
{
	return tankColor;
}

int Tank::getScore()
{
	return tankScore;
}

Map* Tank::getMapObj()
{
	return pToMap;
}

Tank::~Tank()
{}