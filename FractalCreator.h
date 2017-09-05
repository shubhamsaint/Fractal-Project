
#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace c8master    //custom namespace which includes all the identifiers
{
	class FractalCreator
	{
	private:
		int m_width;
		int m_height;
		int *m_histogram;
		int *m_fractal;

		Bitmap m_bitmap;                   //class Bitmap instance
		ZoomList m_zoomList;			//class ZoomList instance
		int m_total;   //total

		vector<int> m_ranges;						//ranges of the type int stored in avcetor
		vector<RGB> m_colors;						//colors of the type RGB stored in vector
		vector<int> m_rangeTotals;					//range totals

		bool m_bGotFirstRange;   //false

		private:
			void calculateIteration();				
			void calculateTotalIterations();
			void calculateRangeTotals();
			void drawFractal();
			void writeBitmap(string name);


		public:
			int getRange(int iterations) const;

			FractalCreator(int width, int height);			//contructor to the fractalCreator class
			void addRange(double rangeEnd, const RGB& rgb);
			void addZoom(const Zoom& zoom);
			virtual ~FractalCreator();
			void run(string name);
	};
}
#endif