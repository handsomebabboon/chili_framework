#pragma once
#include "Graphics.h"
#include "Dude.h"
class Poo
{
public:
	Poo(int in_x, int in_y);
	void Draw(Graphics& gfx);
	void Move();
	bool processConsumption(Dude& dude);
private:
	int x;
	int y;
	static constexpr int width = 24;
	static constexpr int height = 24;
	static constexpr int Vel = 10;
	bool isEaten = false;
};

