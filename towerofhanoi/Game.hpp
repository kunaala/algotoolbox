#pragma once
#include "Stackpile.hpp"

class Game
{
	public:
		Game();
		void solve();
		void legalmove(unsigned int idx1, unsigned int idx2);
		void move(unsigned int idx1, unsigned int idx2);

	private:
		std::vector<Stackpile> stacks;

};
