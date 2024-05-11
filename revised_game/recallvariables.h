#ifndef VARIABLES_H
#define VARIABLES_H

#include <vector>

extern int map1[6][6] = {{0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1}};

extern Map map1(1, map1_1_map, 0, 5);

extern int map2[6][6] = {{1, 0, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0}};

extern Map map2(1, map1_1_map, 0, 5);

extern int map3[6][6] = {{0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 0, 0}};

extern Map map3(1, map1_1_map, 0, 5);

extern std::vector<Map> recall_maps = {map1, map2, map3};

#endif