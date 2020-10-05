#pragma once
#include <stdint.h>

struct RGB
{
	double red;
	double green;
	double blue;

	RGB(double r, double g, double b) : red(r), green(g), blue(b) {};

};
RGB operator-(const RGB&, const RGB&);

