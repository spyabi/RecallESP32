#include "revisedrecall.h"

// NOT IN USE
/*
RevisedRecall::RevisedRecall(int game_level, Map map) {
  this->game_level = game_level;
  this->map = map;
}
    RevisedRecall::void game_over(){
      game_level = 1;
      player.reset_player();
      display_starting_map(sad_face, 3000, 255, 0, 0);
    }

    RevisedRecall::void update_RGB(){
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

    RevisedRecall::void display_animation(int round_ending[6][6],int R,int G,int B){
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

    RevisedRecall::void display_starting_map(Map random_map, unsigned long length,int R,int G,int B){
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

    RevisedRecall::void update_display(int map[6][6],int R,int G,int B){
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

    RevisedRecall::void update_display(int map[6][6],int R,int G,int B, Player player){
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
    RevisedRecall::void check_button_press(int buttonPin, int &lastButtonState, int &buttonState, unsigned long &lastDebounceTime, unsigned long debounceDelay, void (*functionPtr)()) {
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
    RevisedRecall::void check_button_press(int buttonPin, int &lastButtonState, int &buttonState, unsigned long &lastDebounceTime, unsigned long debounceDelay, void (*functionPtr)(Map), Map chosen_map) {
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

    RevisedRecall::void check_player_move(Map chosen_map){
      check_button_press(upbutton, lastUpButtonState, upButtonState, lastUpDebounceTime, debounceDelay, handleUpButtonPress, chosen_map);
      check_button_press(downbutton, lastDownButtonState, downButtonState, lastDownDebounceTime, debounceDelay, handleDownButtonPress, chosen_map);
      check_button_press(leftbutton, lastLeftButtonState, leftButtonState, lastLeftDebounceTime, debounceDelay, handleLeftButtonPress, chosen_map);
      check_button_press(rightbutton, lastRightButtonState, rightButtonState, lastRightDebounceTime, debounceDelay, handleRightButtonPress, chosen_map);
      check_button_press(resetbutton, lastResetButtonState, resetButtonState, lastResetDebounceTime, debounceDelay, handleResetButtonPress);
    }

    RevisedRecall::void handleUpButtonPress(Map chosen_map) {
      // Your code to handle the up button press goes here
      player.move_y(-1);
      if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
        game_over();
      }
    }

    RevisedRecall::void handleDownButtonPress(Map chosen_map) {
      // Your code to handle the down button press goes here
      player.move_y(1);
      if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
        game_over();
      }
    }

    RevisedRecall::void handleLeftButtonPress(Map chosen_map) {
      // Your code to handle the left button press goes here
      player.move_x(-1);
      if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
        game_over();
      }
    }

    RevisedRecall::void handleRightButtonPress(Map chosen_map) {
      // Your code to handle the right button press goes here
      player.move_x(1);
      if (!chosen_map.wall_checker(player.x_pos, player.y_pos)){
        game_over();
      }
    }

    RevisedRecall::void handleFirstStartButtonPress() {
      // Your code to handle the right button press goes here
      player.player_start();
    }
    RevisedRecall::void handleStartButtonPress() {
      // Your code to handle the right button press goes here
      player.level_up();
      FastLED.clear();
      FastLED.show();
    }

    RevisedRecall::void handleResetButtonPress() {
      // Your code to handle the right button press goes here
      game_over();
    }

    */