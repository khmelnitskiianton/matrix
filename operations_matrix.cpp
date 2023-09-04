#include "head.h"

double* mtx_address(double *mtx, const size_t y, const size_t x, SizeMatrix *size_mtx)
{
    return  (double *)((size_t) mtx + (y * (size_mtx -> sizeY) + x) * sizeof (double));
}

FILE * file_open (const char *path, const char *status)
{
    FILE *file = NULL;
    if ((file = fopen (path, status)) == NULL) 
    {
        assert(0);
    }
    return file;
}

void read_matrix (FILE *file_read, double *mtx, SizeMatrix *size_mtx)
{
	for (size_t y = 0; y < size_mtx -> sizeY; y++)
    {
        for (size_t x = 0; x < size_mtx -> sizeX; x++)
        {
		    if (fscanf (file_read, "%lf", (mtx_address(mtx, y, x, size_mtx))) == 0) assert(0);
        }
    }
}

void init_matrix (double *mtx, SizeMatrix *size_mtx)
{
    for (size_t y = 0; y < size_mtx -> sizeY; y++)
    {
        for (size_t x = 0; x < size_mtx -> sizeX; x++)
            *(mtx_address(mtx, y, x, size_mtx)) = NAN;
    }
}

void write_matrix (FILE *file_write, const char name, double *mtx, SizeMatrix *size_mtx)
{
    for (size_t y = 0; y < size_mtx -> sizeY; y++)
    {
        for (size_t x = 0; x < size_mtx -> sizeX; x++)
        {
            fprintf (file_write, "%c(%d,%d)[%10.2lf]\t", name, y, x, *(mtx_address(mtx, y, x, size_mtx)));
        }
        fprintf (file_write, "\n");  
    }
    fprintf (file_write, "\n");
}

int multiply_matrix (const double *mtxA, SizeMatrix *size_mtxA, const double *mtxB, SizeMatrix *size_mtxB, double *mtxC)
{
    if ((size_mtxA -> sizeX) != (size_mtxB -> sizeY))
    {
        printf ("I CANT MULTIPLY THIS MATRIXES. COLUMNS A MUST BE EQUAL TO ROWS B !!!");
        return 0;
    }

    double summa_c = NAN;
    size_t n =  size_mtxB -> sizeY;

    for (size_t i = 0; i < (size_mtxA -> sizeY); i++)
    {
        for (size_t j = 0; j < (size_mtxB -> sizeX); j++)
        {
            summa_c = 0;
            for (size_t k = 0; k < n; k++)
            {
                summa_c += (*(double *)((size_t) mtxA + (i * (size_mtxA -> sizeY) + k) * sizeof (double))) * (*(double *)((size_t) mtxB + (k * (size_mtxB -> sizeY) + j) * sizeof (double)));
            }
            *(double *)((size_t) mtxC + (i * (size_mtxA -> sizeY) + j) * sizeof (double)) = summa_c;
        }
        summa_c = 0;
    }

    return 1;
}

int arithmetic_progression (const int start_arg, const int step, const int n)
{
    return ((2 * start_arg + step * (n-1)) * n) / 2;
}

void write_triangle_matrix (FILE *file_write, const int *data, const size_t size)
{
    for (size_t y = 0; y < size; y++)
    {    
        for (size_t x = 0; x < y + 1; x++)
        {
            fprintf(file_write, "%d\t", *(data + arithmetic_progression(1, 1, y) + x));
        }
        fprintf(file_write, "\n");
    }
}

int find_triangle_matrix (FILE *file_read, const int *data, const size_t size, int *indexes)
{

    for (size_t i = 0; i < 2; i++)
        if (fscanf (file_read, "%d", &indexes[i]) == 0) assert(0);
    
    if ((indexes[0] < indexes[1]) || (indexes[0] >= size) || (indexes[1] >= size)) 
    {
        printf("ERROR FIRST-ROWS MUST BE BIGGER THAN SECOND-COLUMNS AND INDEX CANT BE BIGGER THEN SIZE\n");
        find_triangle_matrix (file_read, data, size, indexes);
        return 0;
    }
    printf("%d", *(data + arithmetic_progression(1, 1, indexes[0]) + indexes[1]));
    return 0;
}
