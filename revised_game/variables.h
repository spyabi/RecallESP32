#ifndef VARIABLES_H
#define VARIABLES_H

#include <vector>

extern int map1[6][6] = {{0, 0, 1, 1, 0, 0},
                        {0, 1, 1, 1, 0, 0},
                        {1, 0, 1, 1, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1}};
extern int map2[6][6] = {{0, 0, 1, 1, 0, 0},
                        {0, 1, 0, 0, 1, 0},
                        {0, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1}};
extern int map3[6][6] = {{0, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 0},
                        {0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0},
                        {0, 1, 1, 1, 1, 1}};

extern int map4[6][6] = {{0, 0, 1, 1, 0, 0},
                        {0, 1, 0, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0,1, 0, 0},
                        {0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0}};

extern int map5[6][6] = {{1, 1, 1, 1, 1, 0},
                        {1, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 1, 0},
                        {1, 1, 1, 1, 0, 0}};

extern int (*round_start[])[6] = {map1, map2, map3, map4, map5};

extern int smiley[6][6] = {{0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 0},
                          {0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 1},
                          {0, 1, 1, 1, 1, 0},
                          {0, 0, 0, 0, 0, 0}};
extern int sad[6][6] = {{0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 0},
                          {0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 0},
                          {1, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0}};
extern int animation[6][6] = {{1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1}};

extern int (*round_endings[])[6] = {smiley, sad, animation};

extern int map1_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {1, 1, 0, 0, 0, 0}};

extern Map map1_1(1, map1_1_map, 0, 5);

extern int map1_2_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 1, 1, 1, 0, 0},
                              {0, 1, 0, 0, 0, 0}};

extern Map map1_2(1, map1_2_map, 1, 5);

extern int map1_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 0, 1, 1, 0, 0}};

extern Map map1_3(1, map1_3_map, 2, 5);

extern std::vector<Map> level_1 = {map1_1, map1_2, map1_3};

extern int map2_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0}};

extern Map map2_1(2, map2_1_map, 1, 5);

extern int map2_2_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0, 0},
                              {1, 1, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0}};

extern Map map2_2(2, map2_2_map, 2, 5);

extern int map2_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0, 1},
                              {0, 0, 0, 1, 1, 1},
                              {0, 0, 0, 1, 0, 0}};

extern Map map2_3(2, map2_3_map,3, 5);

extern std::vector<Map> level_2 = {map2_1, map2_2, map2_3};

extern int map3_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 1, 1, 1, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0}};

extern Map map3_1(2, map3_1_map, 2, 5);

extern int map3_2_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0}};

extern Map map3_2(2, map3_2_map, 3, 5);

extern int map3_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 1},
                              {0, 0, 0, 0, 1, 1},
                              {0, 0, 0, 0, 1, 0}};

extern Map map3_3(2, map3_3_map, 4, 5);

extern std::vector<Map> level_3 = {map3_1, map3_2, map3_3};

extern int map4_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0}};

extern Map map4_1(2, map4_1_map, 3, 5);

extern int map4_2_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0}};

extern Map map4_2(2, map4_2_map, 4, 5);

extern int map4_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 1},
                              {0, 0, 1, 1, 0, 1},
                              {0, 0, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0, 1}};

extern Map map4_3(2, map4_3_map, 5, 5);

extern std::vector<Map> level_4 = {map4_1, map4_2, map4_3};

extern int map5_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0}};

extern Map map5_1(2, map5_1_map, 4, 5);

extern int map5_2_map[6][6] = {{0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 1, 1},
                              {0, 0, 0, 0, 0, 1}};

extern Map map5_2(2, map5_2_map, 5, 5);

extern int map5_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {1, 1, 0, 0, 0, 0}};

extern Map map5_3(2, map5_3_map, 0, 5);

extern std::vector<Map> level_5 = {map5_1, map5_2, map5_3};

std::vector<std::vector<Map>> map_database = {level_1, level_2, level_3, level_4, level_5};





#endif