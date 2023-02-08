#define INCLUDE_SDL

#include "Rect.h"

Rect::Rect(){
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}


Rect::Rect(float x, float y, float w, float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}


Rect Rect::operator=(const Rect& r) const{
    return Rect(r.x, r.y, r.w, r.h);
}


Rect Rect::operator +(const Rect& r) const{
    return Rect(this->x + r.x, this->y + r.y, this->w + r.w, this->h + r.h);
}


Rect Rect::operator +(const Vec2& v) const{
    return Rect(this->x + v.x, this->y + v.y, this->w, this->h);
}


Rect Rect::operator -(const Rect& r) const{
    float res_x, res_y;
    
    res_x = this->x - r.x;
    res_y = this->y - r.y;
    if(this->w == r.w && this->h == r.h){
        if(res_x < 0){
            res_x = 0;
        }
        if(res_y < 0){
            res_y = 0;
        }
    }
    return Rect(res_x, res_y, this->w, this->h);
}

Rect Rect::operator -(const Vec2& v) const{
    float res_x, res_y;
    
    res_x = this->x - v.x;
    res_y = this->y - v.y;

    if(res_x < 0){
        res_x = 0;
    }
    if(res_y < 0){
        res_y = 0;
    }
    return Rect(res_x, res_y, this->w, this->h);
}


bool Rect::Contains(float coord_x, float coord_y){
    if (coord_x <= this->x && coord_y <= this->y){
        return true;
    }
    return false;
}


Vec2 Rect::Center()
{
    return Vec2((this->x + this->w / 2), (this->y + this->h / 2));
}


void Rect::SetOrigin(Vec2 origin){
    this->x = origin.x;
    this->y = origin.y;
}


Vec2 Rect::ToVec2() const{;
    return Vec2(this->x, this->y);
}

Vec2 Rect::Measures() const{
    return Vec2(this->w, this->h);
}