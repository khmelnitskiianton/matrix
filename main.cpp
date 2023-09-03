#include "head.h"

#define ROWS_A 5
#define COLS_A 5
#define ROWS_B 5
#define COLS_B 5 
#define ROWS_C 5
#define COLS_C 5 

#define FIN "matrix_in.txt"
#define FOUT "matrix_out.txt"

int main()
{   
    double matrixA[ROWS_A][COLS_A];
    double matrixB[ROWS_B][COLS_B];
    double matrixC[ROWS_C][COLS_C];

    FILE *file_in = file_open (FIN, "r");
    FILE *file_out = file_open (FOUT, "w");

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
    struct SizeMatrix sizeC
    {
        ROWS_C,
        COLS_C,
    };
    
    init_matrix ((double*) matrixA, &sizeA);
    init_matrix ((double*) matrixB, &sizeB);
    init_matrix ((double*) matrixC, &sizeC);

    read_matrix (file_in, (double*) matrixA, &sizeA);
    read_matrix (file_in, (double*) matrixB, &sizeB);

    write_matrix (file_out, 'A', (double*) matrixA, &sizeA);
    write_matrix (stdout,   'A', (double*) matrixA, &sizeA);  

    write_matrix (file_out, 'B', (double*) matrixB, &sizeB);
    write_matrix (stdout,   'B', (double*) matrixB, &sizeB);    

    if (fclose (file_in))  printf ("ERROR OF CLOSING!\n");
    if (fclose (file_out)) printf ("ERROR OF CLOSING!\n");
    
}