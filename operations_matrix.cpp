#include "head.h"

FILE * file_w_open (void)
{
    FILE *file_write = NULL;
    if ((file_write = fopen ("matrix_out.txt", "w")) == NULL) //check for opening
    {
        assert(0);
    }
    return file_write;
}

FILE * file_r_open (void)
{
    FILE *file_read = NULL;
    if ((file_read = fopen ("matrix_out.txt", "r")) == NULL) //check for opening
    {
        assert(0);
    }
    return file_read;
}
void read_matrix(double mtx[5][5], size_t sizeY, size_t sizeX)
{
    FILE *file_read = NULL;
    file_read = file_r_open ();
	for (size_t y = 0; y < sizeY; y++)
		fscanf(file_read,"%lg %lg %lg %lg %lg", &mtx[y][0], &mtx[y][1], &mtx[y][2], &mtx[y][3], &mtx[y][4]);
}

void init_matrix(double mtx[5][5], size_t sizeY, size_t sizeX)
{
    for (size_t y = 0; y < sizeY; y++)
    {
        for (size_t x = 0; x < sizeX; x++)
            mtx[y][x] = NAN;
    }
}

void write_matrix(double mtx[5][5], size_t sizeY, size_t sizeX)
{
    FILE *file_write = NULL;
    file_write = file_w_open ();

    for (size_t y = 0; y < sizeY; y++)
    {
        for (size_t x = 0; x < sizeX; x++)
        {
            fprintf(file_write, "a(%d,%d)[%.2lg]    ", x, y, mtx[y][x]);
            fprintf(stdout, "a(%d,%d)[%.2lg]    ", x, y, mtx[y][x]);
        }
        fprintf(file_write, "\n");  
        fprintf(stdout, "\n");
    }
    if (fclose(file_write) != 0)
        printf("ERROR OF CLOSING!");
}
/*
void multiply_matix (double mtxA[5][5], SizeMatrix sizeA double mtxB[][], SizeMatrix sizeB)
{

}
*/