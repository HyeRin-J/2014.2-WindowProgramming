#pragma once
class CItem
{
public:
	double x, y;
	double vx, vy;
	int itemnum;
	int damage;
	bool moving;

	CItem(void);
	CItem(int x, int y);
	~CItem(void);

	void Move();
	void SetItem(int num);
	void Reset(int, int);
};

