/*
 * seg7.h
 *
 *  Created on: Feb 27, 2023
 *      Author: Mateusz Krzyściak
 */

#ifndef INC_SEG7_H_
#define INC_SEG7_H_

#include <stdint.h>

// Pokaż cyfrę na wyświetlaczu
// value - cyfra do wyświetlenia
void seg7_show_digit(uint32_t value);

// Pokaż liczbę na wyświetlaczu
// value - liczba do wyświetlenia
void seg7_show(uint32_t value);

// Funkcja pomocnicza
// Zmiana aktywnego wyświetlacza
void seg7_update(void);
#endif /* INC_SEG7_H_ */
