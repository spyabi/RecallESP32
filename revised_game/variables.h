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
extern int display[6][6] = {{0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1},
                          {0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0}};
                          

extern int (*round_endings[])[6] = {smiley, sad, animation, display};

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

extern int map1_4_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map1_4(1, map1_4_map, 2, 1);

extern int map1_5_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map1_5(1, map1_5_map, 4, 3);

extern int map1_6_map[6][6] = {{0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map1_6(1, map1_6_map, 4, 0);

extern std::vector<Map> level_1 = {map1_1, map1_2, map1_3, map1_4, map1_5, map1_6};

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

extern Map map2_3(2, map2_3_map, 3, 5);

extern int map2_4_map[6][6] = {{0, 0, 0, 0, 1, 1},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map2_4(2, map2_4_map, 5, 0);

extern int map2_5_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map2_5(2, map2_5_map, 1, 1);

extern int map2_6_map[6][6] = {{0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map2_6(2, map2_6_map, 2, 3);

extern std::vector<Map> level_2 = {map2_1, map2_2, map2_3, map2_4, map2_5, map2_6};

extern int map3_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 1, 1, 1, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0}};

extern Map map3_1(3, map3_1_map, 2, 5);

extern int map3_2_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0}};

extern Map map3_2(3, map3_2_map, 3, 5);

extern int map3_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 1},
                              {0, 0, 0, 0, 1, 1},
                              {0, 0, 0, 0, 1, 0}};

extern Map map3_3(3, map3_3_map, 4, 5);

extern int map3_4_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map3_4(3, map3_4_map, 1, 1);

extern int map3_5_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 1},
                              {0, 0, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map3_5(3, map3_5_map, 5, 3);

extern int map3_6_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map3_6(3, map3_6_map, 4, 1);

extern std::vector<Map> level_3 = {map3_1, map3_2, map3_3, map3_4, map3_5, map3_6};

extern int map4_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0}};

extern Map map4_1(4, map4_1_map, 2, 2);
extern Map map4_1_2(4, map4_1_map, 4, 3);

extern int map4_2_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0}};

extern Map map4_2(4, map4_2_map, 3, 1);
extern Map map4_2_2(4, map4_2_map, 2, 4);

extern int map4_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 1, 1},
                              {0, 0, 1, 1, 0, 1},
                              {0, 0, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0, 1}};

extern Map map4_3(4, map4_3_map, 2, 3);
extern Map map4_3_2(4, map4_3_map, 5, 2);

extern int map4_4_map[6][6] = {{0, 1, 1, 0, 0, 0},
                              {0, 0, 1, 0, 1, 1},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map4_4(4, map4_4_map, 5, 1);
extern Map map4_4_2(4, map4_4_map, 2, 2);

extern int map4_5_map[6][6] = {{0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {0, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map4_5(4, map4_5_map, 2, 0);
extern Map map4_5_2(4, map4_5_map, 1, 3);

extern int map4_6_map[6][6] = {{0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map4_6(4, map4_6_map, 2, 4);
extern Map map4_6_2(4, map4_6_map, 4, 2);

extern std::vector<Map> level_4 = {map4_1, map4_1_2, map4_2, map4_2_2, map4_3, map4_3_2, map4_4, map4_4_2, map4_5, map4_5_2, map4_6, map4_6_2};

extern int map5_1_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0}};

extern Map map5_1(5, map5_1_map, 4, 1);
extern Map map5_1_2(5, map5_1_map, 2, 4);

extern int map5_2_map[6][6] = {{0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 1, 1},
                              {0, 0, 0, 0, 0, 1}};

extern Map map5_2(5, map5_2_map, 2, 0);
extern Map map5_2_2(5, map5_2_map, 3, 4);

extern int map5_3_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {1, 1, 0, 0, 0, 0}};

extern Map map5_3(5, map5_3_map, 4, 1);
extern Map map5_3_2(5, map5_3_map, 2, 4);

extern int map5_4_map[6][6] = {{0, 0, 0, 1, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 1, 1, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0, 0}};

extern Map map5_4(5, map5_4_map, 4, 2);
extern Map map5_4_2(5, map5_4_map, 2, 5);

extern int map5_5_map[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0},
                              {0, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0}};

extern Map map5_5(5, map5_5_map, 2, 3);
extern Map map5_5_2(5, map5_5_map, 3, 5);

extern int map5_6_map[6][6] = {{0, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0},
                              {0, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

extern Map map5_6(5, map5_6_map, 1, 2);
extern Map map5_6_2(5, map5_6_map, 4, 2);

extern std::vector<Map> level_5 = {map5_1, map5_1_2, map5_2, map5_2_2, map5_3, map5_3_2, map5_4, map5_4_2, map5_5, map5_5_2, map5_6, map5_6_2};

std::vector<std::vector<Map>> map_database = {level_1, level_2, level_3, level_4, level_5};





#endif