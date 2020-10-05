#include "RGB.h"

RGB operator-(const RGB& f, const RGB& s)
{
    
    return RGB(f.red-s.red, f.green - s.green, f.blue - s.blue);
}
