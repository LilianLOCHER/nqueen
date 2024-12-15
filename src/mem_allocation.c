#include <stdlib.h>

void free_map(int **map, int size)
{
    for (int i = 0; i < size; i++)
        free(map[i]);
    free(map);
    return;
}

int **allocate_mem_map(int size)
{
    int **map;

    if (size <= 0)
        return NULL;
    map = malloc(sizeof(int *) * size);
    if (map == NULL)
        return NULL;
    for (int i = 0; i < size; i++){
        map[i] = malloc(sizeof(int) * size);
        if (map[i] == NULL)
            return NULL;
    }
    return map;
}

int **initialize_map(int **map, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            map[i][j] = 0;
    return map;
}
