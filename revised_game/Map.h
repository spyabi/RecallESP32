#ifndef MAP_H
#define MAP_H

//might need #include <Arduino.h>
//class implementation

class Map {       // The class
  public:             // Access specifier
    int level;        // Attribute (int variable)
    int map[6][6];  // Attribute (string variable)
    int startx;
    int starty;

    Map(int level, int matrix[6][6], int startx, int starty);

    bool wall_checker(int x, int y);

    bool map_checker(int player_map[6][6]);

};

#endif