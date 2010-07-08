#include <stdint.h>

/**
 * Größtmögliche Ganzzahl ermitteln, die kleiner oder gleich dem Argument ist.
 * @param x
 * @return
 */
double floor(double x)
{
	long double res;
	uint16_t control_word;

	asm(
	// Rundungsmodus setzen
	"fnstcw %2;"
	"mov %2, %%eax;"
	"orl %3, %2;"
	"fldcw %2;"
	// Zahl auf dem Stack runden
	"frndint;"

	// Wieder den Standardrundungsmodus setzen
	"mov %%eax, %2;"
	"fldcw %2;"
	: "=t" (res) : "0" (x), "m" (control_word), "r" (0x400) : "eax");

	return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Größtmögliche Ganzzahl ermitteln, die kleiner oder gleich dem Argument ist.
 * @param x
 * @return
 */
float floorf(float x)
{
	long double res;
	uint16_t control_word;

	asm(
	// Rundungsmodus setzen
	"fnstcw %2;"
	"mov %2, %%eax;"
	"orl %3, %2;"
	"fldcw %2;"
	// Zahl auf dem Stack runden
	"frndint;"

	// Wieder den Standardrundungsmodus setzen
	"mov %%eax, %2;"
	"fldcw %2;"
	: "=t" (res) : "0" (x), "m" (control_word), "r" (0x400) : "eax");

	return res;
}

/**
 * Größtmögliche Ganzzahl ermitteln, die kleiner oder gleich dem Argument ist.
 * @param x
 * @return
 */
long double floorl(long double x)
{
	long double res;
	uint16_t control_word;

	asm(
	// Rundungsmodus setzen
	"fnstcw %2;"
	"mov %2, %%eax;"
	"orl %3, %2;"
	"fldcw %2;"
	// Zahl auf dem Stack runden
	"frndint;"

	// Wieder den Standardrundungsmodus setzen
	"mov %%eax, %2;"
	"fldcw %2;"
	: "=t" (res) : "0" (x), "m" (control_word), "r" (0x400) : "eax");

	return res;
}

#ifdef __cplusplus
}
#endif