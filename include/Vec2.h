#ifndef VEC2_HEADERS
#define VEC2_HEADERS
#include <cmath>
#define PI M_PI

class Vec2{
public:
    float x,y;
    Vec2();
    Vec2(float x, float y);
    Vec2 GetRotated(float angle);

    Vec2 operator +(const Vec2& v) const;
    Vec2 operator -(const Vec2& v) const;
    Vec2 operator +=(const Vec2& v) const;
    Vec2 operator *(const float& f) const;
    Vec2 operator /(const float& f) const;

    static inline float Mag(const Vec2 &vec){
        return sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    static inline Vec2 Normalize(const Vec2 &vec){
        return vec * (1.f / Mag(vec));
    }
    static inline Vec2 Rotate(const Vec2 &vec, float angle){
        return Vec2(
            vec.x * cos(angle) - vec.y * sin(angle),
            vec.y * cos(angle) + vec.x * sin(angle));
    }
    float Distance(Vec2 vec1, Vec2 vec2);
    float DistanceTo(Vec2 &vector);
    float Atan2();
    float Atan2(Vec2 v1, Vec2 v2);
    float Direct(Vec2 &vector);
};

#endif