#include <math.h>
/**
 * Tangens berechnen.
 * @param x
 * @return
 */
double tan(double x)
{
    double res;
    asm("fptan;"
        "fstp %%st(0)": "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Tangens berechnen.
 * @param x
 * @return
 */
float tanf(float x)
{
    float res;
    asm("fptan;"
        "fstp %%st(0)": "=t" (res) : "0" (x));
    return res;
}

/**
 * Tangens berechnen.
 * @param x
 * @return
 */
long double tanl(long double x)
{
    long double res;
    asm("fptan;"
        "fstp %%st(0)": "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
};
#endif