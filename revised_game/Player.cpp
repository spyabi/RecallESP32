#include "Player.h"


Player::Player(int level, int matrix[6][6], int startx, int starty, bool idle) {
  this->level = level;
  this->x_pos = startx;
  this->y_pos = starty;
  this->idle = idle;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      this->map[i][j] = matrix[i][j];
    }
  }
}

void Player::player_start(){
  idle = false;
}

void Player::level_up(){
  level += 1;
}

void Player::move_x(int move){
  if (x_pos + move >= 0 && x_pos + move <=5){
    x_pos += move;
  }
}
void Player::move_y(int move){
  if (y_pos + move >= 0 && y_pos + move <=5){
    y_pos += move;
  }
}

void Player::set_x(int xpos){
  x_pos = xpos;
}
void Player::set_y(int ypos){
  y_pos = ypos;
}

void Player::update_map(){
  map[y_pos][x_pos] = 1;
}

void Player::reset_map(){
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      this->map[i][j] = 0;
    }
  }
}

void Player::reset_player(){
  reset_map();
  level = 0;
  idle = true;
}
    
