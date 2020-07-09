#include"Bullet.h"
#include<Windows.h>
#include<mmsystem.h>
using namespace std;
#pragma comment(lib,"Winmm.Lib")
Bullet::Bullet()
{}
Bullet::~Bullet()
{}

void Bullet::draw()
{
	DrawObject t;
	t.paint(posX, posY, "●", bulletColor);
}

void Bullet::deleBullet()
{
	DrawObject t;
	t.paint(posX, posY, "  ", 0);
}

Bullet Bullet::createBullet(Tank &tankObj,std::vector<Tank>& tankSet)
{
	*this = tankObj;
	//judge if bullet will crash when it's created
	if (bulletCollision(*this,tankSet))
	{
		ifAlive = false;
	}
	return *this;
}

bool Bullet::bulletCollision(Bullet& bulletObj, std::vector<Tank>& tankSet)
{
	DrawObject t;
	int temp = 0;
	int nType = pToMap->getValue(posX, posY);

	switch (nType)
	{
	case 0:
		pToMap->setValue(posX, posY, bulletObj.ntype);
		draw();
		break;

	case 1:
		bulletObj.ifAlive = false;
		return true;
	case 2:
		bulletObj.ifAlive = false;
		t.erase(posX, posY, "  ", 0);
		PlaySound(TEXT("res\\explode.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
		pToMap->setValue(posX, posY, 0);
		return true;
	case 3:
		bulletObj.ifAlive = false;
		if (bulletObj.ntype != 5)
		{
			t.erase(posX, posY, "  ", 0);
			pToMap->setValue(posX, posY, 0);
			gameFail = true;
		}
		return true;
	case 4: case 5:
		bulletObj.ifAlive = false;

		if (!(bulletObj.ntype==4 || bulletObj.ntype == 5))
		{
			for (size_t i = 0; i < tankSet.size(); i++)
			{
				if (bulletObj == tankSet[i])
				{
					if (tankSet[i].getValue() - 1 > 0)
					{
						PlaySound(TEXT("res\\攻击结束.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
						tankSet[i].setValue(tankSet[i].getValue() - 1);
					}
					else
					{
						PlaySound(TEXT("res\\kill.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
						tankSet[i].setValue(0);
						tankSet[i].DeleTank();
						for (size_t j = 0; j < 8; j++)
						{
							pToMap->setValue(tankSet[i].getTankPst(j).X, tankSet[i].getTankPst(j).Y, 0);
						}
						//tankSet.erase(tankSet.begin() + i);

					}
				}
			}

		}
		return true;

	case 6: case 7: case 8:
		bulletObj.ifAlive = false;
		if (bulletObj.ntype==4||bulletObj.ntype==5)
		{
			for (size_t i = 0; i < tankSet.size(); i++)
			{
				if (bulletObj==tankSet[i])
				{
					if (tankSet[i].getValue()-1>0)
					{
						PlaySound(TEXT("res\\攻击结束.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
						tankSet[i].setValue(tankSet[i].getValue() - 1);
					}
					else
					{
						PlaySound(TEXT("res\\kill.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
						--enemyNum;
						tankSet[0].setScore(tankSet[0].getScore() + tankSet[i].getTanktype());
						tankSet[i].setValue(0);
						tankSet[i].DeleTank();
						for (size_t j = 0; j < 8; j++)
						{
							pToMap->setValue(tankSet[i].getTankPst(j).X, tankSet[i].getTankPst(j).Y, 0);
						}

 						//tankSet.erase(tankSet.begin() + i);						
					}
				
				}
			}
		}
		return true;

	case 11://道具		
		bulletObj.ifAlive = false;
		PlaySound(TEXT("res\\addhp.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
		pToTank->setValue(pToTank->getValue() + 1);
		t.erase(posX, posY, "  ", 0);
		pToMap->setValue(posX, posY, 0);
		
		return true;

	default:
		break;
	}

	return false;
}

bool Bullet::moveBullet(std::vector<Tank>& tankSet)
{
	deleBullet();

	switch (dir)
	{
	case UP:
		pToMap->setValue( posX,posY, 0);
		posY--;
		bulletCollision(*this, tankSet);
		break;
	case DOWN:
		pToMap->setValue( posX,posY, 0);
		posY++;
		bulletCollision(*this, tankSet);
		break;
	case LEFT:
		pToMap->setValue( posX,posY, 0);
		posX--;
		bulletCollision(*this, tankSet);
		break;
	case RIGHT:
		pToMap->setValue( posX,posY, 0);
		posX++;
		bulletCollision(*this, tankSet);
		break;
	default:
		break;
	}

	return true;
}

bool Bullet::operator=(Tank &tankObj)
{
	ntype = tankObj.getTanktype();
	bulletColor = tankObj.getTankColor();
	dir = tankObj.getTankDir();
	pToMap = tankObj.getMapObj();
	ifAlive = true;
	pToTank = &tankObj;

	switch (dir)
	{
	case UP:
		posY= tankObj.getTankPosY() - 2 ;
		posX = tankObj.getTankPosX();
		break;
	case DOWN:
		posY = tankObj.getTankPosY() + 2;
		posX = tankObj.getTankPosX();
		break;
	case RIGHT:
		posX = tankObj.getTankPosX() + 2;
		posY = tankObj.getTankPosY();
		break;
	case LEFT:
		posX = tankObj.getTankPosX() - 2;
		posY = tankObj.getTankPosY();
	default:
		break;
	}

	return true;
}

bool Bullet::operator==(Tank &tankObj)
{
	if (tankObj.getLive())
	{
		for (size_t i = 0; i < 8; i++)
		{
			if (posX == tankObj.getTankPst(i).X && posY == tankObj.getTankPst(i).Y)
			{
				return true;
			}
		}
	}
	return false;
}

Map * Bullet::getMap()
{
	return pToMap;
}

bool Bullet::getLive()
{
	return ifAlive;
}

int Bullet::getBulletPosX()
{
	return posX;
}

int Bullet::getBulletPosY()
{
	return posY;
}

int Bullet::getBulletType()
{
	return ntype;
}

int Bullet::getBulletDir()
{
	return dir;
}
