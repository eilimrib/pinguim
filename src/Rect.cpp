#define INCLUDE_SDL

#include "Rect.h"

Rect::Rect(){
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}


Rect::Rect(float x, float y, float w, float h){
    x = x;
    y = y;
    w = w;
    h = h;
}


Rect& Rect::operator=(Rect& r){
    x = r.x;
    y = r.w;
    w = r.w;
    h = r.h;
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
