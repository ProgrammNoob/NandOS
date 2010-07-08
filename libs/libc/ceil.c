#include <stdint.h>
/**
 * Rundet auf nächste Ganzzahl auf.
 * @param x
 * @return
 */
double ceil(double x)
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
	: "=t" (res) : "0" (x), "m" (control_word), "r" (0x800) : "eax");

	return res;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Rundet auf nächste Ganzzahl auf.
 * @param x
 * @return
 */
float ceilf(float x)
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
	: "=t" (res) : "0" (x), "m" (control_word), "r" (0x800) : "eax");

	return res;
}

/**
 * Rundet auf nächste Ganzzahl auf.
 * @param x
 * @return
 */
long double ceill(long double x)
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
	: "=t" (res) : "0" (x), "m" (control_word), "r" (0x800) : "eax");

	return res;
}

#ifdef __cplusplus
}
#endif