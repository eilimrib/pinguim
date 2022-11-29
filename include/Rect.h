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
    Rect& operator =(const Rect& r);
    friend Rect& operator +(const Rect& r1, const Rect& r2);
    friend Rect& operator +(const Rect& r, const Vec2& v);
    friend Rect& operator -(const Rect& r1, const Rect& r2);
    friend Rect& operator -(const Rect& r, const Vec2& v);
};

#endif