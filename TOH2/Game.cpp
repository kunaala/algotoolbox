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
	std::cout<<"game initialized with "<<(Game::stacks).size()<<" stacks: "<<"stack 0 initialized with "<<(Game::stacks.at(0)).stacksize()<<"cubes"<<'\n';
}
void Game::state()
{
		std::cout<<"Game state after this iteration"<<'\n';
		for(unsigned int i=0; i< Game::stacks.size();i++)
		{
			std::cout<<Game::stacks.at(i)<<'\n';
		}

}
void Game::move_cube(Stackpile &idx1, Stackpile &idx2)
{
	custom::Cube C = idx1.back();
	idx2.push_back(C);
	idx1.remove_top_cube();
}
/*
 * start is the starting cube of the substack
 * end is the topmost cube of the substack
 * source is the index of the stack; where the substack is located currently
 * target is the index of the stack; where the substack has to be moved in this iteration
 * spare is the index of the Spare stack that is used for moving operations
 * *****************
*/
void Game::move(unsigned int start, unsigned int end, Stackpile &source, Stackpile &target, Stackpile &spare)
{
	if ( start == end)
	{
		Game::move_cube(source, target);
		Game::state();
	}
	else//recursive loop starts here
	{
		Game::move(start+1, end, source, spare, target);
		Game::move(start, start, source, target, spare);
		Game::move(start+1, end, spare, target, source);
	}
}
void Game::solve()
{
	
	//Initial problem - which will be further split into subproblems in the recursive loop//
	Game::move(0,3, stacks.at(0), stacks.at(2), stacks.at(1));	
	Game::state();
	
}


