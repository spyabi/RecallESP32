#include <FastLED.h>
#include "Map.h"
#include "Player.h"
#include "variables.h"
#include <vector>

//declare pins
#define startbutton 12
#define resetbutton 13
#define upbutton 32
#define rightbutton 26
#define downbutton 25
#define leftbutton 33

#define led1 19
#define led2 18
#define led3 5
#define led4 17
#define led5 16
#define led6 4
/* can use const int to declare pin numbers but
In embedded programming, for example, #define GLOBAL_CONSTANT 42 is preferred to const int GLOBAL_CONSTANT = 42;
for the following reasons:
it does not need place in RAM (which is usually very limited in microcontrollers, and µC applications usually need a large number of global constants)
const needs not only a storage place in the flash, but the compiler generates extra code at the start of the program to copy it.
pros of const int = type declaration
*/

const int NUM_LED = 6;
//testing branch

CRGB strip_1[NUM_LED];
CRGB strip_2[NUM_LED];
CRGB strip_3[NUM_LED];
CRGB strip_4[NUM_LED];
CRGB strip_5[NUM_LED];
CRGB strip_6[NUM_LED];
CRGB* ledstrips[] = {strip_1, strip_2, strip_3, strip_4, strip_5, strip_6};
int start[6][6] = {{0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}};
Player player(0, start, 0, 0);
Map smiley_face(0, round_endings[0], 0, 0);
Map sad_face(0, round_endings[1], 0, 0);
Map animation_map(0, round_endings[2], 0, 0);
int lastUpButtonState = LOW;
int upButtonState = LOW;
unsigned long lastUpDebounceTime = 0;

int lastDownButtonState = LOW;
int downButtonState = LOW;
unsigned long lastDownDebounceTime = 0;

int lastLeftButtonState = LOW;
int leftButtonState = LOW;
unsigned long lastLeftDebounceTime = 0;

int lastRightButtonState = LOW;
int rightButtonState = LOW;
unsigned long lastRightDebounceTime = 0;
unsigned long debounceDelay = 50;

int lastStartButtonState = LOW;
int startButtonState = LOW;
unsigned long lastStartDebounceTime = 0;

int lastResetButtonState = LOW;
int resetButtonState = LOW;
unsigned long lastResetDebounceTime = 0;

int game_level = 1;

int R = 0;
int G = 0;
int B = 0;


void setup() {
  pinMode(startbutton, INPUT_PULLDOWN);
  pinMode(resetbutton, INPUT_PULLDOWN);
  pinMode(upbutton, INPUT_PULLDOWN);
  pinMode(rightbutton, INPUT_PULLDOWN);
  pinMode(downbutton, INPUT_PULLDOWN);
  pinMode(leftbutton, INPUT_PULLDOWN);
  pinMode(led1, OUTPUT); // Set the LED pin as an output
  pinMode(led2, OUTPUT); // Set the LED pin as an output
  pinMode(led3, OUTPUT); // Set the LED pin as an output
  pinMode(led4, OUTPUT); // Set the LED pin as an output
  pinMode(led5, OUTPUT); // Set the LED pin as an output
  pinMode(led6, OUTPUT); // Set the LED pin as an output
  FastLED.addLeds<WS2812B, led1, GRB>(strip_1, NUM_LED);
  FastLED.addLeds<WS2812B, led2, GRB>(strip_2, NUM_LED);
  FastLED.addLeds<WS2812B, led3, GRB>(strip_3, NUM_LED);
  FastLED.addLeds<WS2812B, led4, GRB>(strip_4, NUM_LED);
  FastLED.addLeds<WS2812B, led5, GRB>(strip_5, NUM_LED);
  FastLED.addLeds<WS2812B, led6, GRB>(strip_6, NUM_LED);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  update_RGB();
  while (player.idle){
    FastLED.clear();
    FastLED.show();
    check_button_press(startbutton, lastStartButtonState, startButtonState, lastStartDebounceTime, debounceDelay, handleFirstStartButtonPress);
  }
  FastLED.clear();
  while (player.level != game_level && !player.idle){
    update_display(round_start[game_level-1], R, G, B);
    check_button_press(startbutton, lastStartButtonState, startButtonState, lastStartDebounceTime, debounceDelay, handleStartButtonPress);
    check_button_press(resetbutton, lastResetButtonState, resetButtonState, lastResetDebounceTime, debounceDelay, handleResetButtonPress);
  }
  //GAME PLAY
  while (player.level == game_level){
    Serial.println("IM LOOPING HERE");
    Map chosen_map = map_database[game_level-1][random((map_database[game_level-1]).size())];
    player.set_x(chosen_map.startx);
    player.set_y(chosen_map.starty);
    player.update_map();
    display_starting_map(chosen_map, 5000, R, G, B);
    //while game not end
    while (!chosen_map.map_checker(player.map) && player.level == game_level){
      player.update_map();
      update_display(player.map, R, G, B, player);
      check_player_move(chosen_map);

      if (chosen_map.map_checker(player.map)){
        //smiley face
        display_starting_map(smiley_face, 2000, 0, 255, 0);
        game_level += 1;
        player.reset_map();
      }
    }
  }
  //AFTER GAME PLAY LEVEL UP GAME LEVEL BY 1
  // IF GAME PLAY == 6
  //ANIMATION AND RESET AFTER ANIMATION
  if (game_level == 6){
    display_animation(round_endings[2], 100, 100, 100);
    FastLED.clear();
    game_level = 1;
    player.reset_player();
  }
}


