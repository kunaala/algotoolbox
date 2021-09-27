#pragma once
#include "Stackpile.hpp"

class Game
{
	public:
		Game();
		void solve();
//		void legalmove(unsigned int idx1, unsigned int idx2);
		void move_cube(Stackpile &idx1, Stackpile &idx2);
		void move(unsigned int start, unsigned int end, Stackpile &source, Stackpile &target, Stackpile &spare);
		void state(); 
//		friend std::ostream& operator<<(std::ostream& output, const Game G);
	private:
		std::vector<Stackpile> stacks;
};
