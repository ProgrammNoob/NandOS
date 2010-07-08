
/**
 * Berechnet den Kosinus.
 * @param x
 * @return
 */
double cos(double x)
{
    double res;
    asm("fcos;" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Berechnet den Kosinus.
 * @param x
 * @return
 */
float cosf(float x)
{
    float res;
    asm("fcos" : "=t" (res) : "0" (x));
    return res;
}

/**
 * Berechnet den Kosinus.
 * @param x
 * @return
 */
long double cosl(long double x)
{
    long double res;
    asm("fcos" : "=t" (res) : "0" (x));
    return res;
}

#ifdef __cplusplus
};
#endif