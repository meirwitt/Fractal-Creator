#pragma once
#include <string>
#include <iostream>
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "Zoom.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <math.h>
#include "RGB.h"
#include <vector>

using namespace std;

namespace cave {
	class FractalCreator
	{
	private:
		int m_total{ 0 };
		int m_height;
		int m_width;
		unique_ptr<int[]> m_histogram;
		unique_ptr<int[]> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomlist;

		vector<int> m_ranges;
		vector<RGB> m_color;

		vector<int> m_rangeTotals;
		bool m_bGotFirstRange{ false };

		int getRange(int iterations) const;

	public:
		FractalCreator(int, int);
		~FractalCreator() = default;

		void addRange(int rangeEnd, RGB rgb);
		void calculateIteration();
		void drawFractal();
		void addZoom(const Zoom&);
		void writeBitmap(string);
		void calculateRangeTotal();

	};
}

