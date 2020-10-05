#pragma once
#include <string>
#include <cstdint>
#include <memory>
using namespace std;

namespace cave {
	class Bitmap
	{
	private:
		int m_width{ 0 };
		int m_height{ 0 };
		unique_ptr <uint8_t[]> m_pPixels{ nullptr };
	public:
		Bitmap() = default;
		Bitmap(int w, int h);
		Bitmap(const Bitmap&) = default;
		void operator=(const Bitmap&);
		void setPixel(int x, int y, uint8_t R, uint8_t G, uint8_t B);
		bool write(string filename);
		~Bitmap() = default;

	};
}