void update_display(int map[6][6],int R,int G,int B){
    for (int i = 0; i < NUM_LED; i++) {
      for (int j = 0; j < NUM_LED; j++) {
    // Check if the current element of the array is equal to 1
        if (map[i][j] == 1) {
          //Serial.println(i);
          //Serial.println(j);
          ledstrips[i][j] = CRGB(R, G, B);  // Set to red (RGB color: 255, 0, 0)
        } else {
          // Print a message indicating that the number is not equal to 1
          ledstrips[i][j] = CRGB(0, 0, 0);  // Set to nothing
        }
      }
  }
  FastLED.show();
}

void update_display(int map[6][6],int R,int G,int B, Player player){
    for (int i = 0; i < NUM_LED; i++) {
      for (int j = 0; j < NUM_LED; j++) {
    // Check if the current element of the array is equal to 1
        if (map[i][j] == 1) {
          //Serial.println(i);
          //Serial.println(j);
          ledstrips[i][j] = CRGB(R, G, B);  // Set to red (RGB color: 255, 0, 0)
        } else {
          // Print a message indicating that the number is not equal to 1
          ledstrips[i][j] = CRGB(0, 0, 0);  // Set to nothing
        }
      }
  }
  ledstrips[player.y_pos][player.x_pos] = CRGB(100, 100, 100);
  FastLED.show();
}

// Function pointer without parameters
void check_button_press(int buttonPin, int &lastButtonState, int &buttonState, unsigned long &lastDebounceTime, unsigned long debounceDelay, void (*functionPtr)()) {
  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    // Reset the debounce timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Only register the button press if the button state has been stable for the debounce delay
    if (reading != buttonState) {
      buttonState = reading;

      // Register button press
      if (buttonState == HIGH) {
        // Call the function associated with this button press
        (*functionPtr)();
      }
    }
  }
  lastButtonState = reading; // Update the last button state for all buttons
}

// Function pointer with parameters
void check_button_press(int buttonPin, int &lastButtonState, int &buttonState, unsigned long &lastDebounceTime, unsigned long debounceDelay, void (*functionPtr)(Map), Map chosen_map) {
  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    // Reset the debounce timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Only register the button press if the button state has been stable for the debounce delay
    if (reading != buttonState) {
      buttonState = reading;

      // Register button press
      if (buttonState == HIGH) {
        // Call the function associated with this button press, passing the buttonPin parameter
        (*functionPtr)(chosen_map);
      }
    }
  }
  lastButtonState = reading; // Update the last button state for all buttons
}

