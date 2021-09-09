#pragma once
namespace custom
{
	class Cube
	{
		public:
			Cube(); //unit cube
			Cube(double length);
			void volume();
			//void volume(double length);
			//void surface_area();
			//void surface_area(double length);
			void set_length(double length);
			//void set_colour(string colour);
			double get_length();
			//string get_colour();
		private:
			double length;
			//string colour;
	};
}
