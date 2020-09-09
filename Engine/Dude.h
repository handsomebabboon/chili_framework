#pragma once
#include "Graphics.h"
class Dude
{
public:
	Dude(int in_x , int in_y);
	void Draw(Graphics& gfx);


private:
	int x;
	int y;
	static constexpr int speed = 10;
	static constexpr int width = 20;
	static constexpr int height = 20;
};

