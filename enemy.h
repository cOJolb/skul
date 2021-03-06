#pragma once
#include "object.h"
class C_enemy : public C_object
{
protected:
	UNIT_TYPE type;
	int count;
	bool superArmor;
private:
public:
	C_enemy();
	virtual~C_enemy();

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

public:
	UNIT_TYPE getUnitType() { return type; }
	bool isSuperArmor() { return superArmor; }
};
