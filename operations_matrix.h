struct SizeMatrix {
    const size_t sizeY;
    const size_t sizeX;
};

FILE * file_open (const char *path, const char *status);

void read_matrix(FILE *file_read, double *mtx, SizeMatrix *size_mtx);

void init_matrix(double *mtx, SizeMatrix *size_mtx);

void write_matrix(FILE *file_write, const char name, double *mtx, SizeMatrix *size_mtx);

int multiply_matrix (double *mtxA, SizeMatrix *size_mtxA, double *mtxB, SizeMatrix *size_mtxB, double *mtxC);
