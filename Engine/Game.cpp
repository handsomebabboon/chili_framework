/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
    rng(rd()),
    xDist(0,770),
    yDist(0,570),
    dude(xDist(rng),yDist(rng)),
    poo0(xDist(rng),yDist(rng)),
    poo1(xDist(rng), yDist(rng)),
    poo2(xDist(rng), yDist(rng))
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    dude.Move(wnd.kbd);
    dude.ClampScreen();

    poo0.processConsumption(dude);
    poo1.processConsumption(dude);
    poo2.processConsumption(dude);

}

void Game::ComposeFrame()
{
    dude.Draw(gfx);

    if (!poo0.IsEaten()) {
        poo0.Draw(gfx);
    }

    if (!poo1.IsEaten()) {
        poo1.Draw(gfx);
    }

    if (!poo2.IsEaten()) {
        poo2.Draw(gfx);
    }

}
