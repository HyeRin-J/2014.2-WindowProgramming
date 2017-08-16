#pragma once
#include "Item.h"

class CUser2
{
public:
	bool turn;
	int hp;
	int x, y;
	CItem item;
	bool moving;

	CUser2(void);
	~CUser2(void);
};

