#pragma once
#include "Cube.hpp"
#include "vector"
class Stackpile
{
	public:
		Stackpile();
		void push_back(custom::Cube &c);
		custom::Cube back();
		void remove_top_cube();
		unsigned int top_cube();
		unsigned int stacksize();

		friend std::ostream& operator<<(std::ostream& output, Stackpile S);
	private:
		std::vector<custom::Cube> content;
			
};
