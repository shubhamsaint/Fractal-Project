
#include "RGB.h"

namespace c8master  //custom namespace
{
// RGB class constructor initialize the value of Red, green,blue pixel
RGB::RGB(double r, double g, double b): r(r), g(g), b(b) 
{
	// TODO Auto-generated constructor stub

}

//Operator "-" overloading to calculate the difference between the colors

RGB
operator-(const RGB& first, const RGB& second) 
{
	return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
}

}
