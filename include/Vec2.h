#ifndef VEC2_HEADERS
#define VEC2_HEADERS
#include <string>

class Vec2{
public:
    float x,y;
    Vec2();
    Vec2(float x, float y);
    Vec2 GetRotated(float angle);

    Vec2& operator =(const Vec2& r);
    friend Vec2& operator +(const Vec2& r1, const Vec2& r2);
    friend Vec2& operator -(const Vec2& r1, const Vec2& r2);
};

#endif