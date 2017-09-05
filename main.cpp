#include <iostream>

#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace c8master;  //custom namespace which includes all the identifiers used in this project

int main() 
{
	// Size of the image or image ratio
	FractalCreator fractalCreator(800, 600);

	//Range of the iterations like we have 1000 then 0-300:300-500:500-1000

	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(255, 0, 65));
	fractalCreator.addRange(0.5, RGB(255, 255, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 45));
	
	//give the category in which 365 lies like 0-300 is 0th 300-500 is 1st and so on (iteration category)
		
	cout << fractalCreator.getRange(365) << endl;

	//zooming the image at the center x,y with the scale s

	fractalCreator.addZoom(Zoom(382, 116, 0.1));
	fractalCreator.addZoom(Zoom(408, 222, 0.1));

	//run all the backgroud function in fractal creator class

	fractalCreator.run("test.bmp");
	
	//check the process is completed or not

	cout << "Finished." << endl;

	//to still the console window

	string buffer;
	cin>>buffer;
	return 0;
}
