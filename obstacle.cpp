#include "framework.h"
#include "obstacle.h"

C_obstacle::C_obstacle()
{
}

C_obstacle::C_obstacle(vector2 _pt, OBSTACLE_TYPE _type)
{
	C_object::init();
	type = _type;
	//tileSize = IMAGE->findImage("tile")->getFrameWidth() / 2;
	pt = { _pt.x + IMAGE->findImage("tile")->getFrameWidth() / 2 , _pt.y + IMAGE->findImage("tile")->getFrameHeight() / 2 };
	collider = new C_collider(pt, { IMAGE->findImage("tile")->getFrameWidth() ,IMAGE->findImage("tile")->getFrameHeight() });
	//obstacleNumber = _number;
	isStart = false;
	isDoor = false;
	setValue(false, false, false);
	setObstacleValue();
	rc = RectMakeCenter(collider->getPos(), collider->getSize().x, collider->getSize().y);
}

C_obstacle::~C_obstacle()
{
}

HRESULT C_obstacle::init()
{
	return S_OK;
}

void C_obstacle::release()
{
}

void C_obstacle::update()
{
	C_object::update();
	//setObstacleValue();
}

void C_obstacle::render()
{
	if (isDoor)
	{
		if (ENEMY->getvEnemy().size() <= 0)
		{
			collider->setSize({ 90,180 });
			IMAGE->findImage(doorType + "Door")->aniRenderCenter(getCVOSDC(), pt.x, pt.y - 37, ANIMATION->findAnimation(doorType + "DoorAni"));
		}
		else { IMAGE->findImage(doorType + "Door")->frameRenderCenter(getCVOSDC(), { pt.x, pt.y - 37 },5,0); }
	}
	else if(isStart){}
	else{IMAGE->frameRenderCenter("tile", getCVOSDC(), pt, frame.x, frame.y);}
	
}

void C_obstacle::setObstacleValue()
{
	switch (type)
	{
	case OBSTACLE_TYPE::LT_LAND:
		frame = { 0,0 };
		setValue(true, false, true);
		break;
	case OBSTACLE_TYPE::LTC_LAND:
		frame = { 1,0 };
		setValue(true, false, true);
		break;
	case OBSTACLE_TYPE::RTC_LAND:
		frame = { 2,0 };
		setValue(true, false, true);
		break;
	case OBSTACLE_TYPE::RT_LAND:
		frame = { 3,0 };
		setValue(true, false, true);
		break;
	case OBSTACLE_TYPE::L_FLOOR:
		frame = { 4,0 };
		setValue(true, false, true);
		break;
	case OBSTACLE_TYPE::R_FLOOR:
		frame = { 5,0 };
		setValue(true, false, true);
		break;
	case OBSTACLE_TYPE::L_LAND:
		frame = { 0,1 };
		setValue(true, false, false);
		break;
	case OBSTACLE_TYPE::LC_LAND:
		frame = { 1,1 };
		setValue(false, false, false);
		break;
	case OBSTACLE_TYPE::RC_LAND:
		frame = { 2,1 };
		setValue(false, false, false);
		break;
	case OBSTACLE_TYPE::R_LAND:
		frame = { 3,1 };
		setValue(true, false, false);
		break;
	case OBSTACLE_TYPE::RCA_LAND:
		frame = { 4,1 };
		setValue(false, false, true);
		break;
	case OBSTACLE_TYPE::RA_LAND:
		frame = { 5,1 };
		setValue(false, false, true);
		break;
	case OBSTACLE_TYPE::TL_LAND:
		frame = { 0,2 };
		setValue(true, false, false);
		break;
	case OBSTACLE_TYPE::BL_LAND:
		frame = { 1,2 };
		setValue(true, false,false);
		break;
	case OBSTACLE_TYPE::BR_LAND:
		frame = { 2,2 };
		setValue(true, false,false);
		break;
	case OBSTACLE_TYPE::TR_LAND:
		frame = { 3,2 };
		setValue(true, false,false);
		break;
	/*case OBSTACLE_TYPE::NONE:
		frame = { 4,2 };
		setValue(false, false);
		break;*/
	case OBSTACLE_TYPE::LBC_LAND:
		frame = { 0,3 };
		setValue(true, false,false );
		break;
	case OBSTACLE_TYPE::LB_LAND:
		frame = { 1,3 };
		setValue(true, false,false);
		break;
	case OBSTACLE_TYPE::RB_LAND:
		frame = { 2,3 };
		setValue(true, false,false);
		break;
	case OBSTACLE_TYPE::RBC_LAND:
		frame = { 3,3 };
		setValue(true, false,false);
		break;
	case OBSTACLE_TYPE::LA_LAND:
		frame = { 4,3 };
		setValue(false, false,true);
		break;
	case OBSTACLE_TYPE::LCA_LAND:
		frame = { 5,3 };
		setValue(false, false,true);
		break;
	case OBSTACLE_TYPE::ITEMDOOR:
		setValue(false, false, false);
		isDoor = true;
		doorType = "item";
		break;
	case OBSTACLE_TYPE::NORMALDOOR:
		setValue(false, false, false);
		isDoor = true;
		doorType = "normal";
		break;
	case OBSTACLE_TYPE::SKULDOOR:
		setValue(false, false, false);
		isDoor = true;
		doorType = "skul";
		break;
	case OBSTACLE_TYPE::START:
		setValue(false, false, false);
		isStart = true;
		break;
	}
}

void C_obstacle::setValue(bool _isUnmovable, bool _isDownJump, bool _isLand)
{
	isUnmovable = _isUnmovable;
	isDownJump = _isDownJump;
	isLand = _isLand;
}

