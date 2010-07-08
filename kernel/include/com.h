#include "stdint.h"
#include "ports.h"

// Einige Definitionen
#define IER 1
#define IIR 2
#define FCR 2
#define LCR 3
#define MCR 4
#define LSR 5
#define MSR 6

void init_com(uint16_t base, uint32_t baud, uint8_t parity, uint8_t bits);
uint8_t is_transmit_empty(uint16_t base);
void write_com(uint16_t base, uint8_t chr);
uint8_t serial_received(uint16_t base);
uint8_t read_serial(uint16_t base);