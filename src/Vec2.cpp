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

Vec2& Vec2::operator=(Vec2& r){
    this->x = r.x;
    this->y = r.y;
}

Vec2& operator +(const Vec2& r1, const Vec2& r2){
    Vec2 res;

    res.x = r1.x + r2.x;
    res.y = r1.y + r2.y;
    return res;
}


Vec2& operator -(Vec2& r1, Vec2& r2){
    Vec2 res;

    res.x = r1.x - r2.x;
    res.y = r1.y - r2.y;
    return res;
}

Vec2 Vec2::GetRotated(float angle){
    float tempx = x;
    float tempy = y;
    this->x = tempx * cosf(angle) - tempy * sinf(angle);
    this->y = tempy * cosf(angle) + tempx * sinf(angle);
    
    return this;
}