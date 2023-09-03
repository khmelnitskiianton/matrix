CC = g++

SHELL = C:/Windows/System64/cmd.exe

CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

EXECUTABLE = proga.exe

start: main.o operations_matrix.o
	$(CC) main.o operations_matrix.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

operations_matrix.o: operations_matrix.cpp
	$(CC) $(CFLAGS) operations_matrix.cpp

clean:
	rm -r *.o 

docs:
	doxygen doxy_config

run: 
	D:/Study/C/matrix/$(EXECUTABLE)
