#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H
//NOT IN USE
class AbstractGame {                                     //Create a class

  public:                                           //functions you can call from another program
    //constructor- which is used to create an instance of the class.
    //Eg. timeObj(float inMs=10,bool startNow=true); //startNow defaults to true
 
    virtual void game_over();

    virtual void update_RGB();

    virtual void display_animation(int round_ending[6][6],int R,int G,int B);
    virtual void display_starting_map(Map random_map, unsigned long length,int R,int G,int B);

    virtual void update_display(int map[6][6],int R,int G,int B);
    virtual void update_display(int map[6][6],int R,int G,int B, Player player);

    // Function pointer without parameters
    virtual void check_button_press(int buttonPin, int &lastButtonState, int &buttonState, unsigned long &lastDebounceTime, unsigned long debounceDelay, void (*functionPtr)());
    // Function pointer with parameters
    virtual void check_button_press(int buttonPin, int &lastButtonState, int &buttonState, unsigned long &lastDebounceTime, unsigned long debounceDelay, void (*functionPtr)(Map), Map chosen_map);

    virtual void check_player_move(Map chosen_map);

    virtual void handleUpButtonPress(Map chosen_map);
    virtual void handleDownButtonPress(Map chosen_map);
    virtual void handleLeftButtonPress(Map chosen_map);
    virtual void handleRightButtonPress(Map chosen_map);
    virtual void handleFirstStartButtonPress();
    virtual void handleStartButtonPress();
    virtual void handleResetButtonPress();
          
};

#endif