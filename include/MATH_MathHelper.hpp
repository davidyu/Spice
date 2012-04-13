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
    {
        return fabsf((a - b) / ((b == 0.0f) ? 1.0f : b)) < EPSILON;
    }

    inline float DegToRad(float d)
    {
        return (d * PI) / 180.0f;
    }

    inline float RadToDeg(float r)
    {
        return (r * 180.0f) / PI;
    }

} // End namespace MATH

#endif // MATHHELPER_H
