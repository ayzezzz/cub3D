#include "lib/cub3D.h"

char **B_map(char **map)
{
    //1111
    //1001
    //1011
    //110

    int yüksek = findyüksek(); //4
    int geniş = findgeniş(); //4

    char **b_map = malloc(sizeof(char *) * yüksek);
    for (int i = 0; i < yüksek; i++)
        b_map[i] = malloc(sizeof(char) * geniş);
    
    for (int i = 0; i < yüksek; i++)
        for (int j = 0; j < geniş; j++)
            b_map[i][j] = "B";

    //BBBBBB
    //BBBBBB
    //BBBBBB
    //BBBBBB
    //BBBBBB
    //BBBBBB
    
    for (int i = 0; i < yüksek; i++)
        for (int j = 0; j < geniş; j++)
        {
            if (map[i][j] != ' ')
                b_map[i + 1][j + 1] = map[i][j];
        }

    //BBBBBB
    //B1111B
    //B1001B
    //B1011B
    //B110BB
    //BBBBBB

    for (int i = 0; i < yüksek; i++)
        for (int j = 0; j < geniş; j++)
        {
            if (b_map[i][j] == '0' && (b_map[i + 1][j] == 'B' || b_map[i - 1][j] == 'B' || b_map[i][j + 1]))
        }
    return (b_map);
}