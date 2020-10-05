#include "FractalCreator.h"
#include <cassert>

namespace cave {
	int FractalCreator::getRange(int iterations) const
	{

		int range = 0;

		for (int i = 1; i < m_ranges.size(); i++)
		{
			range = i;

			if (m_ranges[i] > iterations) break;

		}
		range--;

		assert(range > -1);
		assert(range < m_ranges.size());

		return 0;
	}
	FractalCreator::FractalCreator(int width, int height) :m_height(height), m_width(width), m_zoomlist(width, height),
		m_total(0), m_histogram(unique_ptr<int[]>(new int[Mandelbrot::MAX_ITERATIONS + 1]{ 0 })),
		m_fractal(unique_ptr<int[]>(new int[width * height]{ 0 })), m_bitmap(width, height)
	{}

	void FractalCreator::addRange(int rangeEnd, RGB rgb)
	{
		m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
		m_color.push_back(rgb);

		if (m_bGotFirstRange) {
			m_rangeTotals.push_back(0);
		}

		m_bGotFirstRange = true;

		
	}

	void FractalCreator::calculateIteration()
	{
		ZoomList zoomlist(m_width, m_height);
		zoomlist.add(Zoom(m_width / 2, m_height / 2, 3.0 / m_width));
		//zoomlist.add(Zoom(312, 304, 0.1));

		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{

				pair<double, double> coords = zoomlist.doZoom(x, y);

				int iterations = Mandelbrot::getIterations(coords.first, coords.second);
				m_fractal[y * m_width + x] = iterations;

				if (iterations != Mandelbrot::MAX_ITERATIONS) {
					m_histogram[iterations]++;
				}
			}
		}
		for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
			m_total += m_histogram[i];
		}
	}

	void FractalCreator::drawFractal()
	{

		RGB startcolor(0, 0, 20), endcolor(0, 0, 255), diff = endcolor - startcolor;
		for (int y = 0; y < m_height; y++)
		{
			for (int x = 0; x < m_width; x++)
			{
				int iterations = m_fractal[y * m_width + x];
				

				int range = getRange(iterations);
				int rangeTotal = m_rangeTotals[range];
				int rangeStart = m_ranges[range];

				RGB& startColor = m_color[range];
				RGB& endtColor = m_color[range+1];
				RGB colorDiff = endtColor - startColor;


				double hue = 0.0;
				uint8_t red = 0;
				uint8_t green = 0;
				uint8_t blue = 0;

				if (iterations != Mandelbrot::MAX_ITERATIONS) {

					int totalPixels = 0;

					for (int i = rangeStart; i < iterations; i++)
					{
						totalPixels += m_histogram[i];
					}

					for (int i = 0; i <= iterations; i++)
					{
						hue += ((double)m_histogram[i]) / m_total;
					}
					red =   startColor.red   + colorDiff.red   * (double)totalPixels / rangeTotal;
					green = startColor.green + colorDiff.green * (double)totalPixels / rangeTotal;
					blue =  startColor.blue  + colorDiff.blue  * (double)totalPixels / rangeTotal;
					

					m_bitmap.setPixel(x, y, red, green, blue);
				}
			}
		}
	}

	void FractalCreator::addZoom(const Zoom& z)
	{
		m_zoomlist.add(z);
	}

	void FractalCreator::writeBitmap(std::string filename)
	{
		//write fractal
		if (m_bitmap.write(filename))
			cout << "Complete";
		else
			cout << "Error";

	}
	void FractalCreator::calculateRangeTotal()
	{
		int rangeIndex = 0;
		for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
		{
			int pixels = m_histogram[i];

			if (i >= m_ranges[rangeIndex + 1]) {
				rangeIndex++;
			}

			m_rangeTotals[rangeIndex] += pixels;

		}
		for (int value : m_rangeTotals) {
			cout << "Range Total: " << value << endl;
		}
	}
}