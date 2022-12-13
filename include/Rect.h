#ifndef RECT_HEADERS
#define RECT_HEADERS
#include "Vec2.h"
#include <string>

class Rect{
public:
    float x, y, w, h;
    Rect();
    Rect(float x, float y, float w, float h);
    
    bool Contains(float x, float y);
    Rect operator =(const Rect& r) const;
    Rect operator +(const Rect& r) const;
    Rect operator +(const Vec2& v) const;
    Rect operator -(const Rect& r) const;
    Rect operator -(const Vec2& v) const;
};

#endif