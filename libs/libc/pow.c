#include <math.h>
/**
 * Zahl potenzieren.
 * @param x
 * @param y
 * @return
 */
double pow(double x, double y)
{
	return exp(y * log(x));
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Zahl potenzieren.
 * @param x
 * @param y
 * @return
 */
float powf(float x, float y)
{
	return exp(y * log(x));
}

/**
 * Zahl potenzieren.
 * @param x
 * @param y
 * @return
 */
long double powl(long double x, long double y)
{
	return exp(y * log(x));
}

#ifdef __cplusplus
};
#endif