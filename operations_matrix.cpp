#include "head.h"

#define MTX_ADDRESS (double *)((size_t) mtx + (y * (size_mtx -> sizeY) + x) * sizeof (double))

FILE * file_open (const char *path, const char *status)
{
    FILE *file = NULL;
    if ((file = fopen (path, status)) == NULL) //check for opening
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
		    if (fscanf (file_read, "%lf", MTX_ADDRESS) == 0) assert(0);
        }
    }
}

void init_matrix (double *mtx, SizeMatrix *size_mtx)
{
    for (size_t y = 0; y < size_mtx -> sizeY; y++)
    {
        for (size_t x = 0; x < size_mtx -> sizeX; x++)
            *MTX_ADDRESS = NAN;
    }
}

void write_matrix (FILE *file_write, const char name, const double *mtx, SizeMatrix *size_mtx)
{
    for (size_t y = 0; y < size_mtx -> sizeY; y++)
    {
        for (size_t x = 0; x < size_mtx -> sizeX; x++)
        {
            fprintf (file_write, "%c(%d,%d)[%9.2lg]\t", name, y, x, *MTX_ADDRESS);
        }
        fprintf (file_write, "\n");  
    }
    fprintf (file_write, "\n");
}
int multiply_matrix (double *mtxA, SizeMatrix *size_mtxA, double *mtxB, SizeMatrix *size_mtxB, double *mtxC)
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
                summa_c += (*(double *)((size_t) mtxA + (i * (size_mtxA -> sizeY) + j) * sizeof (double))) * (*(double *)((size_t) mtxB + (j * (size_mtxB -> sizeY) + i) * sizeof (double)));
            }
            *(double *)((size_t) mtxC + (i * (size_mtxA -> sizeY) + j) * sizeof (double)) = summa_c;
        }
    }

    return 1;
}
