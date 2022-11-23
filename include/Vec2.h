#ifndef VEC2_HEADERS
#define VEC2_HEADERS
#include <string>

class Vec2{
private:
    float x,y;
public:
    Vec2();
    Vec2(float x, float y);
    inline float getX() { return x; };
    inline float getY() { return y; };
};

#endif