#include "StdAfx.h"
#include "User1.h"


CUser1::CUser1(void)
{
	turn = true;
	hp = 100;
	x = 100;
	y = 300;
	item = CItem(x, y);
	moving = true;
}

CUser1::~CUser1(void)
{
}
