#include "framework.h"
#include "obstacleManager.h"
#include "obstacle.h"
obstacleManager::obstacleManager()
{
	totalWall = CreateRectRgn(0, 0, 0, 0);
	wallRGN = CreateRectRgn(0, 0, 0, 0);
	totalLand = CreateRectRgn(0, 0, 0, 0);
	landRGN = CreateRectRgn(0, 0, 0, 0);
	totalFloor = CreateRectRgn(0, 0, 0, 0);
	floorRGN = CreateRectRgn(0, 0, 0, 0);
}

obstacleManager::~obstacleManager()
{
}

HRESULT obstacleManager::init()
{
    return S_OK;
}

void obstacleManager::release()
{
}

void obstacleManager::update()
{
	vi_obstacle = v_obstacle.begin();
	for (vi_obstacle; vi_obstacle != v_obstacle.end(); ++vi_obstacle)
	{
		(*vi_obstacle)->update();
	}
}

void obstacleManager::render()
{
	vi_obstacle = v_obstacle.begin();
	for (vi_obstacle; vi_obstacle != v_obstacle.end(); ++vi_obstacle)
	{
		(*vi_obstacle)->render();
	}
}

void obstacleManager::createObstacle(OBSTACLE_TYPE _type, vector2 _pt)
{
    C_obstacle* obstacle;
    obstacle = new C_obstacle(_pt, _type);
    v_obstacle.push_back(obstacle);
	if (obstacle->getisLand())
	{
		landRGN = CreateRectRgn(obstacle->getRc().left, obstacle->getRc().top, obstacle->getRc().right, obstacle->getRc().bottom);
		//OffsetRgn(landRGN, 0, 10);
		CombineRgn(totalLand, totalLand, landRGN, RGN_XOR);
	}
	if (obstacle->getUnMovable())
	{
		wallRGN = CreateRectRgn(obstacle->getRc().left, obstacle->getRc().top, obstacle->getRc().right, obstacle->getRc().bottom);
		CombineRgn(totalWall, totalWall, wallRGN, RGN_XOR);
	}
	if (obstacle->getisDoor())
	{
		v_door.push_back(obstacle);
	}
	if (obstacle->getType() == OBSTACLE_TYPE::L_FLOOR || obstacle->getType() == OBSTACLE_TYPE::R_FLOOR)
	{
		floorRGN = CreateRectRgn(obstacle->getRc().left, obstacle->getRc().top, obstacle->getRc().right, obstacle->getRc().bottom);
		CombineRgn(totalFloor, totalFloor, floorRGN, RGN_XOR);
	}
}

viObstacle obstacleManager::getviObstacle(int number)
{
	vi_obstacle = v_obstacle.begin() + number;
	return vi_obstacle;
}

viObstacle obstacleManager::getviLand(int number)
{
	vi_land = v_land.begin() + number;
	return vi_land;
}

viObstacle obstacleManager::getviWall(int number)
{
	vi_wall = v_wall.begin() + number;
	return vi_wall;
}

viObstacle obstacleManager::getviDoor(int number)
{
	vi_door = v_door.begin() + number;
	return vi_door;
}

void obstacleManager::eraserAllObstacle()
{
	totalWall = CreateRectRgn(0, 0, 0, 0);
	totalLand = CreateRectRgn(0, 0, 0, 0);
	totalFloor = CreateRectRgn(0, 0, 0, 0);
	v_obstacle.erase(v_obstacle.begin(), v_obstacle.end());
	v_door.clear();

	//for (int i = 0; i < v_obstacle.size(); i++)
	//{
	//	v_obstacle.erase(v_obstacle.begin() + i);
	//}
	//for (int i = 0; i < v_land.size(); i++ )
	//{
	//	v_land.erase(v_land.begin() + i);
	//}
	//for (int i = 0; i < v_wall.size(); i++ )
	//{
	//	v_wall.erase(v_wall.begin() + i);
	//}
	//for (int i = 0; i < v_door.size(); i++ )
	//{
	//	v_door.erase(v_door.begin() + i);
	//}
	
}


