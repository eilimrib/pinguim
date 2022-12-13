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

Vec2 Vec2::operator=(const Vec2& v) const{
    return Vec2(v.x, v.y);
}

Vec2 Vec2::operator +(const Vec2& v) const{
    return Vec2(this->x + v.x, this->y + v.y);
}


Vec2 Vec2::operator -(const Vec2& v) const{
    return Vec2(this->x - v.x, this->y - v.y);
}

Vec2 Vec2::GetRotated(float angle){    
    return Vec2(this->x * cosf(angle) - this->y * sinf(angle), this->y * cosf(angle) + this->x * sinf(angle));
}