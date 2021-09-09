#include "Cube.hpp"

namespace custom
{
	Cube::Cube()
	{
		Cube::length = 1;
	}
	Cube::Cube(double length)
	{
		Cube::length = length;
	}
	void Cube::set_length(double length)
	{
		Cube::length = length;	
	}
	/*
	 * void Cube::set_colour(string colour)
	{
		Cube::colour = colour;	
	}
	*/
	double Cube::get_length()
	{
		return Cube::length;
	}
	/*
	string Cube::get_colour()
	{
		return Cube::colour;
	}
	*/
}
