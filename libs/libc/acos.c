#include <math.h>
#include <errno.h>
/**
 * Arkukosinus berechnen.
 * @param x
 * @return
 */
double acos(double x)
{
    double res;
    /*if (x < -1 || x > 1)
	{
        errno = EDOM;
        return NAN;
    }*/
    res = 1.570796326794896619 - asin(x);
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Arkukosinus berechnen.
 * @param x
 * @return
 */
float acosf(float x)
{
    float res;
    /*if (x < -1 || x > 1)
	{
        errno = EDOM;
        return NAN;
    }*/
    res = 1.570796326794896619 - asin(x);
    return res;
}

/**
 * Arkukosinus berechnen.
 * @param x
 * @return
 */
long double acosl(long double x)
{
    long double res;
    /*if (x < -1 || x > 1)
	{
        errno = EDOM;
        return NAN;
    }*/
    res = 1.570796326794896619 - asin(x);
    return res;
}

#ifdef __cplusplus
}
#endif