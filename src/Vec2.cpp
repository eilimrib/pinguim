#include "Vec2.h"
#include "math.h"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

Vec2 Vec2::operator =(const Vec2& v) const{
    return Vec2(v.x, v.y);
}

Vec2 Vec2::operator +(const Vec2& v) const{
    return Vec2(this->x + v.x, this->y + v.y);
}


Vec2 Vec2::operator -(const Vec2& v) const{
    return Vec2(this->x - v.x, this->y - v.y);
}


Vec2 Vec2::operator +=(const Vec2& v) const{
    return *this + v;
}


Vec2 Vec2::operator *(const float& f) const{
    return Vec2(this->x * f, this->y * f);
}

Vec2 Vec2::operator /(const float& f) const{
    return Vec2(this->x / f, this->y / f);
}

Vec2 Vec2::GetRotated(float angle){    
    return Vec2(this->x * cosf(angle) - this->y * sinf(angle), this->y * cosf(angle) + this->x * sinf(angle));
}


float Vec2::Distance(Vec2 vec1, Vec2 vec2){
    return Mag(vec1 - vec2);
}


float Vec2::DistanceTo(Vec2 &vector){
    return Mag(*this - vector);
}


float Vec2::atan() {
    return atan2(this->y, this->x);
}


float Vec2::Direct(Vec2 &vector) {
    Vec2 result = (vector - *this);
    return -atan2(result.y, result.x);
}