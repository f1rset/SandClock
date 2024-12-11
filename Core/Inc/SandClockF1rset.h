//
// Created by f1rset on 11/12/24.
//
#include <stdint.h>
#define ROWS 48
#define COLS 48

typedef struct {
    uint8_t upper_screen[ROWS][COLS];
    uint8_t bottom_screen[ROWS][COLS];
} SandClock;

#ifndef SANDCLOCKF1RSET_H
#define SANDCLOCKF1RSET_H
void generate_displays(SandClock* clock);
void sandTick(uint8_t upper_display[ROWS][COLS], uint8_t bottom_display[ROWS][COLS]);
void update(uint8_t display[ROWS][COLS]);
void drawLines(uint8_t matrix[ROWS][COLS], uint8_t temp);
void updateBottom(uint8_t display[ROWS][COLS]);
void rotate(uint8_t matrix1[ROWS][COLS]);
#endif //SANDCLOCKF1RSET_H
