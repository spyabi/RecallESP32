#include "Map.h"

Map::Map(int level, int matrix[6][6], int startx, int starty) {
  this->level = level;
  this->startx = startx;
  this->starty = starty;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      this->map[i][j] = matrix[i][j];
    }
  }
}

bool Map::wall_checker(int x, int y){
  if (map[y][x] == 1){
    return true;
  }
  else{
    return false;
  }
}
bool Map::map_checker(int player_map[6][6]){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (map[i][j] != player_map[i][j]) {
                return false; // If any corresponding elements are different, matrices are not equal
            }
        }
    }
    return true; // All corresponding elements are the same, matrices are equal
}