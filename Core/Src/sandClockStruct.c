//
// Created by f1rset on 11/28/24.
//
#include "sandClockStruct.h"


void inverseMatrix(uint8_t matrix[ROWS][COLS], uint8_t new_matrix[ROWS][COLS]) {
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            new_matrix[i][j] = (matrix[i][j] == 0) ? 1 : 0;
        }
    }
}

void drawLines(uint8_t matrix[ROWS][COLS], uint8_t new_matrix[ROWS][COLS]) {
    int hard = COLS/2 + ROWS;

    for (int y = 0; y<ROWS; y++){
        for (int x = 0; x<COLS ; x++) {
            if (x+y >= hard | COLS-1-x+y >= hard){
                new_matrix[y][x] = 0;
            }
            else{
                new_matrix[y][x] = matrix[y][x];
            }
        }
    }
}

void generateDisplay(uint8_t matrix[ROWS][COLS]) {
    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLS; j++)
        {
            matrix[i][j] = 1;
        }
    }
}
void sandTick(uint8_t matrix[ROWS][COLS]){
    matrix[ROWS-1][COLS/2-1] = 0;
    matrix[ROWS-1][COLS/2] = 0;
}
void update(uint8_t display[ROWS][COLS]){
    for (int row = ROWS-2; row >= 0; row--)
    {
        for (int col = 0; col < COLS; col++)
        {

            if (display[row][col])
            {

                if (col>=COLS/2)
                {
                    // check for +1down
                    if (display[row+1][col] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col] = 1;
                        // printDisplayTerminal(display);
                    }


                        // check for +1 down and +1 to the left
                    else if (display[row+1][col-1] == 0 && display[row][col-1] ==0)
                    {
                        display[row][col] = 0;
                        display[row+1][col-1] = 1;
                        // printDisplayTerminal(display);
                    }
                } else {
                    // check for +1down
                    if (display[row+1][col] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col] = 1;
                        // printDisplayTerminal(display);
                    }


                        // check for +1 down and +1 to the right if no neighbour on the right
                    else if (display[row+1][col+1] == 0 && display[row][col+1] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col+1] = 1;
                        // printDisplayTerminal(display);
                    }

                }
            }
        }
    }
}