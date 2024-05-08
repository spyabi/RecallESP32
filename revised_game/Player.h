#ifndef PLAYER_H
#define PLAYER_H

//might need #include <Arduino.h>
//class implementation

class Player {       // The class
  public:             // Access specifier
    int level;        // Attribute (int variable)
    int map[6][6];  // Attribute (string variable)
    int x_pos;
    int y_pos;
    bool idle;

    Player(int level, int matrix[6][6], int startx, int starty, bool idle = true);

    void player_start();

    void level_up();

    void move_x(int move);
    void move_y(int move);
    void set_x(int xpos);
    void set_y(int ypos);

    void update_map();

    void reset_map();

    void reset_player();
    

};

#endif