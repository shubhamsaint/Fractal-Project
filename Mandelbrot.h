#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace c8master
{
class Mandelbrot
{
	public:
		static const int MAX_ITERATIONS = 1000;           //initialse the maximum iteration of the mandelbrot
		public:
			Mandelbrot();
			virtual ~Mandelbrot();
			static int getIterations(double x,double y);      //get the iteration 
};
}
#endif