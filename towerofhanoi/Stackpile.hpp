#pragma once
#include "Cube.hpp"
#include "vector"
class Stackpile
{
	public:
		Stackpile();
		void push_back(custom::Cube &c);
		custom::Cube remove_cube();
		unsigned int top_cube();
		unsigned int stacksize();
	private:
		std::vector<custom::Cube> content;
			
};
