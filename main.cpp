#include "head.h"
#define ROWS_A 5
#define COLS_A 5
#define ROWS_B 5
#define COLS_B 5 
int main()
{   
    double matrixA[ROWS_A][COLS_A];
    double matrixB[ROWS_B][COLS_B];

    struct SizeMatrix sizeA 
    {
        ROWS_A,
        COLS_A,
    };
    struct SizeMatrix sizeB
    {
        ROWS_B,
        COLS_B,
    };

    
    init_matrix(matrixA, ROWS_A, COLS_A);
    init_matrix(matrixB, ROWS_B, COLS_B);
    
    read_matrix(matrixA, ROWS_A, COLS_A);
    write_matrix(matrixA, ROWS_A, COLS_A);


    
}