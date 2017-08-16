#include "StdAfx.h"
#include "User2.h"


CUser2::CUser2(void)
{
	turn = false;
	hp = 100;
	x = 700;
	y = 300;
	item = CItem(x, y);
	moving = true;
}


CUser2::~CUser2(void)
{
}
