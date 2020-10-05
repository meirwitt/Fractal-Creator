#include "Mandelbrot.h"
#include <complex>

using namespace std;

Mandelbrot::Mandelbrot()
{
}

Mandelbrot::~Mandelbrot()
{
}

int Mandelbrot::getIterations(double x, double y)// get the number of iteration needed to x+yi to exceded 2 in the 
                                                 // equetion z^2 + c.
{
    complex<double> z = 0;
    complex<double> c(x,y);

    int iteration = 0;

    while (iteration < MAX_ITERATIONS) {
        z = z * z + c;

        if (abs(z) > 2) break;
        iteration++;
    }

    return iteration;
}
