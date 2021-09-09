#include "Game.hpp"

Game::Game()
{
	for(unsigned int i=0;i<3;i++)
	{
		Stackpile s;
		(Game::stacks).push_back(s);
	}
	custom::Cube c1(4);
	(Game::stacks.at(0)).push_back(c1);
	custom::Cube c2(3);
	(Game::stacks.at(0)).push_back(c2);
	custom::Cube c3(2);
	(Game::stacks.at(0)).push_back(c3);
	custom::Cube c4(1);
	(Game::stacks.at(0)).push_back(c4);
}
void Game::solve()
{
	while((Game::stacks.back()).stacksize() != 4)
	{
		legalmove(0,1);
		legalmove(0,2);
		legalmove(1,2);

	}
}
void Game::legalmove(unsigned int idx1, unsigned int idx2)
{
	if(stacks.at(idx1).stacksize()==0 && stacks.at(idx2).stacksize()!=0)	move(idx2, idx1);
	else if(stacks.at(idx2).stacksize()==0 && stacks.at(idx1).stacksize()!=0)	move(idx1, idx2);
	else if(stacks.at(idx1).top_cube() > stacks.at(idx2).top_cube())	move(idx2, idx1);
	else	move(idx1, idx2);
}

void Game::move(unsigned int idx1, unsigned int idx2)
{
	custom::Cube C = stacks.at(idx1).remove_cube();
	stacks.at(idx2).push_back(C);
}
		
