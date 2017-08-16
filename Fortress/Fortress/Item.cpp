#include "StdAfx.h"
#include "Item.h"

CItem::CItem(void)
{
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	itemnum = 0;
	damage = 10;
	moving = false;
}
CItem::CItem(int x1, int y1)
{
	x = x1;
	y = y1;
	damage = 10;
	moving = false;
}

CItem::~CItem(void)
{
}

void CItem::Move()
{
	vy += 0.4;
	if(x < 0)	x -= vx;
	else		x += vx;
	y += vy;
}

void CItem::SetItem(int num){
	itemnum = num;
	switch(itemnum){
	case 0:
		damage = 10;
		break;
	case 1:
		damage = 20;
		break;
	case 2:
		damage = 30;
		break;
	}
}
void CItem::Reset(int x1,int y1){
	x = x1;
	y = y1; 
	vx = 0;
	vy = 0;
	SetItem(0);
}