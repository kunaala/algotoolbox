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

custom::Cube Stackpile::back()
{
	return (Stackpile::content).back();
	
}
void Stackpile::remove_top_cube()
{
	(Stackpile::content).erase((Stackpile::content).end()-1);
}
unsigned int Stackpile::top_cube()
{
	//std::cout<<"topmost Cube Length: "<< ((Stackpile::content).back()).get_length()<<'\n';
	return ((Stackpile::content).back()).get_length();
	
}

unsigned int Stackpile::stacksize()
{
	//std::cout<<"size of stack"<<(Stackpile::content).size()<<'\n';
	return (Stackpile::content).size();
}

std::ostream& operator<<(std::ostream& output, Stackpile S)
{
	std::cout<<"inside stack"<<'\n';
	for(unsigned int i=0; i< S.content.size(); i++)	output<<(S.content.at(i)).get_length()<<'\t';
	std::cout<<'\n';
	return output;
}
