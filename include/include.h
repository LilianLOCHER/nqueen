#ifndef INCLUDE_H
    #define INCLUDE_H

    #define MAP_SIZE 10

int **allocate_mem_map(int size);
int nqueen_solving(int **map, int step, int size);
void free_map(int **map, int size);
int **initialize_map(int **map, int size);

#endif // INCLUDE_H
