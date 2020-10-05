#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include <fstream>
using namespace std;


namespace cave {
	Bitmap::Bitmap(int w, int h) : m_width(w), m_height(h), m_pPixels(new uint8_t[w * h * 3]{}) {
	}

	void Bitmap::operator=(const Bitmap& b)
	{
		m_width = b.m_width;
		m_height = b.m_height;
		m_pPixels.reset(b.m_pPixels.get());
	}

	void Bitmap::setPixel(int x, int y, uint8_t R, uint8_t G, uint8_t B)
	{
		uint8_t* pPixel = m_pPixels.get();

		pPixel += (y * 3) * m_width + (x * 3);

		pPixel[0] = B;
		pPixel[1] = G;
		pPixel[2] = R;
	}

	bool Bitmap::write(string filename)
	{
		BitmapFileHeader fileheader;
		BitmapInfoHeader infoheader;

		fileheader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
		fileheader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoheader.width = m_width;
		infoheader.height = m_height;

		ofstream file;
		file.open(filename.c_str(), ios::out | ios::binary);
		if (!file) return false;

		file.write((char*)&fileheader, sizeof(fileheader));
		file.write((char*)&infoheader, sizeof(infoheader));
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);

		file.close();

		//convert file.bmp to jpeg

		if (!file) return false;

		return true;
	}
}