
/**
 * Sinus berechnen.
 * @param x
 * @return
 */
double sin(double x)
{
    double res;
    asm("fsin" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Sinus berechnen.
 * @param x
 * @return
 */
float sinf(float x)
{
    float res;
    asm("fsin" : "=t" (res) : "0" (x));
    return res;
}

/**
 * Sinus berechnen.
 * @param x
 * @return
 */
long double sinl(long double x)
{
    long double res;
    asm("fsin" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
};
#endif