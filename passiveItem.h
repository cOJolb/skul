#pragma once
#include "item.h"
class C_player;
class passiveItem
{
};

class C_DimLightDarkcite : public C_item
{
public:
	//C_DimLightDarkcite();
	C_DimLightDarkcite(vector2 _pt);
	//~C_DimLightDarkcite();
public:
	virtual HRESULT init(C_player* _player);
	//virtual void release();
	//virtual void update(C_player* _player);
	virtual void render();
	virtual void render(vector2 _pt);
};

class C_MedalOfCarleon : public C_item
{
public:
	//C_MedalOfCarleon();
	C_MedalOfCarleon(vector2 _pt);
	//~C_MedalOfCarleon();
public:
	virtual HRESULT init(C_player* _player);
	//virtual void release();
	virtual void update(C_player* _player);
	virtual void render();
	virtual void render(vector2 _pt);
};