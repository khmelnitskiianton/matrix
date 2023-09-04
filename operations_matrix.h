struct SizeMatrix {
    const size_t sizeY;
    const size_t sizeX;
};
double* mtx_address(double *mtx, const size_t y, const size_t x, SizeMatrix *size_mtx);

FILE * file_open (const char *path, const char *status);

void read_matrix(FILE *file_read, double *mtx, SizeMatrix *size_mtx);

void init_matrix(double *mtx, SizeMatrix *size_mtx);

void write_matrix(FILE *file_write, const char name, double *mtx, SizeMatrix *size_mtx);

int multiply_matrix (const double *mtxA, SizeMatrix *size_mtxA, const double *mtxB, SizeMatrix *size_mtxB, double *mtxC);

int arithmetic_progression (const int start_arg, const int step, const int n);

void write_triangle_matrix (FILE *file_write, const int *data, const size_t size);

int find_triangle_matrix (FILE *file_read, const int *data, const size_t size, int *indexes);