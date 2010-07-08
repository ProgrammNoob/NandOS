#include <math.h>
#include <errno.h>
/**
 * Arkussinus berechnen.
 * @param x
 * @return
 */
double asin(double x)
{
    double res;
    /*if (x < -1 || x > 1)
	{
        errno = EDOM;
        return NAN;
    }*/
    res = 2 * atan(x / (1 + sqrt(1 - (x * x))));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Arkussinus berechnen.
 * @param x
 * @return
 */
float asinf(float x)
{
    float res;
    /*if (x < -1 || x > 1)
	{
        errno = EDOM;
        return NAN;
    }*/
    res = 2 * atanf(x / (1 + sqrtf(1 - (x * x))));
    return res;
}

/**
 * Arkussinus berechnen.
 * @param x
 * @return
 */
long double asinl(long double x)
{
    long double res;
    if (x < -1 || x > 1)
	/*{
        errno = EDOM;
        return NAN;
    }*/
    res = 2 * atanl(x / (1 + sqrtl(1 - (x * x))));
    return res;
}

#ifdef __cplusplus
};
#endif