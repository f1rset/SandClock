//
// Created by f1rset on 11/28/24.
//

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define ROWS 48
#define COLS 64

typedef struct{
    float x;
    float y;
    float z;

} Vector;

typedef struct {
    int time;
    uint8_t display[ROWS][COLS];
    Vector vector;
} SandClock;

void inverseMatrix(uint8_t matrix[ROWS][COLS], uint8_t new_matrix[ROWS][COLS]);
void drawLines(uint8_t matrix[ROWS][COLS], uint8_t new_matrix[ROWS][COLS]);
void generateDisplay(uint8_t matrix[ROWS][COLS]);
void sandTick(uint8_t matrix[ROWS][COLS]);
void update(uint8_t display[ROWS][COLS]);

#ifndef SANDCLOCK_SANDCLOCKSTRUCT_H
#define SANDCLOCK_SANDCLOCKSTRUCT_H

#endif //SANDCLOCK_SANDCLOCKSTRUCT_H
