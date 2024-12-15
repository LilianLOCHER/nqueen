#include "../include/include.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int size = MAP_SIZE;
    int **map;
    int res = 0;

    map = allocate_mem_map(size);
    if (map == NULL)
        return 84;
    map = initialize_map(map, size);
    res = nqueen_solving(map, 0, size);
    free_map(map, size);
    printf("SIZE : %d, SOLUTIONS : %d", size, res);
    return 0;
}
