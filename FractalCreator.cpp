
#include "FractalCreator.h"
#include <assert.h>             // for assert function to check on ranges

using namespace std;

namespace c8master    //custom namespace to include all the identifiers
{
//different Ranges of the iterations are added 
void
FractalCreator::addRange(double rangeEnd, const RGB& rgb) 
{
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);

	if (m_bGotFirstRange) 
	{
		m_rangeTotals.push_back(0);
	}
	m_bGotFirstRange = true;
}
//Provide the category in which the particular iteration lies
int 
FractalCreator::getRange(int iterations) const 
{
	int range = 0;

	for(int i=1; i < m_ranges.size(); i++) 
	{
		range = i;
		if(m_ranges[i] > iterations) 
		{
			break;
		}
	}
	range--;
	assert(range > -1);    //check the range if it is negative the program dies
	assert(range < m_ranges.size());    //and ranges hould be less than the size pf the ranges

	return range;
}

//add the zoom into list of zoom

void
FractalCreator::addZoom(const Zoom& zoom)
{
	m_zoomList.add(zoom);
}

//constructor of the class Fractal Creator
FractalCreator::FractalCreator(int width, int height) :m_width(width),m_height(height),m_bitmap(m_width,m_height),m_zoomList(m_width,m_height)
{
	m_histogram = new int[Mandelbrot::MAX_ITERATIONS]();
	m_fractal = new int[m_width*m_height]();
	m_total=0;
	m_bGotFirstRange = false;
	m_zoomList.add(Zoom(m_width/2,m_height/2,4.0/m_width));
}

//Run all the functions

void
FractalCreator::run(string name) 
{  
	//calculate iterations
	calculateIteration();
	//calculate total iterations
	calculateTotalIterations();
	//calculate the range of the iterations
	calculateRangeTotals();
	//dray the fractal image
	drawFractal();
	//writing the fractal image in the file
	writeBitmap("test.bmp");

}

//destructor which deletes the pointer 
FractalCreator::~FractalCreator()
{
delete(m_fractal);
delete(m_histogram);
}

//calculate the iterations

void 
FractalCreator::calculateIteration() 
{

	for (int y = 0; y < m_height; y++) 
	{
		for (int x = 0; x < m_width; x++) 
		{
			pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first,coords.second);

			m_fractal[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) 
			{
				m_histogram[iterations]++;
			}	
		}
	}
}

//calculate the total range
void 
FractalCreator::calculateRangeTotals() 
{
	int rangeIndex = 0;

	for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) 
	{
		int pixels = m_histogram[i];

		if(i >= m_ranges[rangeIndex+1]) 
		{
			rangeIndex++;
		}

		m_rangeTotals[rangeIndex] += pixels;
	}
}

//calculate total iterations

void 
FractalCreator::calculateTotalIterations() 
{
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) 
	{
		m_total += m_histogram[i];
	}
}

//draw the fractal image

void 
FractalCreator::drawFractal() 
{
	RGB startColor(0, 0, 0);		//initialize the start color
	RGB endColor(255, 0, 255);		//initialize the end color
	RGB colorDiff = endColor - startColor;      //calculate the colorDiff 
	
	for(int y=0;y<m_height;y++)
    {
        for(int x=0;x<m_width;x++)
        {
            unsigned __int8 red=0;
            unsigned __int8 green=0;
            unsigned __int8 blue=0;

            int iterations=m_fractal[y*m_width+x] ;

            if(iterations!=Mandelbrot::MAX_ITERATIONS)
            {
            double hue=0.0;
            for(int i=0;i<=iterations;i++)
			{

               hue += ((double) m_histogram[i]) / m_total;    //hue variable is used to calculate the values for the colors to find
            }
				red = startColor.r + colorDiff.r * hue;
				green = startColor.g + colorDiff.g * hue;
				blue = startColor.b + colorDiff.b * hue;
        }
            m_bitmap.setPixel(x,y,red,green,blue);
        }
    }
}

void
FractalCreator::writeBitmap(string name) 
{
	m_bitmap.write(name);
}

}