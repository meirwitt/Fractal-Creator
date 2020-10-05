#pragma once
#include <cstdint>

namespace cave {
#pragma pack(2) // store value with blocks of two bytes

	struct BitmapInfoHeader {
		int32_t HeaderSize{ 40 };
		int32_t width;
		int32_t height;
		int16_t planes{ 1 };
		int16_t bitPerPixel{ 24 };
		int32_t compression{ 0 };
		int32_t dataSize{ 0 };
		int32_t horizontalResolution{ 2400 };
		int32_t verticalResolution{ 2400 };
		int32_t colors{ 0 };
		int32_t importantColors{ 0 };
	};
#pragma pop
}