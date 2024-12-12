#include "SandClockF1rset.h"

void generate_displays(SandClock* clock){
    for (int i = 0; i<COLS; i++){
        for (int j = 0; j<ROWS; j++){
            clock->upper_screen[i][j] = 1;
            clock->bottom_screen[i][j] = 0;
        }
    }
}
void sandTick(uint8_t upper_display[ROWS][COLS], uint8_t bottom_display[ROWS][COLS]){
    if (upper_display[ROWS-1][(int) COLS/2-1] ==1
        && upper_display[ROWS-1][(int) COLS/2] == 1){
        upper_display[ROWS-1][(int) COLS/2-1] = 0;
        upper_display[ROWS-1][(int) COLS/2] = 0;
        bottom_display[0][(int) COLS/2-1] = 1;
        bottom_display[0][(int) COLS/2] = 1;
    }
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
                    if (display[row+1][col] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col] = 1;
                    }
                    else if (display[row+1][col-1] == 0 && display[row][col-1] ==0)
                    {
                        display[row][col] = 0;
                        display[row+1][col-1] = 1;
                    }
                } else {
                    if (display[row+1][col] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col] = 1;
                    }
                    else if (display[row+1][col+1] == 0 && display[row][col+1] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col+1] = 1;
                    }
                }
            }
        }
    }
}

void drawLines(uint8_t matrix[ROWS][COLS], uint8_t temp) {
    int hard = COLS/2 + ROWS;

    for (int y = 0; y<ROWS; y++){
        for (int x = 0; x<COLS ; x++) {
            if (x+y >= hard || COLS-1-x+y >= hard){
                matrix[y][x] = temp;
            }
        }
    }

}
void updateBottom(uint8_t display[ROWS][COLS]){
    for (int row = ROWS-2; row >= 0; row--)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (display[row][col])
            {
                if (col>=COLS/2)
                {
                    if (display[row+1][col] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col] = 1;
                    }
                    else if (display[row+1][col+1] == 0 && display[row][col+1] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col+1] = 1;
                    }
                } else {
                    if (display[row+1][col] == 0)
                    {
                        display[row][col] = 0;
                        display[row+1][col] = 1;
                    }
                    else if (display[row+1][col-1] == 0 && display[row][col-1] ==0)
                    {
                        display[row][col] = 0;
                        display[row+1][col-1] = 1;
                    }
                }
            }
        }
    }
}
//void update(uint8_t upper_display[ROWS][COLS], uint8_t bottom_display[ROWS][COLS]){
//    for (int y = 0; y<ROWS-1; y++){
//        for (int x = 0; x<COLS/2; x++){
//            if (upper_display[y][x] == 1){
//                if (upper_display[y+1][x] == 1) {
//                    if (upper_display[y + 1][x + 1] == 0) {
//                        upper_display[y + 1][x + 1] = 1;
//                        upper_display[y][x] = 0;
//                        upper_display[y + 1][ROWS - x - 1] = 1;
//                        upper_display[y][ROWS - x] = 0;
//                    }
//                } else{
//                    upper_display[y + 1][x] = 1;
//                    upper_display[y][x] = 0;
//                    upper_display[y + 1][ROWS - x] = 1;
//                    upper_display[y][ROWS - x] = 0;
//                }
//            }
//        }
//    }
//}

//void print_matrix(uint8_t matrix[ROWS][COLS]){
//    for (int i = 0; i<ROWS; i++){
//        for (int j = 0; j<COLS; j++){
//            printf("%d", matrix[i][j]);
//        }
//        printf("\n");
//    }
//}

//void reverse(uint8_t matrix[ROWS][COLS]){
//    for (int i = 0; i<ROWS; i++){
//        for (int j = 0; j<COLS; j++){
//            matrix[i][j] = matrix[i][j] == 0 ? 1 : 0;
//        }
//    }
//}

//void exchange(uint8_t matrix1[ROWS][COLS], uint8_t matrix2[ROWS][COLS]){
//    for (int i = 0; i<ROWS; i++){
//        for (int j = 0; j<COLS; j++){
//            uint8_t temp = matrix1[i][j];
//            matrix1[i][j] = matrix2[ROWS -1 -i][j];
//            matrix2[ROWS - 1 - i][j] = temp;
//        }
//    }
//}

void rotate(uint8_t matrix1[ROWS][COLS]){
    for (int i = 0; i<ROWS/2; i++){
        for (int j = 0; j<COLS; j++){
            uint8_t temp = matrix1[i][j];
            matrix1[i][j] = matrix1[ROWS -1-i][j];
            matrix1[ROWS-1 -i][j] = temp;
        }
    }
}

//int main(){
//    SandClock clock = generate_displays();
//    for (int i = 0; i<10; i++){
//        print_matrix(clock.upper_screen);
//        printf("___________________________\n");
//        print_matrix(clock.bottom_screen);
//        printf("___________________________\n");
//        printf("___________________________\n");
//        sandTick(clock.upper_screen, clock.bottom_screen);
//        for (int j = 0; j<10; j++){
//            update(clock.upper_screen);
//            updateBottom(clock.bottom_screen);
//        }
//    }
//    printf("___________________________\n");
//    printf("___________________________\n");
//    printf("___________________________\n");
//    printf("___________________________\n");
//    printf("___________________________\n");
//    printf("___________________________\n");
////    reverse(clock.upper_screen);
////    reverse(clock.bottom_screen);
//    drawLines(clock.upper_screen, 0);
////    exchange(clock.upper_screen, clock.bottom_screen);
//    rotate(clock.upper_screen);
//    rotate(clock.bottom_screen);
//    drawLines(clock.bottom_screen, 1);
//    for (int i = 0; i<12; i++){
//        print_matrix(clock.upper_screen);
//        printf("___________________________\n");
//        print_matrix(clock.bottom_screen);
//        printf("___________________________\n");
//        printf("___________________________\n");
//        sandTick(clock.bottom_screen, clock.upper_screen);
//        for (int j = 0; j<10; j++){
//            update(clock.bottom_screen);
//            updateBottom(clock.upper_screen);
//        }
//    }
//    return 0;
//}
