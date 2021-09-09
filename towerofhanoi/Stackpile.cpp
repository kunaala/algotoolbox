#include "Stackpile.hpp"
#include <iostream>
Stackpile::Stackpile()
{
	Stackpile::content = {};
}

void Stackpile::push_back(custom::Cube &c)
{
	(Stackpile::content).push_back(c);

}

custom::Cube Stackpile::remove_cube()
{
	custom::Cube C = (Stackpile::content).back();
	(Stackpile::content).erase((Stackpile::content).end());
	return C;
}

unsigned int Stackpile::top_cube()
{
	std::cout<<"topmost Cube Length: "<< ((Stackpile::content).back()).get_length()<<'\n';
	return ((Stackpile::content).back()).get_length();
	
}

unsigned int Stackpile::stacksize()
{
	std::cout<<(Stackpile::content).size()<<'\n';
	return (Stackpile::content).size();
}
