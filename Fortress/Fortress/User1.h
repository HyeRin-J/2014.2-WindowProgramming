#pragma once
#include "Item.h"

class CUser1
{
public:
	bool turn;
	int hp;
	int x, y;
	CItem item;
	bool moving;

	CUser1(void);
	~CUser1(void);
};

