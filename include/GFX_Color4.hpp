// I bite my lip, and omit the "u"
#ifndef COLOR4_H
#define COLOR4_H


struct Color4
{
    float r,g,b,a;
    void set(float vr, float vg, float vb, float va)
    { r = vr; g = vg, b=vb, a=va; }
};

#endif // COLOR4_H
