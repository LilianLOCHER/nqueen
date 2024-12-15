#include <unistd.h>

void print_map(int **map, int size)
{
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            map[i][j] += 48;
            write(1, &map[i][j], 1);
            map[i][j] -= 48;
        }
        write(1, "\n", 1);
    }
    return;
}

int can_place_queen(int **map, int i, int j, int size)
{
    for (int k = 0; k < size; k++){
        if (k != j && map[i][k] == 1)
            return 0;
    }
    for (int k = 0; k < size; k++){
        if (k != i && map[k][j] == 1)
            return 0;
    }
    for (int k = 1; k < size; k++){
        if (i - k >= 0 && j - k >= 0 && map[i - k][j - k] == 1)
            return 0;
        if (i + k < size && j - k >= 0 && map[i + k][j - k] == 1)
            return 0;
        if (i + k < size && j + k < size && map[i + k][j + k] == 1)
            return 0;
        if (i - k >= 0 && j + k < size && map[i - k][j + k] == 1)
            return 0;
    }
    return 1;
}

int nqueen_solving(int **map, int step, int size)
{
    int solutions = 0;

    if (step >= size)
        return 1;
    for (int i = 0; i < size; i++){
        map[step][i] = 1;
        if (can_place_queen(map, step, i, size))
            solutions += nqueen_solving(map, step + 1, size);
        map[step][i] = 0;
    }
    return solutions;
}
