#include <iostream>

#include "FractalCreator.h"
#include "RGB.h"
using namespace std;
using namespace cave;


int main() {
	int const WIDTH = 800; int const HEIGHT = 600;

	FractalCreator fractalcreator(WIDTH, HEIGHT);

	fractalcreator.addRange(0.0, RGB(0, 0, 0));
	fractalcreator.addRange(0.3, RGB(255, 0, 0));
	fractalcreator.addRange(0.5, RGB(255, 255, 0));
	fractalcreator.addRange(1.0, RGB(255, 255, 255));


	fractalcreator.calculateIteration();
	fractalcreator.addZoom(Zoom(WIDTH / 2, HEIGHT / 2, 2.0 / WIDTH));
	fractalcreator.calculateRangeTotal();
	fractalcreator.drawFractal();
	fractalcreator.writeBitmap("test.bmp");


	return 0;

	
}