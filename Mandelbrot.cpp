#include "Mandelbrot.h"
#include <complex>

using namespace std;
namespace c8master
{
int
Mandelbrot::getIterations(double x,double y)     //return the iterations by using the mandelbrot formula
{

    complex<double> z = 0;							//complex numbers with real and imaginary part are distributed
    complex<double> c(x,y);

    int iterations =0;

    while(iterations < MAX_ITERATIONS)
    {
        z= z*z+c;

        if(abs(z)>2)
		{
            break;
        }
        iterations++;
    }
return iterations;
}

}
