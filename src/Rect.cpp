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


Rect& Rect::operator=(Rect& r){
    this->x = r.x;
    this->y = r.w;
    this->w = r.w;
    this->h = r.h;
}


Rect& operator +(Rect& r1, Rect& r2){
    Rect res;

    res.x = r1.x + r2.x;
    res.y = r1.y + r2.y;
    res.w = r1.w + r2.w;
    res.h = r1.h + r2.h;

    return res;
}

Rect& operator +(Rect& r, Vec2& v){
    Rect res;

    res.x = r.x + v.getX();
    res.y = r.x + v.getY();

    return res;
}


Rect& operator -(Rect& r1, Rect& r2){
    Rect res;

    res.x = r1.x - r2.x;
    res.y = r1.y - r2.y;
    res.w = r1.w - r2.w;
    res.h = r1.h - r2.h;

    return res;
}

Rect& operator -(Rect& r, Vec2& v){
    Rect res;

    res.x = r.x - v.getX();
    res.y = r.x - v.getY();

    return res;
}
