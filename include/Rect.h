#ifndef RECT_HEADERS
#define RECT_HEADERS
#include "Vec2.h"
#include <string>

class Rect{
private:
    float x, y, w, h;
public:
    Rect();
    Rect(float x, float y, float w, float h);

    Rect& operator =(Rect& r);
    friend Rect& operator +(Rect& r1, Rect& r2);
    friend Rect& operator +(Rect& r, Vec2& v);
    friend Rect& operator -(Rect& r1, Rect& r2);
    friend Rect& operator -(Rect& r, Vec2& v);
};

#endif