void check_player_move(Map chosen_map){
  check_button_press(upbutton, lastUpButtonState, upButtonState, lastUpDebounceTime, debounceDelay, handleUpButtonPress, chosen_map);
  check_button_press(downbutton, lastDownButtonState, downButtonState, lastDownDebounceTime, debounceDelay, handleDownButtonPress, chosen_map);
  check_button_press(leftbutton, lastLeftButtonState, leftButtonState, lastLeftDebounceTime, debounceDelay, handleLeftButtonPress, chosen_map);
  check_button_press(rightbutton, lastRightButtonState, rightButtonState, lastRightDebounceTime, debounceDelay, handleRightButtonPress, chosen_map);
  check_button_press(resetbutton, lastResetButtonState, resetButtonState, lastResetDebounceTime, debounceDelay, handleResetButtonPress);
}

void handleUpButtonPress(Map chosen_map) {
  // Your code to handle the up button press goes here
  player.move_y(-1);
  if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
    game_over();
  }
}

void handleDownButtonPress(Map chosen_map) {
  // Your code to handle the down button press goes here
  player.move_y(1);
  if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
    game_over();
  }
}

void handleLeftButtonPress(Map chosen_map) {
  // Your code to handle the left button press goes here
  player.move_x(-1);
  if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
    game_over();
  }
}

void handleRightButtonPress(Map chosen_map) {
  // Your code to handle the right button press goes here
  player.move_x(1);
  if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
    game_over();
  }
}

void handleFirstStartButtonPress() {
  // Your code to handle the right button press goes here
  player.player_start();
}
void handleStartButtonPress() {
  // Your code to handle the right button press goes here
  player.level_up();
  FastLED.clear();
  FastLED.show();
}

void handleResetButtonPress() {
  // Your code to handle the right button press goes here
  game_over();
}

void display_starting_map(Map random_map, unsigned long length,int R,int G,int B){
  unsigned long duration = length;

  unsigned long currentTime = millis();
  unsigned long startTime = currentTime;
  update_display(random_map.map, R, G, B);
  // Perform the task once here
  Serial.println("Task started");

  // Check if the duration has elapsed
  while (currentTime - startTime < duration) {
    currentTime = millis();
    check_button_press(resetbutton, lastResetButtonState, resetButtonState, lastResetDebounceTime, debounceDelay, handleResetButtonPress);
    //Serial.println("Keep performing the task");
    //Serial.println(currentTime - startTime);
  }
  FastLED.clear();
  FastLED.show();
}

void display_animation(int round_ending[6][6],int R,int G,int B){
  FastLED.clear();
  unsigned long duration = 200;
  unsigned long currentTime = millis();
  unsigned long startTime = currentTime;
    for (int i = 0; i < NUM_LED; i++) {
      startTime = currentTime;
      while (currentTime - startTime < duration){
        currentTime = millis();
        for (int j = 0; j < NUM_LED; j++) {
      // Check if the current element of the array is equal to 1
          if (round_ending[i][j] == 1) {
            //Serial.println(i);
            //Serial.println(j);
            ledstrips[j][i] = CRGB(R, G, B);  // Set to red (RGB color: 255, 0, 0)
          } else {
            // Print a message indicating that the number is not equal to 1
            ledstrips[i][j] = CRGB(0, 0, 0);  // Set to nothing
            }
        }
        FastLED.show(); 
    }
  }
}

void update_RGB(){
  if (game_level == 1){
    R = 255;
    G = 255;
    B = 0;
  }
  else if (game_level == 2){
    R = 255;
    G = 100;
    B = 0;
  }
  else if (game_level == 3){
    R = 255;
    G = 0;
    B = 255;
  }
  else if (game_level == 4){
    R = 0;
    G = 255;
    B = 255;
  }
  else if (game_level == 5){
    R = 0;
    G = 0;
    B = 255;
  }
}

void game_over(){
  game_level = 1;
  player.reset_player();
  display_starting_map(sad_face, 3000, 255, 0, 0);
}