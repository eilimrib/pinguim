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


Rect& Rect::operator=(const Rect& r){
    this->x = r.x;
    this->y = r.y;
    this->w = r.w;
    this->h = r.h;
}


Rect& operator +(const Rect& r1, const Rect& r2){
    Rect res;

    res.x = r1.x + r2.x;
    res.y = r1.y + r2.y;
    res.w = r1.w + r2.w;
    res.h = r1.h + r2.h;

    return res;
}

Rect& operator +(const Rect& r, const Vec2& v){
    Rect res;

    res.x = r.x + v.x;
    res.y = r.x + v.y;

    return res;
}


Rect& operator -(const Rect& r1, const Rect& r2){
    Rect res;

    res.x = r1.x - r2.x;
    res.y = r1.y - r2.y;
    res.w = r1.w - r2.w;
    res.h = r1.h - r2.h;

    return res;
}

Rect& operator -(const Rect& r, const Vec2& v){
    Rect res;

    res.x = r.x - v.x;
    res.y = r.x - v.y;

    return res;
}
