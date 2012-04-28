#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <cmath>

#define EPSILON             (1.0e-7f)
#define	PI					3.1415926535897932384626433832795028841971693993751f	//!< PI
#define	HALFPI				1.57079632679489661923f									//!< 0.5 * PI
#define	TWOPI				6.28318530717958647692f									//!< 2.0 * PI
#define	INVPI				0.31830988618379067154f									//!< 1.0 / PI

namespace MATH
{

    inline bool CloseTof(float a, float b)
    { return fabsf((a - b) / ((b == 0.0f) ? 1.0f : b)) < EPSILON; }

    inline float minf(float a, float b)
    { return (a<b) ? a : b; }

    inline float maxf(float a, float b)
    { return (a>b) ? a : b; }

    inline void clampf(float& v, float min, float max)
    {
        if (v<min)
        { v = min; return; }
        else if (v>max)
        { v = max; return; }
    }

    inline int signf(float v)
    { return (v < 0.0f) ? -1 : 1;}

    inline float lerpf(float min, float max, float percent)
    { return (max-min)*percent + min; }
    // Trig stuff
    inline float DegToRad(float d)
    { return (d * PI) / 180.0f; }

    inline float RadToDeg(float r)
    { return (r * 180.0f) / PI; }

    inline float cos_deg(float d)
    { return cosf(DegToRad(d)); }

    inline float sin_deg(float d)
    { return sinf(DegToRad(d)); }


} // End namespace MATH

#endif // MATHHELPER_H
