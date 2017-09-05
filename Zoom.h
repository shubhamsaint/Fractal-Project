#ifndef ZOOM_H_
#define ZOOM_H_

namespace c8master
{

struct Zoom 
{
	int x;
	int y;
	double scale;

	Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};
};

}
#endif