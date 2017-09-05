
#include "ZoomList.h"

namespace c8master 
{
ZoomList::ZoomList(int width, int height) :	m_width(width), m_height(height)    //constructor to initialize all the variable
{
	m_xCenter=0;
	m_yCenter=0;
	m_scale=1.0;
}

void 
ZoomList::add(const Zoom& zoom) 
{
	zooms.push_back(zoom);									//zoom values are pushbacked into the vector 

	m_xCenter += (zoom.x - m_width / 2) * m_scale;				//calculate the new center
	m_yCenter += -(zoom.y - m_height / 2) * m_scale;

	m_scale *= zoom.scale;										//update the scale value
}

pair<double, double> 
ZoomList::doZoom(int x, int y)															//zoom is procesesed on the image and x and y are returned back as updated value
{
	double xFractal = (x - m_width / 2) * m_scale + m_xCenter;						
	double yFractal = (y - m_height / 2) * m_scale + m_yCenter;

	return pair<double, double>(xFractal, yFractal);
}

}
